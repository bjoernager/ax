/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

void agbx_done(agbx_err const _err) {
	if (_err == agbx_err_ok) {
		__asm__ (
			"swi 0x3\n"
		);
		__builtin_unreachable();
	}
	/* Display the barcode-like error message: */
	agbx_set10(0x4000000u,0x403u);
	agbx_i10 err[0x8u];
	for (agbx_i8 pos = 0x0u;pos != 0x8u;++pos) {err[pos] = (agbx_i8)_err >> pos & 0x1u ? 0x19u : 0x0u;}
	for (agbx_i10 pos = 0x0u;pos != 0x9600u;pos += 0xF0u) {
		agbx_setpx2(pos,       err[0x0u]);
		agbx_setpx2(pos + 0x1u,err[0x1u]);
		agbx_setpx2(pos + 0x2u,err[0x2u]);
		agbx_setpx2(pos + 0x3u,err[0x3u]);
		agbx_setpx2(pos + 0x4u,err[0x4u]);
		agbx_setpx2(pos + 0x5u,err[0x5u]);
		agbx_setpx2(pos + 0x6u,err[0x6u]);
		agbx_setpx2(pos + 0x7u,err[0x7u]);
		agbx_setpx2(pos + 0x8u,0x0u);
		agbx_setpx2(pos + 0x9u,0x19u);
	}
	__asm__ (
		"swi 0x2\n"
	);
	for (;;) {}
}
