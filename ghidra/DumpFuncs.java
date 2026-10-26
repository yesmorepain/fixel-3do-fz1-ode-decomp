// Write a functions.tsv-style list (addr, size, name) of every function (arg: output path).
// @category piode2
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpFuncs extends GhidraScript {
    @Override
    public void run() throws Exception {
        try (PrintWriter w = new PrintWriter(new FileWriter(getScriptArgs()[0]))) {
            w.println("addr\tsize\tname");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true))
                w.printf("%08x\t%d\t%s%n", f.getEntryPoint().getOffset(), f.getBody().getNumAddresses(), f.getName());
        }
    }
}
