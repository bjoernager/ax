# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

ifneq ($(DEBUG),false)
ifneq ($(DEBUG),true)
$(error Invalid value \"$(DEBUG)\" for DEBUG)
endif
endif

# TOOLS

CC      := clang -target arm-none-eabi
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
	-mcpu=arm7tdmi \
	-mthumb \
	-mtune=arm7tdmi \
	-nostdlib \
	--std=c2x

ifeq ($(DEBUG),true)
CFLAGS := \
	$(CFLAGS) \
	-D__agbx_dbg
endif

# HEADERS

HDRS := \
	include/agbx/bs.h \
	include/agbx/gfx.h \
	include-private/agbx/priv.h

# BINARIES

OBJS := \
	source/bs/done.o \
	source/bs/get.o \
	source/bs/set.o \
	source/gfx/plot.o \
	source/gfx/setpx.o \
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
