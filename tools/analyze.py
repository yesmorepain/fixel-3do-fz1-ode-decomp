"""Static analysis of the piode2 RP2040 application image.

Usage: python3 -I analyze.py <image.ode> <outdir>
"""
import sys, os, re, struct, json, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from thumb import decode
import rp2040regs

IMG, OUT = sys.argv[1], sys.argv[2]
raw = open(IMG, "rb").read()
FLASH = 0x10010000
FLASH_END = FLASH + len(raw)


# ---------------------------------------------------------------- memory model
class Seg:
    def __init__(s, name, vma, data, lma):
        s.name, s.vma, s.data, s.lma = name, vma, data, lma
        s.end = vma + len(data)


def w32(a):
    for s in SEGS:
        if s.vma <= a and a + 4 <= s.end:
            return struct.unpack_from("<I", s.data, a - s.vma)[0]
    return None


def seg_of(a):
    for s in SEGS:
        if s.vma <= a < s.end:
            return s
    return None


def rd(a, n):
    s = seg_of(a)
    if not s or a + n > s.end:
        return None
    return s.data[a - s.vma:a - s.vma + n]


SEGS = [Seg("flash", FLASH, raw, FLASH)]
# crt0 data_cpy_table (address from binary_info mapping / crt0 adr)
ram_copies = []
t = 0x10010238
while w32(t):
    src, dst, end = w32(t), w32(t + 4), w32(t + 8)
    if end > dst:
        ram_copies.append((src, dst, end))
    t += 12
for src, dst, end in ram_copies:
    SEGS.append(Seg("ram_data", dst, raw[src - FLASH:src - FLASH + end - dst], src))

# Code ranges: flash .text (up to first big rodata block) and the RAM function area
# .text end determined after discovery; initial bound = start of string pool
TEXT_LIMIT = 0x1001F800


def is_code_addr(a):
    if FLASH + 0x100 <= a < TEXT_LIMIT:
        return True
    for s in SEGS[1:]:
        if s.vma <= a < s.end:
            return True
    return False


# ---------------------------------------------------------------- strings
strings = {}


def scan_strings(seg, lo, hi):
    data = seg.data
    for m in re.finditer(rb"[\x09\x0a\x0d\x20-\x7e]{3,}\x00", data[lo - seg.vma:hi - seg.vma]):
        a = lo + m.start()
        strings[a] = m.group()[:-1].decode("latin1")


scan_strings(SEGS[0], 0x1001F000, 0x10032EF0)
for s in SEGS[1:]:
    scan_strings(s, s.vma, s.end)


def str_at(a):
    if a in strings:
        return strings[a]
    # interior pointer into a string
    b = rd(a, 1)
    if b is None:
        return None
    s = seg_of(a)
    o = a - s.vma
    e = s.data.find(b"\0", o)
    if e < 0 or e - o < 3 or e - o > 200:
        return None
    t = s.data[o:e]
    if all(32 <= c < 127 or c in (9, 10, 13) for c in t) and (0x1001F000 <= a < 0x10033000 or s.name != "flash"):
        return t.decode("latin1")
    return None


# ---------------------------------------------------------------- discovery
insns = {}            # addr -> Insn
data_marks = set()    # literal pool / table byte addresses
func_entries = {}     # addr -> source tag
xrefs_call = collections.defaultdict(set)   # target -> {caller insn addr}
switch_tables = {}    # bl insn addr -> (helper, base, entries)

vt = 0x10010100
for i in range(48):
    v = w32(vt + 4 * i)
    if v and is_code_addr(v & ~1):
        func_entries.setdefault(v & ~1, f"vector[{i}]")
for a, tag in [(0x100101F6, "reset"), (0x1001958C, "crt0:runtime_init"),
               (0x10010424, "crt0:main"), (0x10019548, "crt0:exit"),
               (0x10010230, "crt0:data_cpy"), (0x1001026A, "crt0:get_ipsr")]:
    func_entries[a] = tag


def decode_at(a):
    s = seg_of(a)
    if not s:
        return None
    return decode(s.data, a - s.vma, a)


CASE_HELPERS = {}   # addr -> kind ('uqi','sqi','uhi','shi')


def classify_case_helper(a):
    """Detect libgcc __gnu_thumb1_case_* by instruction pattern."""
    seq = []
    p = a
    for _ in range(12):
        i = decode_at(p)
        if not i:
            break
        seq.append(i.text())
        p += i.size
        if i.kind in ("ret", "ijump"):
            break
    j = " | ".join(seq)
    if "mov     r1, lr" in j or "mov     r1, lr" in j:
        if "ldrb    r1, [r1, r0]" in j:
            return "uqi"
        if "ldrsb   r1, [r1, r0]" in j:
            return "sqi"
        if "ldrh    r1, [r1, r0]" in j:
            return "uhi"
        if "ldrsh   r1, [r1, r0]" in j:
            return "shi"
    return None


def last_cmp_bound(fn_insns, bl_addr):
    """Find the 'cmp rX,#N' + 'bhi' guarding a switch: return N+1 entries."""
    prev = [i for i in fn_insns if i.addr < bl_addr][-6:]
    for i in reversed(prev):
        m = re.match(r"cmp\s+r\d+, #(\d+)", i.text())
        if m:
            return int(m.group(1)) + 1
    return None


def recover_addr_table(a):
    """GCC armv6-m switch: cmp rI,#N ; b{hi|ls} ; lsls rI,rI,#2 ; ldr rT,=TABLE ;
    ldr rT,[rT,rI] ; mov pc,rT.  Returns (table_addr, [targets])."""
    prev = []
    p = a - 2
    while len(prev) < 10 and p >= a - 40:
        i = decode_at(p)
        prev.append(i)
        p -= 2
    # prev[0]=a-2 ...
    if not (prev[0] and re.match(r"ldr\s+r\d+, \[r\d+, r\d+\]", prev[0].text())):
        return None
    if not (prev[1] and prev[1].mnem == "ldr" and prev[1].lit_addr is not None):
        return None
    tbl = w32(prev[1].lit_addr)
    n = None
    for i in prev[2:]:
        if i is None:
            continue
        m = re.match(r"cmp\s+r\d+, #(\d+)", i.text())
        if m:
            n = int(m.group(1)) + 1
            break
    if n is None or tbl is None:
        return None
    tg = []
    for k in range(n):
        v = w32(tbl + 4 * k)
        if v is None or not is_code_addr(v & ~1):
            return None
        tg.append(v & ~1)
    return tbl, tg


def explore(entry):
    """Recursive descent within one function. Returns list of insn addrs."""
    work, seen = [entry], set()
    body = []
    while work:
        a = work.pop()
        while a not in seen and is_code_addr(a) and a not in data_marks:
            i = decode_at(a)
            if i is None:
                break
            seen.add(a)
            insns[a] = i
            body.append(i)
            if i.lit_addr is not None and i.mnem == "ldr":
                for k in range(4):
                    data_marks.add(i.lit_addr + k)
                v = w32(i.lit_addr)
                if v is not None and v & 1 and is_code_addr(v & ~1):
                    func_entries.setdefault(v & ~1, "fnptr")
            if i.kind == "call":
                xrefs_call[i.target].add(a)
                if is_code_addr(i.target):
                    func_entries.setdefault(i.target, "bl")
                    kind = CASE_HELPERS.get(i.target)
                    if kind is None and i.target not in CASE_HELPERS:
                        kind = classify_case_helper(i.target)
                        CASE_HELPERS[i.target] = kind
                    if kind:
                        n = last_cmp_bound(sorted(body, key=lambda x: x.addr), a) or 1
                        base = a + 4
                        es = 1 if kind in ("uqi", "sqi") else 2
                        tgts = []
                        for k in range(n):
                            b = rd(base + k * es, es)
                            if b is None:
                                break
                            v = int.from_bytes(b, "little", signed=kind in ("sqi", "shi"))
                            tgts.append(base + v * 2)
                        for k in range(n * es + (n * es) % 2):
                            data_marks.add(base + k)
                        switch_tables[a] = (kind, base, tgts)
                        work.extend(tgts)
                        break  # helper never returns to base
            if i.kind == "ijump" and i.text().startswith("mov     pc"):
                jt = recover_addr_table(a)
                if jt:
                    tbl, tgts = jt
                    switch_tables[a] = ("addr", tbl, tgts)
                    for k in range(len(tgts) * 4):
                        data_marks.add(tbl + k)
                    work.extend(sorted(set(tgts)))
                break
            if i.kind == "cjump":
                work.append(i.target)
            elif i.kind == "jump":
                if i.target in func_entries and i.target != entry:
                    break       # tail call
                a = i.target
                continue
            if i.kind in ("ret", "ijump"):
                break
            a += i.size
    return sorted(seen)


functions = {}
done = set()


def run_discovery():
    changed = True
    while changed:
        changed = False
        for e in sorted(func_entries):
            if e in done:
                continue
            done.add(e)
            functions[e] = explore(e)
            changed = True


run_discovery()

# prologue sweep for code not reached (callbacks stored in RAM structs, etc.)
for rng_lo, rng_hi in [(FLASH + 0x100, TEXT_LIMIT)] + [(s.vma, s.end) for s in SEGS[1:]]:
    a = rng_lo
    while a < rng_hi:
        if a in insns or a in data_marks:
            a += 2
            continue
        b = rd(a, 2)
        if b and b[1] == 0xB5:   # push {..., lr}
            func_entries[a] = "prologue"
            run_discovery()
        a += 2

# drop entries that turned out to lie inside data
for e in list(functions):
    if e in data_marks:
        del functions[e]

# function bounds: entry .. max insn
func_bounds = {}
ents = sorted(functions)
for e in ents:
    body = functions[e]
    func_bounds[e] = (e, max(body) + insns[max(body)].size if body else e + 2)

text_end = max(b[1] for e, b in func_bounds.items() if e < 0x20000000)

# ---------------------------------------------------------------- constant propagation
# Per function, linear over sorted insns; reset state at branch targets & after calls.
branch_targets = set()
for i in insns.values():
    if i.kind == "cjump" or i.kind == "jump":
        branch_targets.add(i.target)
for _, (_, _, tg) in switch_tables.items():
    branch_targets.update(tg)

comments = collections.defaultdict(list)
str_refs = collections.defaultdict(set)    # string addr -> {func}
mmio_refs = collections.defaultdict(set)   # block -> {func}
call_args = {}                             # call insn -> {reg: value}

RE_LDR_IMM = re.compile(r"(ldr|str)(b|h|sb|sh)?\s+(r\d+), \[(r\d+), #(\d+)\]")
RE_MOVS = re.compile(r"movs\s+(r\d+), #(\d+)")
RE_ADDI = re.compile(r"adds\s+(r\d+), #(\d+)")
RE_ADD3 = re.compile(r"adds\s+(r\d+), (r\d+), #(\d+)")
RE_LSL = re.compile(r"lsls\s+(r\d+), (r\d+), #(\d+)")
RE_MOVR = re.compile(r"movs?\s+(r\d+), (r\d+)$")


def describe_value(v):
    s = str_at(v)
    if s is not None:
        return '"' + s.replace("\n", "\\n")[:70] + '"'
    for base, _, blk in rp2040regs.BLOCKS:
        if v == base and blk != "ROM":
            return f"{blk}_BASE"
    n = rp2040regs.name(v)
    if n:
        return n
    if v & 1 and (v & ~1) in functions:
        return f"&{{fn_{v & ~1:08x}}}"
    return None


func_of_insn = {}
for e, body in functions.items():
    for a in body:
        func_of_insn.setdefault(a, e)

for e, body in functions.items():
    regs = {}
    for a in body:
        i = insns[a]
        if a in branch_targets:
            regs = {}
        t = i.text()
        if i.mnem == "ldr" and i.lit_addr is not None:
            v = w32(i.lit_addr)
            regs[t.split()[1].rstrip(",")] = v
            d = describe_value(v)
            comments[a].append(f"=0x{v:08x}" + (f" {d}" if d else ""))
            if str_at(v) is not None:
                str_refs[v].add(e)
            continue
        if i.mnem == "adr":
            r = t.split()[1].rstrip(",")
            regs[r] = i.lit_addr
            d = describe_value(i.lit_addr)
            if d:
                comments[a].append(d)
            continue
        m = RE_MOVS.match(t)
        if m:
            regs[m.group(1)] = int(m.group(2)); continue
        m = RE_ADD3.match(t)
        if m:
            if m.group(2) in regs:
                v = (regs[m.group(2)] + int(m.group(3))) & 0xFFFFFFFF
                regs[m.group(1)] = v
                d = describe_value(v)
                if d and v > 0xFFFF:
                    comments[a].append(f"0x{v:08x} {d}")
                    if str_at(v) is not None:
                        str_refs[v].add(e)
            else:
                regs.pop(m.group(1), None)
            continue
        m = RE_ADDI.match(t)
        if m:
            r = m.group(1)
            if r in regs:
                v = (regs[r] + int(m.group(2))) & 0xFFFFFFFF
                regs[r] = v
                d = describe_value(v)
                if d and v > 0xFFFF:
                    comments[a].append(f"0x{v:08x} {d}")
                    if str_at(v) is not None:
                        str_refs[v].add(e)
            continue
        m = RE_LSL.match(t)
        if m:
            if m.group(2) in regs:
                regs[m.group(1)] = (regs[m.group(2)] << int(m.group(3))) & 0xFFFFFFFF
                n = describe_value(regs[m.group(1)]) if regs[m.group(1)] > 0xFFFF else None
                if n:
                    comments[a].append(f"0x{regs[m.group(1)]:08x} {n}")
            else:
                regs.pop(m.group(1), None)
            continue
        m = RE_MOVR.match(t)
        if m and m.group(2) in regs:
            regs[m.group(1)] = regs[m.group(2)]; continue
        m = RE_LDR_IMM.match(t)
        if m:
            base = m.group(4)
            if base in regs:
                ea = (regs[base] + int(m.group(5))) & 0xFFFFFFFF
                n = rp2040regs.name(ea)
                if n:
                    comments[a].append(n)
                    mmio_refs[n.split(".")[0].split("+")[0]].add(e)
                elif seg_of(ea) and ea >= 0x20000000:
                    comments[a].append(f"[0x{ea:08x}]")
            if m.group(1) == "ldr":
                regs.pop(m.group(3), None)
            continue
        if i.kind in ("call", "icall"):
            call_args[a] = {r: regs[r] for r in ("r0", "r1", "r2", "r3") if r in regs}
            for r in ("r0", "r1", "r2", "r3", "r12", "lr"):
                regs.pop(r, None)
            continue
        # any other insn writing a low reg invalidates it
        mm = re.match(r"\w+\s+(r\d+|sp|lr|pc)\b", t)
        if mm and i.mnem not in ("cmp", "cmn", "tst", "str", "strb", "strh", "push", "stmia", "b", "bl", "bx", "blx") \
                and not i.mnem.startswith("b") and not i.mnem.startswith("str"):
            regs.pop(mm.group(1), None)
        if i.mnem in ("pop", "ldmia"):
            for r in re.findall(r"r\d+", t):
                regs.pop(r, None)

# ---------------------------------------------------------------- naming
names = {}
notes = collections.defaultdict(list)
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]{2,}$")

# 1) crt0
names.update({0x100101F6: "_reset_handler", 0x1001958C: "runtime_init",
              0x10010424: "main", 0x10019548: "exit", 0x10010230: "data_cpy",
              0x1001026A: "__get_current_exception", 0x100101C0: "isr_invalid",
              0x100101C2: "isr_nmi", 0x1001022A: "isr_hardfault", 0x100101C4: "isr_svcall",
              0x100101C6: "isr_pendsv", 0x100101C8: "isr_systick",
              0x100101CA: "__unhandled_user_irq"})
for a, k in CASE_HELPERS.items():
    if k:
        names[a] = f"__gnu_thumb1_case_{k}"

# 2) __func__ strings from SDK/TinyUSB asserts: identifier strings referenced as call args
func_strings = {a: s for a, s in strings.items() if IDENT.match(s)}
cands = collections.defaultdict(collections.Counter)
for ca, args in call_args.items():
    f = func_of_insn.get(ca)
    for r, v in args.items():
        if v in func_strings and r in ("r2", "r0", "r1", "r3"):
            cands[f][func_strings[v]] += 1
for f, c in cands.items():
    if f in names:
        continue
    picks = [n for n, _ in c.most_common()]
    names[f] = picks[0]
    if len(picks) > 1:
        notes[f].append("asserts reference: " + ", ".join(picks) + " (inlined callees)")

# 3) well-known by referenced string
def by_string(substr):
    out = set()
    for a, fs in str_refs.items():
        if substr in (str_at(a) or ""):
            out |= fs
    return out


def name_unique(fs, nm, why):
    fs = [f for f in fs if f not in names]
    if len(fs) == 1:
        names[fs[0]] = nm
        notes[fs[0]].append(why)


name_unique(by_string('assertion "%s" failed'), "__assert_func", "formats newlib assertion message")
name_unique(by_string("*** PANIC ***"), "panic", "prints *** PANIC ***")
name_unique(by_string("Attempted to sleep inside of an exception"), "sleep_until", "pico_time sleep check")
name_unique(by_string("Hardware alarm %d already claimed"), "hardware_alarm_claim", "hardware_timer")
name_unique(by_string("No spinlocks are available"), "spin_lock_claim_unused", "hardware_sync")
name_unique(by_string("%s %d: ASSERT FAILED"), "tu_assert_report", "TinyUSB TU_ASSERT")
name_unique(by_string("System Volume Information"), "ode_dir_list_filter", "skips 'System Volume Information'")
name_unique(by_string("Loaded cue/bin.."), "ode_load_cue", "parses .cue sheets (FILE/TRACK/MODE/INDEX)")
name_unique(by_string("Caught dipir reset"), "ode_cd_command_loop", "3DO CD command handling / DIPIR reset")
name_unique(by_string("Updating from %x"), "ode_firmware_update", "flashes /sd|/usb/update.ode")
name_unique(by_string("usb mounted"), "ode_usb_mount", "mounts /usb, opens /usb/boot.iso")
name_unique(by_string("sd mounted"), "ode_sd_mount", "mounts /sd, opens /sd/boot.iso")
name_unique(by_string("toc_rd /sd"), "ode_toc_read_dir", "builds directory listing TOC for 3DO menu")
name_unique(by_string("toc_ch Special case"), "ode_toc_change_dir", "directory navigation from 3DO menu")
name_unique(by_string("next image mounted"), "ode_mount_next_image", "advance to next disc image")
name_unique(by_string("params dens"), "ode_cd_mode_select", "CD drive mode/params command")
name_unique(by_string("Opening %s, res=%d"), "ode_open_file", "f_open wrapper")

# 4) printf = most common callee whose r0 is a format string containing '%'
fmt_callees = collections.Counter()
for ca, args in call_args.items():
    v = args.get("r0")
    s = str_at(v) if v is not None else None
    if s and "%" in s:
        i = insns[ca]
        if i.kind == "call":
            fmt_callees[i.target] += 1
if fmt_callees:
    pf = fmt_callees.most_common(1)[0][0]
    names.setdefault(pf, "printf")
    notes[pf].append(f"called with format strings {fmt_callees[pf]}x")

# 5) library functions identified by byte match (tools/match_libs.py) beat the heuristics
from names_matched import MATCHED
confidence = {}
for a, (nm, how) in MATCHED.items():
    if a in functions:
        alts = nm.split("|")
        names[a] = alts[0]
        confidence[a] = "C" if how.startswith("match") else "L"
        notes[a].insert(0, how + (" (identical: " + ", ".join(alts[1:]) + ")" if len(alts) > 1 else ""))

# 6) curated names take priority
from names_manual import MANUAL
for a, (nm, conf, why) in MANUAL.items():
    if a in functions:
        names[a] = nm
        confidence[a] = conf
        if why:
            notes[a].insert(0, why)
# linker long-branch veneers: push {r0}; ldr r0,[pc,#8]; mov ip,r0; pop {r0}; bx ip
for e in functions:
    if rd(e, 10) == bytes.fromhex("01b40248844601bc6047"):
        d = w32(((e + 6) & ~3) + 8) & ~1
        names[e] = "__%s_veneer" % names.get(d, "fn_%08x" % d)
        notes[e].insert(0, "linker veneer -> %08x" % d)
# leave unnamed functions as fn_<addr>; keep names unique (symbol files need it)
seen = set()
for e in sorted(functions):
    nm = names.setdefault(e, f"fn_{e:08x}")
    if nm in seen:
        names[e] = nm = f"{nm}_{e:08x}"
    seen.add(nm)

# ---------------------------------------------------------------- emit
os.makedirs(OUT, exist_ok=True)


def label(a):
    return names.get(a) or names.get(a & ~1)


def fmt_insn(i):
    t = i.text()
    if i.target is not None and label(i.target):
        t = t.replace(f"0x{i.target:08x}", f"{label(i.target)}")
    c = list(comments.get(i.addr, []))
    if i.kind == "call":
        args = call_args.get(i.addr, {})
        for r in ("r0", "r1", "r2", "r3"):
            if r in args:
                d = describe_value(args[r])
                if d:
                    c.append(f"{r}={d}")
    if i.addr in switch_tables:
        k, base, tg = switch_tables[i.addr]
        dflt = collections.Counter(tg).most_common(1)[0][0]
        c.append(f"switch table @{base:08x}, {len(tg)} entries, default/most-common -> .L{dflt:08x}")
    b = rd(i.addr, i.size).hex()
    return f"  {i.addr:08x}:  {b:<9} {t}" + (f"    ; {' | '.join(c)}" if c else "")


case_labels = {}
for _, (k, base, tg) in switch_tables.items():
    dflt = collections.Counter(tg).most_common(1)[0][0] if len(tg) > 8 else None
    grp = collections.defaultdict(list)
    for j, x in enumerate(tg):
        if x != dflt:
            grp[x].append(j)
    for x, js in grp.items():
        case_labels[x] = ", ".join(f"0x{j:02x}" for j in js)
    if dflt is not None:
        case_labels[dflt] = "default"

callers = collections.defaultdict(set)
for tgt, sites in xrefs_call.items():
    for s in sites:
        if s in func_of_insn:
            callers[tgt].add(func_of_insn[s])

with open(os.path.join(OUT, "piode2_disasm.s"), "w") as f:
    f.write("@ piode2 v0.1 (3DO FZ-1 ODE) - RP2040 / Cortex-M0+ Thumb disassembly\n")
    f.write("@ image base 0x10010000 (app after 64KB bootloader); .data/RAM code at 0x%08x\n" % SEGS[1].vma if len(SEGS) > 1 else "")
    f.write("@ generated by custom ARMv6-M disassembler; names marked fn_XXXXXXXX are unidentified\n\n")
    for e in sorted(functions):
        lo, hi = func_bounds[e]
        f.write(f"\n@ ==================================================================\n")
        f.write(f"@ {names[e]}   [{lo:08x}..{hi:08x}) {hi - lo} bytes   ({func_entries.get(e, '')})\n")
        cs = sorted(names[c] for c in callers.get(e, []))
        if cs:
            f.write(f"@ called by: {', '.join(cs[:12])}{' ...' if len(cs) > 12 else ''}\n")
        for n in notes.get(e, []):
            f.write(f"@ note: {n}\n")
        f.write(f"{names[e]}:\n")
        a = lo
        body = set(functions[e])
        while a < hi:
            if a in body:
                if a in branch_targets and a != e:
                    f.write(f" .L{a:08x}:" + (f"    @ case {case_labels[a]}" if a in case_labels else "") + "\n")
                i = insns[a]
                f.write(fmt_insn(i) + "\n")
                a += i.size
            else:
                # data inside function range (literal pool / switch table)
                if a % 4 == 0 and w32(a) is not None and all(x not in body for x in range(a, a + 4)) and a + 4 <= hi:
                    v = w32(a)
                    d = describe_value(v)
                    f.write(f"  {a:08x}:  .word 0x{v:08x}" + (f"    ; {d}" if d else "") + "\n")
                    a += 4
                else:
                    b = rd(a, 2)
                    f.write(f"  {a:08x}:  .short 0x{int.from_bytes(b, 'little'):04x}\n")
                    a += 2

with open(os.path.join(OUT, "functions.tsv"), "w") as f:
    f.write("address\tsize\tname\tcallers\tcallees\tstrings\tperipherals\tnotes\n")
    for e in sorted(functions):
        lo, hi = func_bounds[e]
        callees = sorted({names.get(insns[a].target, f"{insns[a].target:08x}") for a in functions[e]
                          if insns[a].kind == "call"})
        strs = sorted({str_at(s)[:40] for s, fs in str_refs.items() if e in fs})
        per = sorted({b for b, fs in mmio_refs.items() if e in fs})
        f.write(f"{e:08x}\t{hi - lo}\t{names[e]}\t{len(callers.get(e, []))}\t{', '.join(callees)}\t"
                f"{' || '.join(strs)}\t{', '.join(per)}\t{'; '.join(notes.get(e, []))}\n")

with open(os.path.join(OUT, "ghidra_symbols.txt"), "w") as f:
    for e in sorted(functions):
        if not names[e].startswith("fn_"):
            f.write(f"{names[e]} {e:08x} f\n")
    for a, s in sorted(strings.items()):
        f.write(f"s_{re.sub(r'[^A-Za-z0-9_]', '_', s)[:40]}_{a:08x} {a:08x} l\n")

# ---------------------------------------------------------------- ELF with symbols
def write_elf(path):
    DATA_LMA = ram_copies[0][0]
    text = raw[:DATA_LMA - FLASH]
    data = raw[DATA_LMA - FLASH:]
    BSS = (0x20000AE0, 0x200075F8)
    shstr = b"\0.text\0.data\0.bss\0.symtab\0.strtab\0.shstrtab\0"
    so = lambda n: shstr.index(n.encode() + b"\0")
    strtab = bytearray(b"\0")
    syms = [struct.pack("<IIIBBH", 0, 0, 0, 0, 0, 0)]

    def sym(nm, val, size, typ, shndx, bind=1):
        o = len(strtab)
        strtab.extend(nm.encode() + b"\0")
        syms.append(struct.pack("<IIIBBH", o, val, size, (bind << 4) | typ, 0, shndx))

    locals_ = []
    # mapping symbols ($t code / $d data) — local, must precede globals
    code_set = set(insns)
    for e in sorted(functions):
        lo, hi = func_bounds[e]
        sh = 1 if e < 0x20000000 else 2
        state = None
        a = lo
        while a < hi:
            st = "t" if a in code_set else ("d" if a in data_marks else state)
            if st != state:
                locals_.append((f"${st}", a, sh))
                state = st
            a += 2
    for a, s in sorted(strings.items()):
        locals_.append((f"s_{re.sub(r'[^A-Za-z0-9_]', '_', s)[:40]}_{a:08x}", a, 1 if a < 0x20000000 else 2))
    for nm, a, sh in locals_:
        sym(nm, a, 0, 0 if nm.startswith("$") else 1, sh, bind=0)
    first_global = len(syms)
    for e in sorted(functions):
        lo, hi = func_bounds[e]
        sym(names[e], e | 1, hi - lo, 2, 1 if e < 0x20000000 else 2)
    symtab = b"".join(syms)

    ehsz, phsz, shsz = 52, 32, 40
    off_text = ehsz + 3 * phsz
    off_text = (off_text + 0xFF) & ~0xFF
    off_data = off_text + len(text)
    off_sym = (off_data + len(data) + 3) & ~3
    off_str = off_sym + len(symtab)
    off_shs = off_str + len(strtab)
    off_sh = (off_shs + len(shstr) + 3) & ~3
    eh = b"\x7fELF" + bytes([1, 1, 1, 0]) + bytes(8)
    eh += struct.pack("<HHIIIIIHHHHHH", 2, 40, 1, 0x100101F7, ehsz, off_sh, 0x05000200,
                      ehsz, phsz, 3, shsz, 7, 6)
    ph = struct.pack("<8I", 1, off_text, FLASH, FLASH, len(text), len(text), 5, 0x100)
    ph += struct.pack("<8I", 1, off_data, 0x200000C0, DATA_LMA, len(data), len(data), 6, 4)
    ph += struct.pack("<8I", 1, 0, BSS[0], BSS[0], 0, BSS[1] - BSS[0], 6, 4)
    shdrs = [bytes(40),
             struct.pack("<10I", so(".text"), 1, 6, FLASH, off_text, len(text), 0, 0, 4, 0),
             struct.pack("<10I", so(".data"), 1, 7, 0x200000C0, off_data, len(data), 0, 0, 4, 0),
             struct.pack("<10I", so(".bss"), 8, 3, BSS[0], off_sym, BSS[1] - BSS[0], 0, 0, 4, 0),
             struct.pack("<10I", so(".symtab"), 2, 0, 0, off_sym, len(symtab), 5, first_global, 4, 16),
             struct.pack("<10I", so(".strtab"), 3, 0, 0, off_str, len(strtab), 0, 0, 1, 0),
             struct.pack("<10I", so(".shstrtab"), 3, 0, 0, off_shs, len(shstr), 0, 0, 1, 0)]
    out = bytearray(eh + ph)
    out += bytes(off_text - len(out)) + text + data
    out += bytes(off_sym - len(out)) + symtab + strtab + shstr
    out += bytes(off_sh - len(out)) + b"".join(shdrs)
    open(path, "wb").write(out)


write_elf(os.path.join(OUT, "piode2.elf"))

with open(os.path.join(OUT, "piode2_symbols.ld"), "w") as f:
    f.write("/* Firmware function addresses for linking patch code against piode2 v0.1.\n"
            "   Thumb bit is set (|1). Names marked fn_* are unidentified. */\n")
    for e in sorted(functions):
        f.write(f"PROVIDE({names[e]} = 0x{e | 1:08x});\n")
    # SDK --wrap targets: let patch code call printf/memcpy/... by their plain names
    plain = set(names.values())
    for e in sorted(functions):
        nm = names[e]
        if nm.startswith("__wrap_") and nm[7:] not in plain:
            f.write(f"PROVIDE({nm[7:]} = 0x{e | 1:08x});\n")

db = {"functions": {f"{e:08x}": {"name": names[e], "bounds": func_bounds[e]} for e in functions},
      "segments": [(s.name, s.vma, len(s.data), s.lma) for s in SEGS],
      "text_end": text_end, "switch_tables": len(switch_tables)}
json.dump(db, open(os.path.join(OUT, "db.json"), "w"), indent=1)

named = sum(1 for e in functions if not names[e].startswith("fn_"))
print(f"functions: {len(functions)}  named: {named}  insns: {len(insns)}  switch tables: {len(switch_tables)}")
print(f"text end: 0x{text_end:08x}  strings: {len(strings)}  string-referencing sites: {sum(len(v) for v in str_refs.values())}")
print("case helpers:", {f'{a:08x}': k for a, k in CASE_HELPERS.items() if k})
print("peripheral blocks used:", {k: len(v) for k, v in sorted(mmio_refs.items())})
