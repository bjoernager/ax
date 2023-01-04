# Copyright 2022-2023 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

# TOOLS

AS      := arm-none-eabi-as
CC      := arm-none-eabi-gcc
#CC      := clang --target=arm-none-eabi
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy

# TOOL FLAGS

CFLAGS := \
	-I../ax/include \
	-Iinclude       \
	-Oz             \
	-Wall           \
	-Wextra         \
	-Wpedantic      \
	-ffreestanding  \
	-fshort-enums   \
	-mcpu=arm7tdmi  \
	-mthumb         \
	-nostdlib       \
	-std=c2x

LDFLAGS := \
	-L../ax       \
	-Tscript.ld   \
	-znoexecstack

# BINARIES

OBJS := \
	source/chkkeys.o   \
	source/chgcol.o    \
	source/initdat.o   \
	source/initgfx.o   \
	source/loop.o      \
	source/setcolbdr.o \
	source/start.o

ROMHDR := hdr.o

LDLIBS := \
	-lax

IMG := demo.gba

# TARGETS

.PHONY: clean purge

$(IMG): $(ROMHDR) $(OBJS)
	$(LD) $(LDFLAGS) -odemo.elf $(^) $(LDLIBS)
	$(OBJCOPY) -Obinary demo.elf $(@)
	agbsum -psi$(@)

clean:
	$(RM) $(OBJS) $(ROMHDR) demo.elf

purge: clean
	$(RM) $(IMG)

