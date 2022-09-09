# Copyright 2022 Gabriel Jensen.
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

ifeq ($(DEBUG),)
DEBUG := false
endif

.PHONY: agbx clean demo install purge

agbx:
	$(MAKE) -C$(@) DEBUG=$(DEBUG)

demo: agbx
	$(MAKE) -C$(@)

install: agbx
	mkdir -pvm755 "$(HDRDIR)/agbx"
	mkdir -pvm755 "$(LIBDIR)"
	install -vm644 "agbx/include/agbx/"*".h" "$(HDRDIR)/agbx"
	install -vm755 "agbx/libagbx.a" "$(LIBDIR)"

clean:
	$(MAKE) -Cagbx clean
	$(MAKE) -Cdemo clean

purge:
	$(MAKE) -Cagbx purge
	$(MAKE) -Cdemo purge

