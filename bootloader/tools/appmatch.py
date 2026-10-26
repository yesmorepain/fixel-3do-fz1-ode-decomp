import sys, struct
sys.path.insert(0, sys.argv[1]); from odeboot_matched import MATCHED
B, P = sys.argv[1], sys.argv[2]
boot = open(B + "/ram.bin", "rb").read(); BASE = 0x200000c0
app = open(P + "/original/update.ode", "rb").read(); ABASE = 0x10010000
def isbl(b, i):
    return i + 4 <= len(b) and (b[i+1] & 0xf8) == 0xf0 and (b[i+3] & 0xd0) == 0xd0
def norm(b):
    out = bytearray(b); i = 0
    while i < len(b) - 1:
        if isbl(b, i): out[i:i+4] = b"\0\0\0\0"; i += 4; continue
        i += 2
    for i in range(0, len(b) - 3, 4):   # literal-like words
        v = struct.unpack_from("<I", b, i)[0]
        if 0x10000000 <= v < 0x10100000 or 0x20000000 <= v < 0x20042000: out[i:i+4] = b"\0\0\0\0"
    return bytes(out)
appf = []
for l in open(P + "/functions.tsv").read().splitlines()[1:]:
    f = l.split("\t")
    try: a, s, n = int(f[0], 16), int(f[1]), f[2]
    except: continue
    if ABASE <= a < ABASE + len(app): appf.append((a, s, n))
for l in open(B + "/odeboot_funcs.tsv").read().splitlines()[1:]:
    a, s, n = l.split("\t"); a = int(a, 16); s = int(s)
    if a < BASE or a in MATCHED or s < 8: continue
    tb = norm(boot[a - BASE:a - BASE + s]); best = None
    for aa, ss, nn in appf:
        if abs(ss - s) > s // 8: continue
        ab = norm(app[aa - ABASE:aa - ABASE + s])
        sc = sum(x == y for x, y in zip(tb, ab)) / s
        if not best or sc > best[0]: best = (sc, nn, aa, ss)
    print("%08x %4d  %.2f %s (%08x,%d)" % (a, s, *best) if best else "%08x %4d  -" % (a, s))
