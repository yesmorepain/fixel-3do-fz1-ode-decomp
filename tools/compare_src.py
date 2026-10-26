"""Compare reconstructed source objects against the original image, function by function.

Usage: python compare_src.py <piode2.elf> <functions.tsv> <objdir> [name ...]
Needs pyelftools. A function is MATCH when its bytes equal the original everywhere except
relocated fields, and every call relocation targets the function the original calls.
"""
import sys, os, struct, collections, difflib
try:
    import capstone
    CS = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
except ImportError:
    CS = None


def shape(b, addr):
    """instruction mnemonics + immediates/registers-free operands, for a similarity score"""
    out = []
    for i in CS.disasm(b, addr):
        m = i.mnemonic.replace(".w", "").replace(".n", "")
        ops = "".join(c for c in i.op_str if not c.isalnum() or c == "#")
        out.append(m + ops)
    return out
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from elftools.elf.enums import ENUM_RELOC_TYPE_ARM

ELF, TSV, OBJDIR, *ONLY = sys.argv[1:]
RTYPE = {v: k for k, v in ENUM_RELOC_TYPE_ARM.items()}
RELSZ = {"R_ARM_THM_JUMP11": 2, "R_ARM_THM_JUMP8": 2, "R_ARM_THM_PC8": 2, "R_ARM_V4BX": 0, "R_ARM_NONE": 0}

fw = ELFFile(open(ELF, "rb"))
segs = [(s["p_vaddr"], s.data()) for s in fw.iter_segments() if s["p_type"] == "PT_LOAD" and s["p_filesz"]]


def fw_bytes(a, n):
    for va, d in segs:
        if va <= a and a + n <= va + len(d):
            return d[a - va:a - va + n]
    return None


byaddr, byname = {}, {}
for line in open(TSV).read().splitlines()[1:]:
    f = line.split("\t")
    if len(f) < 3 or len(f[0]) != 8 or not all(c in "0123456789abcdef" for c in f[0]):
        continue
    byaddr[int(f[0], 16)] = f[2]
    byname[f[2]] = (int(f[0], 16), int(f[1]))
starts = sorted(byaddr)


def bl_target(a):
    h1, h2 = struct.unpack("<HH", fw_bytes(a, 4))
    s = (h1 >> 10) & 1
    i1, i2 = 1 - (((h2 >> 13) & 1) ^ s), 1 - (((h2 >> 11) & 1) ^ s)
    off = (s << 24) | (i1 << 23) | (i2 << 22) | ((h1 & 0x3ff) << 12) | ((h2 & 0x7ff) << 1)
    return a + 4 + off - ((1 << 25) if s else 0)


def norm(n):
    n = n or ""
    if n == "__aeabi_uidivmod":
        n = "__aeabi_uidiv"
    if n.startswith("__wrap_"):
        n = n[7:]
    if n.startswith("__") and n.endswith("_veneer"):
        n = n[2:-7]
    return n


mine = {}
for root, _, files in os.walk(OBJDIR):
    for fn in files:
        if not fn.endswith((".o", ".obj")):
            continue
        e = ELFFile(open(os.path.join(root, fn), "rb"))
        st = e.get_section_by_name(".symtab")
        if not st:
            continue
        syms = list(st.iter_symbols())
        rels = {s["sh_info"]: s for s in e.iter_sections() if isinstance(s, RelocationSection)}
        for s in syms:
            if s["st_info"]["type"] != "STT_FUNC" or not isinstance(s["st_shndx"], int):
                continue
            sec = e.get_section(s["st_shndx"])
            off, size = s["st_value"] & ~1, s["st_size"]
            data = sec.data()[off:off + size]
            rl = []
            if s["st_shndx"] in rels:
                for r in rels[s["st_shndx"]].iter_relocations():
                    if off <= r["r_offset"] < off + size:
                        rs = syms[r["r_info_sym"]]
                        nm = rs.name or e.get_section(rs["st_shndx"]).name
                        rl.append((r["r_offset"] - off, RTYPE.get(r["r_info_type"], "?"), nm))
            mine[s.name] = (data, rl, fn)

res = collections.Counter()
for name, (addr, tsize) in sorted(byname.items(), key=lambda x: x[1][0]):
    if ONLY and name not in ONLY:
        continue
    if name not in mine:
        continue
    data, rl, obj = mine[name]
    i = starts.index(addr)
    gap = starts[i + 1] - addr if i + 1 < len(starts) else len(data)
    orig = fw_bytes(addr, max(len(data), 2))
    mask = bytearray(len(data))
    bad_calls = []
    for o, t, sym in rl:
        for k in range(o, min(o + RELSZ.get(t, 4), len(data))):
            mask[k] = 1
    # ordered call lists: original (decoded BLs) vs rebuilt (call relocations)
    my_calls = [norm(sym) for o, t, sym in sorted(rl) if t in ("R_ARM_THM_CALL", "R_ARM_THM_JUMP24")]
    orig_calls = []
    k = 0
    while orig and k + 4 <= min(tsize or len(data), len(orig)):
        h1 = orig[k] | orig[k + 1] << 8
        if (h1 & 0xf800) == 0xf000 and ((orig[k + 2] | orig[k + 3] << 8) & 0xd000) == 0xd000:
            orig_calls.append(norm(byaddr.get(bl_target(addr + k), "?")))
            k += 4
        else:
            k += 2
    if orig_calls != my_calls:
        sm = difflib.SequenceMatcher(None, orig_calls, my_calls)
        for op, a1, a2, b1, b2 in sm.get_opcodes():
            if op != "equal":
                bad_calls.append("%s:[%s]->[%s]" % (op, ",".join(orig_calls[a1:a2]), ",".join(my_calls[b1:b2])))
    diff = sum(1 for k in range(len(data)) if not mask[k] and (orig is None or data[k] != orig[k]))
    sizeok = tsize <= len(data) <= gap
    sim = 1.0
    if CS and orig and diff:
        code_end = min(len(data), tsize or len(data))
        sim = difflib.SequenceMatcher(None, shape(orig[:code_end], addr), shape(data[:code_end], addr)).ratio()
    if diff == 0 and not bad_calls and sizeok:
        st = "MATCH"
    else:
        st = "DIFF"
    res[st] += 1
    if st != "MATCH" or ONLY or os.environ.get("ALL"):
        print("%-5s %-30s %08x orig~%d mine=%d diff=%d sim=%.2f %s" % (st, name, addr, tsize, len(data), diff, sim,
                                                                      " ".join(bad_calls[:4])))
print("summary:", dict(res))
