// Rename functions to match ghidra_symbols.txt ("name hexaddr f" lines; arg: path).
// @category piode2
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;

public class SyncNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            String[] p = line.trim().split("\\s+");
            if (p.length < 3 || !p[2].equals("f")) continue;
            Function f = getFunctionAt(toAddr(Long.parseLong(p[1], 16)));
            if (f == null || f.getName().equals(p[0])) continue;
            println(f.getName() + " -> " + p[0]);
            f.setName(p[0], SourceType.USER_DEFINED);
            n++;
        }
        println("renamed " + n);
    }
}
