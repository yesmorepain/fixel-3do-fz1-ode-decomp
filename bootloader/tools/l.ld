SECTIONS { .flash 0x10000000 : { flash.o(.flash) } .ramimg 0x200000c0 : { ram.o(.ramimg) } }
