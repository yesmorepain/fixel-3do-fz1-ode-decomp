#!/usr/bin/env python3
"""odepatch - patch / extend the piode2 v0.1 (3DO FZ-1 ODE) application image.

The .ode file is a raw RP2040 flash image of the application, linked at 0x10010000
(the device's own bootloader occupies 0x10000000-0x1000FFFF and is NOT in this file).

  python3 odepatch.py info   update.ode
  python3 odepatch.py apply  update.ode patches.json  out.ode
  python3 odepatch.py selftest update.ode

patches.json:
{
  "append": [ {"file": "build/patch.bin", "at": "0x10033a00"} ],     # new code/rodata
  "bytes":  [ {"addr": "0x10031780", "hex": "2f73642f..."} ],         # raw overwrite
  "bl":     [ {"site": "0x10017828", "target": "0x10033a01"} ],       # retarget a BL
  "u32":    [ {"addr": "0x...", "value": "0x..."} ],
  "opcode": [ {"op": "0xd2", "handler": "0x10033a01"} ]               # new 3DO CD command
}
"""
import sys, json, struct, binascii

BASE = 0x10010000
BINARY_END = 0x1003390C           # end of original image (binary_info binary_end)
APPEND_DEFAULT = 0x10033A00       # first free, 256-byte aligned address after the image
DISPATCH_TABLE = 0x100311B8       # 241 x u32, indexed by command byte (0x00..0xF0)
DISPATCH_DEFAULT = 0x1001696A     # "illegal command" case (table stores even addrs: mov pc clears bit0)
DISPATCH_TAIL = 0x10016899        # common tail: appends status byte, cd_send_reply()
N_OPCODES = 241


def u32(b, a):
    return struct.unpack_from("<I", b, a - BASE)[0]


def put(b, a, data):
    o = a - BASE
    if o < 0:
        raise SystemExit(f"address 0x{a:08x} below image base")
    if o + len(data) > len(b):
        b.extend(b"\0" * (o + len(data) - len(b)))
    b[o:o + len(data)] = data


def enc_bl(src, dst):
    """Thumb BL from src to dst (thumb bit ignored)."""
    off = (dst & ~1) - (src + 4)
    if not -(1 << 24) <= off < (1 << 24):
        raise SystemExit("BL out of range")
    S = (off >> 24) & 1
    I1 = (off >> 23) & 1
    I2 = (off >> 22) & 1
    J1 = (1 - I1) ^ S
    J2 = (1 - I2) ^ S
    h1 = 0xF000 | (S << 10) | ((off >> 12) & 0x3FF)
    h2 = 0xD000 | (J1 << 13) | (J2 << 11) | ((off >> 1) & 0x7FF)
    return struct.pack("<HH", h1, h2)


def trampoline(at, handler):
    """Case block for the dispatcher:  bl handler ; ldr r3,=TAIL ; bx r3 ; .word TAIL
    Mirrors what the original case blocks do (bl handler ; b common_tail)."""
    code = enc_bl(at, handler)
    code += struct.pack("<H", 0x4B00)        # ldr r3, [pc, #0]  (literal at at+8)
    code += struct.pack("<H", 0x4718)        # bx  r3
    code += struct.pack("<I", DISPATCH_TAIL)
    assert len(code) == 12
    return code


def boot2_crc_ok(b):
    # RP2040 boot2: CRC32/MPEG-2 (poly 0x04C11DB7, init 0xFFFFFFFF, no reflect, no xorout) of 252 bytes
    crc = 0xFFFFFFFF
    for byte in b[:252]:
        crc ^= byte << 24
        for _ in range(8):
            crc = ((crc << 1) ^ 0x04C11DB7) & 0xFFFFFFFF if crc & 0x80000000 else (crc << 1) & 0xFFFFFFFF
    return crc == struct.unpack_from("<I", b, 252)[0]


def free_opcodes(b):
    return [op for op in range(N_OPCODES) if u32(b, DISPATCH_TABLE + 4 * op) == DISPATCH_DEFAULT]


def info(b):
    print(f"size            {len(b)} bytes, maps 0x{BASE:08x}..0x{BASE + len(b):08x}")
    print(f"boot2 CRC       {'OK' if boot2_crc_ok(b) else 'BAD'}")
    print(f"initial SP/PC   0x{u32(b, BASE + 0x100):08x} / 0x{u32(b, BASE + 0x104):08x}")
    fo = free_opcodes(b)
    print(f"free opcodes    {len(fo)}: " + " ".join(f"{o:02x}" for o in fo))
    used = [o for o in range(N_OPCODES) if o not in fo]
    print(f"used opcodes    " + " ".join(f"{o:02x}" for o in used))


def apply(b, p):
    tramp_at = None
    for e in p.get("append", []):
        at = int(e.get("at", hex(APPEND_DEFAULT)), 16)
        if at < BINARY_END:
            raise SystemExit("append address overlaps original image")
        data = open(e["file"], "rb").read()
        put(b, at, data)
        print(f"append  {e['file']} -> 0x{at:08x} ({len(data)} bytes)")
    for e in p.get("bytes", []):
        put(b, int(e["addr"], 16), binascii.unhexlify(e["hex"]))
        print(f"bytes   0x{int(e['addr'], 16):08x}")
    for e in p.get("u32", []):
        put(b, int(e["addr"], 16), struct.pack("<I", int(e["value"], 16)))
    for e in p.get("bl", []):
        s = int(e["site"], 16)
        h1 = struct.unpack_from("<H", b, s - BASE)[0]
        if (h1 >> 11) != 0x1E:
            raise SystemExit(f"no BL at 0x{s:08x}")
        put(b, s, enc_bl(s, int(e["target"], 16)))
        print(f"bl      0x{s:08x} -> 0x{int(e['target'], 16):08x}")
    for e in p.get("opcode", []):
        op = int(e["op"], 16)
        if op >= N_OPCODES:
            raise SystemExit("opcode must be <= 0xf0 (dispatcher bound check)")
        if op not in free_opcodes(b) and not e.get("replace"):
            raise SystemExit(f"opcode 0x{op:02x} already handled; set \"replace\": true to override")
        if tramp_at is None:
            # trampolines live at the very end, 16-byte aligned
            tramp_at = (BASE + len(b) + 15) & ~15
        code = trampoline(tramp_at, int(e["handler"], 16))
        put(b, tramp_at, code)
        put(b, DISPATCH_TABLE + 4 * op, struct.pack("<I", tramp_at))
        print(f"opcode  0x{op:02x} -> trampoline 0x{tramp_at:08x} -> handler {e['handler']}")
        tramp_at += 16
    if not boot2_crc_ok(b):
        raise SystemExit("boot2 CRC broken - do not touch the first 256 bytes")
    return b


def selftest(b):
    import os
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from thumb import decode
    assert boot2_crc_ok(b), "boot2 crc"
    # BL encoder must reproduce every BL in the original image
    n = 0
    o = 0x100
    while o < 0xF37A:
        h1, h2 = struct.unpack_from("<HH", b, o)
        if (h1 >> 11) == 0x1E and (h2 >> 14) == 3 and (h2 >> 12) & 1:
            i = decode(b, o, BASE + o)
            assert enc_bl(BASE + o, i.target) == bytes(b[o:o + 4]), hex(BASE + o)
            n += 1
            o += 4
        else:
            o += 2
    print(f"BL encoder reproduces all {n} original BLs")
    t = bytearray(b)
    apply(t, {"opcode": [{"op": "0xd2", "handler": "0x10016369"}]})   # route 0xd2 -> cmd_c3_clear_playlist
    tr = u32(t, DISPATCH_TABLE + 4 * 0xD2)
    seg = bytes(t[tr - BASE:tr - BASE + 12])
    a = 0
    while a < 8:
        i = decode(seg, a, tr + a)
        print(f"  {tr + a:08x}  {i.text()}")
        a += i.size
    assert decode(seg, 0, tr).target == 0x10016368
    assert struct.unpack_from("<I", seg, 8)[0] == DISPATCH_TAIL
    diff = [i for i in range(len(b)) if b[i] != t[i]]
    assert all(DISPATCH_TABLE - BASE + 4 * 0xD2 <= i < DISPATCH_TABLE - BASE + 4 * 0xD2 + 4 for i in diff), diff
    print(f"opcode hook OK: only the table entry changed inside the original image; {len(t) - len(b)} bytes appended")


if __name__ == "__main__":
    cmd, img = sys.argv[1], bytearray(open(sys.argv[2], "rb").read())
    if cmd == "info":
        info(img)
    elif cmd == "apply":
        out = apply(img, json.load(open(sys.argv[3])))
        open(sys.argv[4], "wb").write(out)
        print(f"wrote {sys.argv[4]} ({len(out)} bytes)")
    elif cmd == "selftest":
        selftest(img)
    else:
        print(__doc__)
