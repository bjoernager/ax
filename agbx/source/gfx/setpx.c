/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

void agbx_setpx1(agbx_i20 const _vaddr,agbx_i10 const _px,agbx_i8 const _col) {
	/* We can only write halfwords to VRAM, so we need to load the adjacent pixel value and combine it into a halfword. */
	bool     const odd    = _px & 0x1u;
	agbx_i20       addr   = _vaddr + _px - odd;
	agbx_i10       precol = __agbx_get10(addr);
	agbx_i10       col    = _col;
	if (odd) {
		precol &=  0b11111111u;
		col    <<= 0x8u;
	}
	else {
		precol &= 0b1111111100000000u;
	}
	agbx_i10 const newcol = precol | col;
	__agbx_set10(addr,newcol);
}

void agbx_setpx2(agbx_i20 const _vaddr,agbx_i10 const _px,agbx_i10 const _col) {
	agbx_i20 const addr = _vaddr + _px;
	__agbx_set10(addr,_col);
}
