# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

# TOOLS

AS      := arm-none-eabi-as
CC      := clang --target=arm-none-eabi
#CC      := arm-none-eabi-gcc
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy

# TOOL FLAGS

CFLAGS := \
	-I../agbx/include \
	-O3 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-mcpu=arm7tdmi \
	-nostdlib \
	-std=c2x

# BINARIES

OBJS := \
	demo.o

ROMHDR := hdr.o

IMG := demo.gba

# TARGETS

.PHONY: clean purge

$(IMG): $(ROMHDR) $(OBJS)
	$(LD) -L../agbx -Tldscript -odemo.elf -znoexecstack $(^) -lagbx
	$(OBJCOPY) -Obinary demo.elf $(@)
	agbsum -psi$(@)

clean:
	$(RM) $(OBJS) $(ROMHDR) demo.elf

purge: clean
	$(RM) $(IMG)

