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
	/* Display the barcode-like error message: */
	ax_set10(0x400'0000u,0x404u);
	ax_set10(0x500'0000u,0x0u);
	ax_set10(0x500'0002u,0b11111u);
	ax_i8 err[0xBu];
	for (ax_i8 pos = 0x0u;pos != 0x8u;++pos) {err[pos] = (ax_i8)_err >> pos & 0x1u;}
	err[0x8u] = 0x0u;
	err[0x9u] = 0x1u;
	err[0xAu] = 0x0u;
	for (ax_i01 pos = 0x0u;pos != 0x9600u;pos += 0xF0u) {
		ax_setpx1(0x600'0000u,pos,       err[0x0u]);
		ax_setpx1(0x600'0000u,pos + 0x1u,err[0x1u]);
		ax_setpx1(0x600'0000u,pos + 0x2u,err[0x2u]);
		ax_setpx1(0x600'0000u,pos + 0x3u,err[0x3u]);
		ax_setpx1(0x600'0000u,pos + 0x4u,err[0x4u]);
		ax_setpx1(0x600'0000u,pos + 0x5u,err[0x5u]);
		ax_setpx1(0x600'0000u,pos + 0x6u,err[0x6u]);
		ax_setpx1(0x600'0000u,pos + 0x7u,err[0x7u]);
		ax_setpx1(0x600'0000u,pos + 0x8u,err[0x8u]);
		ax_setpx1(0x600'0000u,pos + 0x9u,err[0x9u]);
		ax_setpx1(0x600'0000u,pos + 0xAu,err[0xAu]);
	}
	__asm__ (
		"svc 0x2\n"
	);
	for (;;) {}
}
