/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

void ax_done(ax_err const _err) {
	if (_err == ax_err_ok) {
		__asm__ (
			"svc 0x3\n"
		);
		__builtin_unreachable();
	}
	__asm__ (
		"svc 0x2\n"
	);
	for (;;) {}
}
