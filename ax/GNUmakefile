# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

# TOOLS

AS      := arm-none-eabi-as
CC      := arm-none-eabi-gcc
#CC      := clang --target=arm-none-eabi
CXX     := arm-none-eabi-g++ 
#CXX     := clang++ --target=arm-none-eabi
OBJCOPY := arm-none-eabi-objcopy

# TOOL FLAGS

CFLAGS := \
	-Iinclude            \
	-Iinclude-private    \
	-Oz                  \
	-Wall                \
	-Wextra              \
	-Wpadded             \
	-Wpedantic           \
	-ffreestanding       \
	-fno-strict-aliasing \
	-fshort-enums        \
	-mabi=aapcs          \
	-mcpu=arm7tdmi       \
	-mthumb              \
	-mtune=arm7tdmi      \
	-nostdlib            \
	-pipe                \
	-std=c2x

CXXFLAGS := \
	-Iinclude            \
	-Iinclude-private    \
	-Ofast               \
	-Wall                \
	-Wextra              \
	-Wpedantic           \
	-ffreestanding       \
	-fno-exceptions      \
	-fno-strict-aliasing \
	-fshort-enums        \
	-mabi=aapcs          \
	-mcpu=arm7tdmi       \
	-mthumb              \
	-mtune=arm7tdmi      \
	-nostdlib            \
	-pipe                \
	-std=c++2b

# HEADERS

HDRS := \
	include/ax/algo.h         \
	include/ax/bs.h           \
	include/ax/gfx.h          \
	include/ax/key.h          \
	include/float.h           \
	include/iso646.h          \
	include/limits.h          \
	include/stdalign.h        \
	include/stdarg.h          \
	include/stdbit.h          \
	include/stdbool.h         \
	include/stddef.h          \
	include/stdint.h          \
	include/stdlib.h          \
	include/stdnoreturn.h     \
	include/string.h          \
	include-private/ax/priv.h

# ARTEFACTS

OBJS := \
	source/algo/cp.o                \
	source/algo/cp8.o               \
	source/algo/divmod.o            \
	source/algo/fill.o              \
	source/bs/done.o                \
	source/bs/get.o                 \
	source/bs/set.o                 \
	source/bs/trap.o                \
	source/gfx/blnk.o               \
	source/gfx/clrscrn.o            \
	source/gfx/flip.o               \
	source/gfx/getvbnk.o            \
	source/gfx/plot.o               \
	source/gfx/plottex.o            \
	source/gfx/rd.o                 \
	source/gfx/rec.o                \
	source/gfx/setcol.o             \
	source/gfx/vsync.o              \
	source/key/getkeymap.o          \
	source/priv/init.o              \
	source/setjmp/longjmp.o         \
	source/setjmp/setjmp.o          \
	source/stdlib/memalignement.o   \
	source/string/memcpy.o          \
	source/string/memmove.o         \
	source/string/memset.o          \
	source/string/memset_explicit.o \
	source/string/strlen.o

LIB := libax.a

# TARGETS

.PHONY: clean purge

$(LIB): $(OBJS)
	$(AR) r $(@) $(^)

$(OBJS): $(HDRS)

clean:
	$(RM) $(OBJS)

purge: clean
	$(RM) $(LIB)
