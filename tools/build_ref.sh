#!/bin/bash
# Builds the reference objects used by match_libs.py (toolchain, SDK, FatFs go in ~/opt).
# Then: ~/opt/venv/bin/python tools/match_libs.py piode2.elf functions.tsv tools/names_matched.py \
#         ~/opt/ref/build ~/opt/ref/libs/libc ~/opt/ref/libs/libm ~/opt/ref/libs/libgcc
set -e
O=~/opt; HERE=$(cd "$(dirname "$0")" && pwd); mkdir -p $O; cd $O
G=$O/gcc-arm-none-eabi-10.3-2021.10
[ -d $G ] || curl -sL "https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2" | tar xj
[ -d cmake-3.27.9-linux-x86_64 ] || curl -sL https://github.com/Kitware/CMake/releases/download/v3.27.9/cmake-3.27.9-linux-x86_64.tar.gz | tar xz
[ -d pico-sdk-1.3.0 ] || { git clone -q -b 1.3.0 https://github.com/raspberrypi/pico-sdk pico-sdk-1.3.0; git -C pico-sdk-1.3.0 submodule update --init -q; }
[ -d fatfs/ff14b ] || { mkdir -p fatfs/ff14b; curl -sL -o fatfs/ff14b.zip http://elm-chan.org/fsw/ff/arc/ff14b.zip; (cd fatfs/ff14b && unzip -q ../ff14b.zip); }
[ -d venv ] || { python3 -m venv venv; venv/bin/pip -q install pyelftools; }
mkdir -p ref; cp $HERE/ref/CMakeLists.txt $HERE/ref/tusb_config.h $HERE/ref/main.c ref/
rm -rf ref/ff; cp -r fatfs/ff14b/source ref/ff; cp $HERE/ref/ffconf.h ref/ff/
cp pico-sdk-1.3.0/external/pico_sdk_import.cmake ref/
export PATH=$G/bin:$O/cmake-3.27.9-linux-x86_64/bin:$PATH PICO_SDK_PATH=$O/pico-sdk-1.3.0
mkdir -p ref/build; (cd ref/build && cmake -DCMAKE_BUILD_TYPE=Debug -DPICO_BOARD=pico .. >/dev/null && make -j8 >/dev/null)
for l in libc libm; do mkdir -p ref/libs/$l; (cd ref/libs/$l && $G/bin/arm-none-eabi-ar x $G/arm-none-eabi/lib/thumb/v6-m/nofp/$l.a); done
mkdir -p ref/libs/libgcc; (cd ref/libs/libgcc && $G/bin/arm-none-eabi-ar x $G/lib/gcc/arm-none-eabi/10.3.1/thumb/v6-m/nofp/libgcc.a)
echo "reference ready in $O/ref"
