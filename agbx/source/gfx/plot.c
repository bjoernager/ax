/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

void ax_plot1(ax_i02 const _vaddr,ax_i01 const _px,ax_i8 const _col) {
	/* We can only write halfwords to VRAM, so we need to load the adjacent pixel value and combine it into a halfword. */
	bool   const odd    = _px & 0x1u;
	ax_i02       addr   = _vaddr + _px - odd;
	ax_i01       precol = __ax_get10(addr);
	ax_i01       col    = _col;
	if (odd) {
		precol &=  0b11111111u;
		col    <<= 0x8u;
	}
	else {
		precol &= 0b1111111100000000u;
	}
	ax_i01 const newcol = precol | col;
	__ax_set10(addr,newcol);
}

void ax_plot2(ax_i02 const _vaddr,ax_i01 const _px,ax_i01 const _col) {
	ax_i02 const addr = _vaddr + _px;
	__ax_set10(addr,_col);
}
