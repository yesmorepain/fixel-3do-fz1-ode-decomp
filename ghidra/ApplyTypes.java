// Apply recovered types/signatures to piode2.
// @category piode2
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.data.FunctionDefinitionDataType;
import java.io.*;
import java.util.*;

public class ApplyTypes extends GhidraScript {

    Address A(long v) { return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(v); }

    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        CategoryPath cp = new CategoryPath("/piode2");

        // ---- cd_state_t @0x200050cc
        StructureDataType s = new StructureDataType(cp, "cd_state_t", 0);
        s.add(ByteDataType.dataType, "status", "bit4=CHECK_ERROR");
        s.add(ByteDataType.dataType, "error", "0x17 = unknown command");
        s.add(ByteDataType.dataType, "reply_len", "bytes in reply[]");
        s.add(new ArrayDataType(ByteDataType.dataType, 9, 1), "_unk3", null);
        s.add(new ArrayDataType(ByteDataType.dataType, 7, 1), "cmd", "command packet from FPGA");
        s.add(new ArrayDataType(ByteDataType.dataType, 61, 1), "reply", "[opcode echo, data..., status]");
        s.add(DWordDataType.dataType, "cmd_count", "incremented per dispatch");
        DataType sd = dtm.addDataType(s, DataTypeConflictHandler.REPLACE_HANDLER);
        Address st = A(0x200050ccL);
        createLabel(st, "cd_state", true, SourceType.USER_DEFINED);
        clearListing(st, st.add(sd.getLength() - 1));
        createData(st, sd);

        // ---- globals
        String[][] globals = {
            {"2000697c", "g_boot_device"}, {"2000488c", "g_cur_path"},
            {"20006978", "g_main_state"}, {"200075e8", "g_main_flags"},
        };
        for (String[] g : globals) createLabel(A(Long.parseLong(g[0], 16)), g[1], true, SourceType.USER_DEFINED);

        // ---- prototypes
        String[] sigs = {
            "int __wrap_printf(char *fmt, ...)",
            "int f_read(void *fp, void *buff, unsigned int btr, unsigned int *br)",
            "int f_write(void *fp, void *buff, unsigned int btw, unsigned int *bw)",
            "int f_lseek(void *fp, unsigned long long ofs)",
            "int f_readdir(void *dp, void *fno)",
            "int f_closedir(void *dp)",
            "int f_sync(void *fp)",
            "char * f_gets(char *buff, int len, void *fp)",
            "unsigned int strlen(char *s)",
            "int strcasecmp(char *a, char *b)",
            "int memcmp(void *a, void *b, unsigned int n)",
            "char * strstr(char *a, char *b)",
            "char * strncat(char *d, char *s, unsigned int n)",
            "int atoi(char *s)",
            "void sleep_us(unsigned long long us)",
            "void busy_wait_us_32(unsigned int us)",
            "void gpio_init(unsigned int gpio)",
            "void gpio_set_function(unsigned int gpio, int fn)",
            "void gpio_set_pulls(unsigned int gpio, int up, int down)",
            "void gpio_set_drive_strength(unsigned int gpio, int drive)",
            "void gpio_set_irq_enabled_with_callback(unsigned int gpio, unsigned int events, int enabled, void *cb)",
            "unsigned int spi_init(void *spi, unsigned int baud)",
            "unsigned int spi_set_baudrate(void *spi, unsigned int baud)",
            "int spi_write_read_blocking(void *spi, unsigned char *src, unsigned char *dst, unsigned int len)",
            "void multicore_fifo_push_blocking(unsigned int v)",
            "int multicore_fifo_push_timeout_us(unsigned int v, unsigned long long us)",
            "int multicore_fifo_pop_timeout_us(unsigned long long us, unsigned int *out)",
            "int tuh_msc_read10(unsigned char addr, unsigned char lun, void *buf, unsigned int lba, unsigned short n, void *cb)",
            "int tuh_msc_write10(unsigned char addr, unsigned char lun, void *buf, unsigned int lba, unsigned short n, void *cb)",
            "unsigned int tuh_msc_get_block_count(unsigned char addr, unsigned char lun)",
            "unsigned int tuh_msc_get_block_size(unsigned char addr, unsigned char lun)",
            "unsigned char xchg_spi(unsigned char b)",
            "int wait_ready(unsigned int ms)",
            "int send_cmd(unsigned char cmd, unsigned int arg)",
            "int image_read_sector(void *img, unsigned int lba, void *buf, unsigned int len)",
            "void lba_to_msf(unsigned int lba, unsigned char *msf)",
            "int msf_to_lba(unsigned char *msf)",
            "void fpga_send_data(unsigned char *buf, unsigned int len)",
            "int image_open(char *path)",
            "int button_register(void *btn, void *cb, unsigned int events)",
            "int puts(char *s)",
            "int snprintf(char *buf, unsigned int n, char *fmt, ...)",
            "void * memset(void *p, int c, unsigned int n)",
            "void * memcpy(void *d, void *s, unsigned int n)",
            "int f_mount(void *fs, char *path, unsigned char opt)",
            "int f_open(void *fp, char *path, unsigned char mode)",
            "int f_close(void *fp)",
            "int f_opendir(void *dp, char *path)",
            "int f_chdrive(char *path)",
            "int f_chdir(char *path)",
            "int spi_write_blocking(void *spi, unsigned char *src, unsigned int len)",
            "int spi_read_blocking(void *spi, unsigned char tx, unsigned char *dst, unsigned int len)",
            "void watchdog_enable(unsigned int delay_ms, int pause_on_debug)",
            "void multicore_launch_core1(void *entry)",
            "void cd_send_reply(unsigned char *buf, unsigned int len)",
            "int cd_recv_command(unsigned char *cmd)",
            "void cd_cmd_dispatch(void)",
            "int ode_stage_firmware_update(void)",
            "void __assert_func(char *file, int line, char *func, char *expr)",
            "void panic(char *fmt, ...)",
        };
        FunctionManager fm = currentProgram.getFunctionManager();
        Map<String, Function> byName = new HashMap<>();
        for (Function f : fm.getFunctions(true)) byName.put(f.getName(), f);
        int ok = 0;
        for (String sig : sigs) {
            String nm = sig.substring(0, sig.indexOf('(')).trim();
            nm = nm.substring(nm.lastIndexOf(' ') + 1).replace("*", "");
            Function f = byName.get(nm);
            if (f == null) { println("missing fn " + nm); continue; }
            FunctionDefinitionDataType fd = CParserUtils.parseSignature((ghidra.app.services.DataTypeManagerService) null, currentProgram, sig, true);
            if (fd == null) { println("parse fail " + sig); continue; }
            ApplyFunctionSignatureCmd cmd = new ApplyFunctionSignatureCmd(f.getEntryPoint(), fd, SourceType.USER_DEFINED);
            if (cmd.applyTo(currentProgram, monitor)) ok++; else println("apply fail " + nm + ": " + cmd.getStatusMsg());
        }
        // cmd_* handlers: void(void)
        for (Function f : fm.getFunctions(true)) {
            if (f.getName().startsWith("cmd_")) {
                FunctionDefinitionDataType fd = CParserUtils.parseSignature((ghidra.app.services.DataTypeManagerService) null, currentProgram, "void " + f.getName() + "(void)", true);
                new ApplyFunctionSignatureCmd(f.getEntryPoint(), fd, SourceType.USER_DEFINED).applyTo(currentProgram, monitor);
                ok++;
            }
        }
        println("signatures applied: " + ok);
    }
}
