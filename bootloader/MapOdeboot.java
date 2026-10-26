// Pre-script: map odeboot's copy_to_ram image (flash 0x10000308.. -> RAM 0x200000c0..0x2000dfcc), add bss,
// and seed functions at every Thumb pointer found in the image.
// @category odeboot
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.nio.file.*;

public class MapOdeboot extends GhidraScript {
    @Override
    public void run() throws Exception {
        byte[] img = Files.readAllBytes(Paths.get(getScriptArgs()[0]));
        int src = 0x308, len = 0x2000dfcc - 0x200000c0;
        byte[] ram = java.util.Arrays.copyOfRange(img, src, src + len);
        Memory m = currentProgram.getMemory();
        Address ra = toAddr(0x200000c0L);
        MemoryBlock b = m.createInitializedBlock("ram_text_data", ra, new ByteArrayInputStream(ram), len, monitor, false);
        b.setRead(true); b.setWrite(true); b.setExecute(true);
        MemoryBlock bss = m.createUninitializedBlock("bss", toAddr(0x2000dfccL), 0x20042000L - 0x2000dfccL, false);
        bss.setRead(true); bss.setWrite(true);
        m.createUninitializedBlock("periph_apb", toAddr(0x40000000L), 0x70000, false);
        m.createUninitializedBlock("sio", toAddr(0xd0000000L), 0x200, false);
        m.createUninitializedBlock("ppb", toAddr(0xe0000000L), 0x10000, false);
        // seed: odd pointers into RAM text
        int n = 0;
        for (int o = 0; o + 4 <= len; o += 4) {
            long v = ((ram[o] & 0xffL) | (ram[o+1] & 0xffL) << 8 | (ram[o+2] & 0xffL) << 16 | (ram[o+3] & 0xffL) << 24);
            if ((v & 1) == 1 && v > 0x200000c0L && v < 0x2000bcc0L) {
                Address a = toAddr(v - 1);
                currentProgram.getProgramContext().setValue(currentProgram.getProgramContext().getRegister("TMode"), a, a, java.math.BigInteger.ONE);
                addEntryPoint(a); n++;
            }
        }
        long[] fl = {0x100001f6L};
        for (long f : fl) {
            Address a = toAddr(f);
            currentProgram.getProgramContext().setValue(currentProgram.getProgramContext().getRegister("TMode"), a, a, java.math.BigInteger.ONE);
            addEntryPoint(a);
        }
        println("mapped; seeded " + n);
    }
}
