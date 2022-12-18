# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

# TOOLS

AS      := arm-none-eabi-as
CC      := clang --target=arm-none-eabi
#CC      := arm-none-eabi-gcc
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy

# TOOL FLAGS

CFLAGS :=                      \
	-I../agbx/include          \
	-Iinclude                  \
	-O3                        \
	-Wall                      \
	-Wextra                    \
	-Wpedantic                 \
	-Wno-gnu-binary-literal    \
	-Wno-gnu-empty-initializer \
	-fshort-enums              \
	-mcpu=arm7tdmi             \
	-nostdlib                  \
	-std=c2x

LDFLAGS :=      \
	-L../agbx   \
	-Tscript.ld

# BINARIES

OBJS :=              \
	source/chkkeys.o \
	source/chgcol.o  \
	source/initdat.o \
	source/initgfx.o \
	source/loop.o    \
	source/main.o

ROMHDR := hdr.o

LDLIBS :=  \
	-lagbx

IMG := demo.gba

# TARGETS

.PHONY: clean purge

$(IMG): $(ROMHDR) $(OBJS)
	$(LD) $(LDFLAGS) -odemo.elf -znoexecstack $(^) $(LDLIBS)
	$(OBJCOPY) -Obinary demo.elf $(@)
	agbsum -psi$(@)

clean:
	$(RM) $(OBJS) $(ROMHDR) demo.elf

purge: clean
	$(RM) $(IMG)

