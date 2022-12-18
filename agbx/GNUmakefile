# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

# TOOLS

AS      := arm-none-eabi-as
#CC      := arm-none-eabi-gcc -Dbool="_Bool" -Dfalse="((_Bool)+0x0u)" -Dfalse="((_Bool)+0x0u)"
CC      := clang --target=arm-none-eabi
#CXX      := arm-none-eabi-g++ 
CXX     := clang++ --target=arm-none-eabi
OBJCOPY := arm-none-eabi-objcopy

# TOOL FLAGS

CFLAGS :=                      \
	-Iinclude                  \
	-Iinclude-private          \
	-Ofast                     \
	-Wall                      \
	-Wextra                    \
	-Wpedantic                 \
	-Wno-gnu-binary-literal    \
	-Wno-gnu-empty-initializer \
	-ffreestanding             \
	-fno-builtin               \
	-fno-strict-aliasing       \
	-fshort-enums              \
	-mcpu=arm7tdmi             \
	-mthumb                    \
	-mtune=arm7tdmi            \
	-nostdlib                  \
	-std=c2x

CXXFLAGS :=               \
	-Iinclude            \
	-Iinclude-private    \
	-Ofast               \
	-Wall                \
	-Wextra              \
	-Wpedantic           \
	-ffreestanding       \
	-fno-builtin         \
	-fno-exceptions      \
	-fno-strict-aliasing \
	-fshort-enums        \
	-mcpu=arm7tdmi       \
	-mthumb              \
	-mtune=arm7tdmi      \
	-nostdlib            \
	-std=c++2b

# HEADERS

HDRS :=                       \
	include/ax/algo.h         \
	include/ax/bs.h           \
	include/ax/gfx.h          \
	include/ax/key.h          \
	include-private/ax/priv.h

# BINARIES

OBJS :=                    \
	source/algo/cp.o       \
	source/bs/done.o       \
	source/bs/get.o        \
	source/bs/set.o        \
	source/gfx/clrscrn.o   \
	source/gfx/flip.o      \
	source/gfx/getvbnk.o   \
	source/gfx/plot.o      \
	source/gfx/plottex.o   \
	source/gfx/rd.o        \
	source/gfx/vsync.o     \
	source/key/getkeymap.o \
	source/priv/init.o

LIB := libagbx.a

# TARGETS

.PHONY: clean purge

$(LIB): $(OBJS)
	$(AR) r $(@) $(^)

$(OBJS): $(HDRS)

clean:
	$(RM) $(OBJS)

purge: clean
	$(RM) $(LIB)
