"""Minimal but complete ARMv6-M (Cortex-M0/M0+) Thumb disassembler.

decode(buf, off, addr) -> Insn(size, mnem, ops, target, lit_addr, kind)
  target   : branch/call destination (absolute) if any
  lit_addr : address of a PC-relative literal loaded (LDR rX,[pc,#]) / ADR result
  kind     : 'call' | 'jump' | 'cjump' | 'ret' | 'ijump' | 'icall' | None
"""
import struct
from dataclasses import dataclass

R = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
     "r8", "r9", "r10", "r11", "r12", "sp", "lr", "pc"]
COND = ["eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc",
        "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"]
SYSM = {0: "apsr", 1: "iapsr", 2: "eapsr", 3: "xpsr", 5: "ipsr", 6: "epsr",
        7: "iepsr", 8: "msp", 9: "psp", 16: "primask", 20: "control"}


@dataclass
class Insn:
    addr: int
    size: int
    mnem: str
    ops: str = ""
    target: int = None
    lit_addr: int = None
    kind: str = None
    raw: int = 0

    def text(self):
        return f"{self.mnem:<8}{self.ops}".rstrip()


def reglist(mask, extra=None):
    regs = [R[i] for i in range(8) if mask >> i & 1]
    if extra:
        regs.append(extra)
    return "{" + ", ".join(regs) + "}"


def sx(v, bits):
    return v - (1 << bits) if v >> (bits - 1) & 1 else v


def decode(buf, off, addr):
    if off + 2 > len(buf):
        return None
    h = struct.unpack_from("<H", buf, off)[0]
    top5 = h >> 11
    if top5 in (0x1D, 0x1E, 0x1F):
        if off + 4 > len(buf):
            return Insn(addr, 2, ".short", f"0x{h:04x}", raw=h)
        h2 = struct.unpack_from("<H", buf, off + 2)[0]
        return decode32(h, h2, addr)
    return decode16(h, addr)


def decode32(h1, h2, addr):
    raw = h1 << 16 | h2
    # BL
    if (h1 >> 11) == 0x1E and (h2 >> 14) == 3 and (h2 >> 12) & 1:
        S = (h1 >> 10) & 1
        J1 = (h2 >> 13) & 1
        J2 = (h2 >> 11) & 1
        I1 = 1 - (J1 ^ S)
        I2 = 1 - (J2 ^ S)
        imm = (S << 24) | (I1 << 23) | (I2 << 22) | ((h1 & 0x3FF) << 12) | ((h2 & 0x7FF) << 1)
        imm = sx(imm, 25)
        t = (addr + 4 + imm) & 0xFFFFFFFF
        return Insn(addr, 4, "bl", f"0x{t:08x}", target=t, kind="call", raw=raw)
    # MSR
    if (h1 & 0xFFF0) == 0xF380 and (h2 & 0xFF00) == 0x8800:
        return Insn(addr, 4, "msr", f"{SYSM.get(h2 & 0xFF, hex(h2 & 0xFF))}, {R[h1 & 0xF]}", raw=raw)
    # MRS
    if h1 == 0xF3EF and (h2 & 0xF000) == 0x8000:
        return Insn(addr, 4, "mrs", f"{R[(h2 >> 8) & 0xF]}, {SYSM.get(h2 & 0xFF, hex(h2 & 0xFF))}", raw=raw)
    # barriers
    if h1 == 0xF3BF and (h2 & 0xFF00) == 0x8F00:
        op = (h2 >> 4) & 0xF
        name = {4: "dsb", 5: "dmb", 6: "isb"}.get(op)
        if name:
            return Insn(addr, 4, name, "sy" if (h2 & 0xF) == 0xF else f"#{h2 & 0xF}", raw=raw)
    if (h1 & 0xFFF0) == 0xF7F0 and (h2 & 0xF000) == 0xA000:
        return Insn(addr, 4, "udf.w", f"#{((h1 & 0xF) << 12) | (h2 & 0xFFF)}", kind="ret", raw=raw)
    return Insn(addr, 4, ".word", f"0x{h2 << 16 | h1:08x}  ; undefined 32-bit", raw=raw)


DP = ["ands", "eors", "lsls", "lsrs", "asrs", "adcs", "sbcs", "rors",
      "tst", "rsbs", "cmp", "cmn", "orrs", "muls", "bics", "mvns"]
LSREG = ["str", "strh", "strb", "ldrsb", "ldr", "ldrh", "ldrb", "ldrsh"]


def decode16(h, addr):
    I = lambda m, o="", **k: Insn(addr, 2, m, o, raw=h, **k)
    rd, rn, rm = h & 7, (h >> 3) & 7, (h >> 6) & 7
    op5 = h >> 11
    if op5 <= 2:
        imm = (h >> 6) & 0x1F
        if op5 == 0 and imm == 0:
            return I("movs", f"{R[rd]}, {R[rn]}")
        if op5 != 0 and imm == 0:
            imm = 32
        return I(["lsls", "lsrs", "asrs"][op5], f"{R[rd]}, {R[rn]}, #{imm}")
    if op5 == 3:
        sub = (h >> 9) & 1
        if (h >> 10) & 1:
            return I("subs" if sub else "adds", f"{R[rd]}, {R[rn]}, #{rm}")
        return I("subs" if sub else "adds", f"{R[rd]}, {R[rn]}, {R[rm]}")
    if 4 <= op5 <= 7:
        r = (h >> 8) & 7
        imm = h & 0xFF
        return I(["movs", "cmp", "adds", "subs"][op5 - 4], f"{R[r]}, #{imm}" + (f"  ; 0x{imm:x}" if imm > 9 else ""))
    if (h >> 10) == 0x10:
        op = (h >> 6) & 0xF
        if op == 9:
            return I("rsbs", f"{R[rd]}, {R[rn]}, #0")
        if op == 13:
            return I("muls", f"{R[rd]}, {R[rn]}, {R[rd]}")
        if op in (8, 10, 11):
            return I(DP[op], f"{R[rd]}, {R[rn]}")
        return I(DP[op], f"{R[rd]}, {R[rn]}")
    if (h >> 10) == 0x11:
        op = (h >> 8) & 3
        d = ((h >> 4) & 8) | rd
        m = (h >> 3) & 0xF
        if op == 0:
            return I("add", f"{R[d]}, {R[m]}", kind="ijump" if d == 15 else None)
        if op == 1:
            return I("cmp", f"{R[d]}, {R[m]}")
        if op == 2:
            if d == 8 and m == 8:
                return I("nop", "; mov r8, r8")
            return I("mov", f"{R[d]}, {R[m]}", kind="ijump" if d == 15 else None)
        if (h >> 7) & 1:
            return I("blx", R[m], kind="icall")
        return I("bx", R[m], kind="ret" if m == 14 else "ijump")
    if op5 == 9:
        r = (h >> 8) & 7
        imm = (h & 0xFF) * 4
        la = ((addr + 4) & ~3) + imm
        return I("ldr", f"{R[r]}, [pc, #{imm}]", lit_addr=la)
    if (h >> 12) == 5:
        op = (h >> 9) & 7
        return I(LSREG[op], f"{R[rd]}, [{R[rn]}, {R[rm]}]")
    if (h >> 13) == 3:
        b = (h >> 12) & 1
        L = (h >> 11) & 1
        imm = (h >> 6) & 0x1F
        imm = imm if b else imm * 4
        return I(("ldr" if L else "str") + ("b" if b else ""), f"{R[rd]}, [{R[rn]}, #{imm}]")
    if (h >> 12) == 8:
        L = (h >> 11) & 1
        imm = ((h >> 6) & 0x1F) * 2
        return I("ldrh" if L else "strh", f"{R[rd]}, [{R[rn]}, #{imm}]")
    if (h >> 12) == 9:
        L = (h >> 11) & 1
        r = (h >> 8) & 7
        imm = (h & 0xFF) * 4
        return I("ldr" if L else "str", f"{R[r]}, [sp, #{imm}]")
    if (h >> 12) == 0xA:
        sp = (h >> 11) & 1
        r = (h >> 8) & 7
        imm = (h & 0xFF) * 4
        if sp:
            return I("add", f"{R[r]}, sp, #{imm}")
        la = ((addr + 4) & ~3) + imm
        return I("adr", f"{R[r]}, 0x{la:08x}", lit_addr=la)
    if (h >> 12) == 0xB:
        if (h & 0xFF00) == 0xB000:
            imm = (h & 0x7F) * 4
            return I("sub" if (h >> 7) & 1 else "add", f"sp, #{imm}")
        if (h & 0xFF00) == 0xB200:
            return I(["sxth", "sxtb", "uxth", "uxtb"][(h >> 6) & 3], f"{R[rd]}, {R[rn]}")
        if (h & 0xFE00) == 0xB400:
            return I("push", reglist(h & 0xFF, "lr" if (h >> 8) & 1 else None))
        if (h & 0xFFEF) == 0xB662:
            return I("cpsid" if (h >> 4) & 1 else "cpsie", "i")
        if (h & 0xFF00) == 0xBA00 and ((h >> 6) & 3) != 2:
            return I(["rev", "rev16", "", "revsh"][(h >> 6) & 3], f"{R[rd]}, {R[rn]}")
        if (h & 0xFE00) == 0xBC00:
            pc = (h >> 8) & 1
            return I("pop", reglist(h & 0xFF, "pc" if pc else None), kind="ret" if pc else None)
        if (h & 0xFF00) == 0xBE00:
            return I("bkpt", f"#{h & 0xFF}", kind="ret")
        if (h & 0xFF0F) == 0xBF00:
            return I(["nop", "yield", "wfe", "wfi", "sev"][(h >> 4) & 0xF] if ((h >> 4) & 0xF) < 5 else "hint")
    if (h >> 12) == 0xC:
        L = (h >> 11) & 1
        r = (h >> 8) & 7
        wb = "!" if (not L or not (h >> r) & 1) else ""
        return I("ldmia" if L else "stmia", f"{R[r]}{wb}, {reglist(h & 0xFF)}")
    if (h >> 12) == 0xD:
        c = (h >> 8) & 0xF
        if c == 0xE:
            return I("udf", f"#{h & 0xFF}", kind="ret")
        if c == 0xF:
            return I("svc", f"#{h & 0xFF}")
        t = (addr + 4 + sx(h & 0xFF, 8) * 2) & 0xFFFFFFFF
        return I("b" + COND[c], f"0x{t:08x}", target=t, kind="cjump")
    if op5 == 0x1C:
        t = (addr + 4 + sx(h & 0x7FF, 11) * 2) & 0xFFFFFFFF
        return I("b", f"0x{t:08x}", target=t, kind="jump")
    return I(".short", f"0x{h:04x}  ; undefined")
