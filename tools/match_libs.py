"""Name firmware functions by matching them against reference library object files.

Usage: python match_libs.py <piode2.elf> <functions.tsv> <out names_matched.py> <objdir_or_file>...
Needs pyelftools. Reference objects: Pico SDK 1.3.0 Debug build (-Og) objects, FatFs,
newlib libc/libm, libgcc, all built with GNU Arm Embedded 10.3-2021.10.

A match = same length, all bytes equal except those covered by relocations.
Then names propagate through relocations: a BL/literal in a matched function that the
reference resolves to symbol S names the firmware target S as well ("via").
"""
import sys, os, struct, collections
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ELF, TSV, OUT, *REFS = sys.argv[1:]

# ------------------------------------------------------------ firmware image
fw = ELFFile(open(ELF, "rb"))
segs = [(s["p_vaddr"], s.data()) for s in fw.iter_segments() if s["p_type"] == "PT_LOAD" and s["p_filesz"]]


def fw_bytes(a, n):
    for va, d in segs:
        if va <= a and a + n <= va + len(d):
            return d[a - va:a - va + n]
    return None


targets = {}
for line in open(TSV).read().splitlines()[1:]:
    f = line.split("\t")
    if len(f) < 3 or not all(c in "0123456789abcdef" for c in f[0]) or len(f[0]) != 8:
        continue
    targets[int(f[0], 16)] = (int(f[1]), f[2])
for extra in (0x100102f0, 0x1001becc, 0x1001c5c0):
    targets.setdefault(extra, (0, "fn_%08x" % extra))

# ------------------------------------------------------------ reference functions
RELSZ = {"R_ARM_THM_CALL": 4, "R_ARM_THM_JUMP24": 4, "R_ARM_ABS32": 4, "R_ARM_REL32": 4,
         "R_ARM_THM_JUMP11": 2, "R_ARM_THM_JUMP8": 2, "R_ARM_TARGET1": 4, "R_ARM_PREL31": 4,
         "R_ARM_THM_PC8": 2, "R_ARM_THM_JUMP6": 2, "R_ARM_V4BX": 0, "R_ARM_NONE": 0}

refs = []  # (name, obj, bytes, mask, relocs[(off, type, symname, addend)])


def load_obj(path):
    try:
        e = ELFFile(open(path, "rb"))
    except Exception:
        return
    if e["e_machine"] != "EM_ARM":
        return
    symtab = e.get_section_by_name(".symtab")
    if not symtab:
        return
    syms = list(symtab.iter_symbols())
    relmap = {}
    for s in e.iter_sections():
        if isinstance(s, RelocationSection):
            relmap[s["sh_info"]] = s
    bysec = collections.defaultdict(list)
    for s in syms:
        if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int):
            bysec[s["st_shndx"]].append(s)
    for shndx, fs in bysec.items():
        sec = e.get_section(shndx)
        data = sec.data()
        rels = []
        if shndx in relmap:
            for r in relmap[shndx].iter_relocations():
                rs = syms[r["r_info_sym"]]
                nm = rs.name
                if not nm and rs["st_info"]["type"] == "STT_SECTION":
                    nm = e.get_section(rs["st_shndx"]).name
                typ = r["r_info_type"]
                from elftools.elf.enums import ENUM_RELOC_TYPE_ARM
                tname = next((k for k, v in ENUM_RELOC_TYPE_ARM.items() if v == typ), str(typ))
                add = struct.unpack_from("<I", data, r["r_offset"])[0] if tname in ("R_ARM_ABS32", "R_ARM_TARGET1") else 0
                rels.append((r["r_offset"], tname, nm, add))
        starts = sorted({s["st_value"] & ~1 for s in fs} | {len(data)})
        for s in fs:
            off = s["st_value"] & ~1
            size = s["st_size"] or (next(x for x in starts if x > off) - off)
            if size < 2:
                continue
            b = data[off:off + size]
            mask = bytearray(len(b))
            frel = []
            for ro, t, nm, add in rels:
                if off <= ro < off + size:
                    n = RELSZ.get(t, 4)
                    for i in range(ro - off, min(ro - off + n, size)):
                        mask[i] = 1
                    frel.append((ro - off, t, nm, add))
            refs.append((s.name, os.path.basename(path), bytes(b), bytes(mask), frel))


for r in REFS:
    if os.path.isdir(r):
        for root, _, files in os.walk(r):
            for f in files:
                if f.endswith((".o", ".obj")):
                    load_obj(os.path.join(root, f))
    else:
        load_obj(r)
print("reference functions:", len(refs), file=sys.stderr)

# index by (size, first 2 unmasked-ish bytes) -- just size buckets
bysize = collections.defaultdict(list)
for r in refs:
    bysize[len(r[2])].append(r)


def matches(ref, tb):
    _, _, b, m, _ = ref
    for i in range(len(b)):
        if not m[i] and b[i] != tb[i]:
            return False
    return True


starts = None


def find(addr, tsize):
    """refs whose bytes match at addr; size between the tsv size (code only, no literal
    pool) and the gap to the next known function."""
    global starts
    if starts is None:
        starts = sorted(targets)
    i = starts.index(addr)
    gap = (starts[i + 1] - addr) if i + 1 < len(starts) else 0x400
    out = []
    for sz in bysize:
        if sz < max(tsize, 2) or sz > gap:
            continue
        tb = fw_bytes(addr, sz)
        if tb is None:
            continue
        for ref in bysize[sz]:
            if matches(ref, tb):
                out.append(ref)
    if out:  # prefer the longest matches
        best = max(len(r[2]) for r in out)
        out = [r for r in out if len(r[2]) == best]
    return out


def bl_target(a):
    b = fw_bytes(a, 4)
    h1, h2 = struct.unpack("<HH", b)
    s = (h1 >> 10) & 1
    j1, j2 = (h2 >> 13) & 1, (h2 >> 11) & 1
    i1, i2 = 1 - (j1 ^ s), 1 - (j2 ^ s)
    off = (s << 24) | (i1 << 23) | (i2 << 22) | ((h1 & 0x3ff) << 12) | ((h2 & 0x7ff) << 1)
    if s:
        off -= 1 << 25
    return a + 4 + off


VENEER = bytes.fromhex("01b402488446 01bc6047".replace(" ", ""))


def veneer_dest(a):
    """long-branch veneer: push {r0}; ldr r0,[pc,#8]; mov ip,r0; pop {r0}; bx ip"""
    b = fw_bytes(a, 10)
    if b != VENEER:
        return None
    return struct.unpack("<I", fw_bytes(((a + 2 + 4) & ~3) + 8, 4))[0] & ~1


names = {}  # addr -> (name, how)
data_names = {}
for addr, (tsize, cur) in sorted(targets.items()):
    c = find(addr, tsize)
    if not c:
        continue
    nm = sorted({r[0] for r in c})
    names[addr] = ("|".join(nm), "match:" + ",".join(sorted({r[1] for r in c}))[:60], c)

# disambiguate: the linker keeps an object's functions together, so prefer candidates
# from the object file of the nearest unambiguous neighbours; drop trivial stubs
# (getters, bx lr) whose neighbours are not library code.
uniq = sorted((a, v[2][0][1]) for a, v in names.items() if "|" not in v[0])
for addr, (nm, how, c) in list(names.items()):
    small = len(c[0][2]) <= 12
    if "|" not in nm and not small:
        continue
    prev = [o for a, o in uniq if a < addr][-1:]
    nxt = [o for a, o in uniq if a > addr][:1]
    near = set(prev + nxt)
    cc = [r for r in c if r[1] in near]
    ns = sorted({r[0] for r in cc})
    if small and not cc:
        del names[addr]
        continue
    if cc and len(ns) <= 4:
        names[addr] = ("|".join(ns), "match:%s(neighbour)" % cc[0][1], cc)
    elif len({r[0] for r in c}) > 4:
        del names[addr]

# propagate via relocations, iterate until stable
changed = True
while changed:
    changed = False
    for addr, (nm, how, c) in list(names.items()):
        if not c:
            continue
        ref = c[0]
        if "|" in nm and len({tuple(x[4]) for x in c}) > 1:
            continue
        for off, t, sym, add in ref[4]:
            if t in ("R_ARM_THM_CALL", "R_ARM_THM_JUMP24") and not sym.startswith("."):
                tgt = bl_target(addr + off)
                v = veneer_dest(tgt)
                if v is not None:
                    if tgt not in names:
                        names[tgt] = ("__%s_veneer" % sym, "veneer", [])
                    tgt = v
                if tgt not in names and tgt in targets:
                    names[tgt] = (sym, "via:%s+%#x" % (nm.split("|")[0], off), [])
                    cc = find(tgt, targets[tgt][0])
                    if cc:
                        names[tgt] = (sym, names[tgt][1], cc)
                    changed = True
            elif t in ("R_ARM_ABS32", "R_ARM_TARGET1") and not sym.startswith("."):
                v = struct.unpack("<I", fw_bytes(addr + off, 4))[0]
                if (v & 1) and (v & ~1) in targets and (v & ~1) not in names:
                    names[v & ~1] = (sym, "ptr:%s+%#x" % (nm.split("|")[0], off), [])
                    changed = True
                elif not (v & 1) and sym and add == 0:
                    data_names.setdefault(v, set()).add(sym)

with open(OUT, "w") as f:
    f.write('"""Generated by match_libs.py -- library functions identified by byte match against\n'
            'Pico SDK 1.3.0 / TinyUSB 0.12 / FatFs / newlib / libgcc objects (GCC 10.3-2021.10, -Og)."""\n')
    f.write("MATCHED = {\n")
    for a in sorted(names):
        nm, how, _ = names[a]
        f.write("    0x%08x: (%r, %r),\n" % (a, nm, how))
    f.write("}\n\nDATA = {\n")
    for v in sorted(data_names):
        f.write("    0x%08x: %r,\n" % (v, "|".join(sorted(data_names[v]))))
    f.write("}\n")

nfn = len(targets)
print("matched %d / %d functions (%d by byte match, %d via relocs), %d data symbols" % (
    len(names), nfn, sum(1 for v in names.values() if v[1].startswith("match")),
    sum(1 for v in names.values() if not v[1].startswith("match")), len(data_names)), file=sys.stderr)
