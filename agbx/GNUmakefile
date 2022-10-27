# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

# TOOLS

AS      := arm-none-eabi-as
CC      := clang --target=arm-none-eabi
#CC      := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy

# TOOL FLAGS

CFLAGS := \
	-Iinclude \
	-Iinclude-private \
	-Ofast \
	-Wall \
	-Wextra \
	-Wpedantic \
	-ffreestanding \
	-fno-builtin \
	-fno-strict-aliasing \
	-mcpu=arm7tdmi \
	-mthumb \
	-mtune=arm7tdmi \
	-nostdlib \
	-std=c2x

# HEADERS

HDRS := \
	include/agbx/bs.h \
	include/agbx/gfx.h \
	include-private/agbx/priv.h

# BINARIES

OBJS := \
	source/algo/cp.o \
	source/bs/done.o \
	source/bs/get.o \
	source/bs/set.o \
	source/gfx/clrscrn.o \
	source/gfx/flip.o \
	source/gfx/getpx.o \
	source/gfx/getvbnk.o \
	source/gfx/plot.o \
	source/gfx/rd.o \
	source/gfx/setpx.o \
	source/gfx/vsync.o \
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
