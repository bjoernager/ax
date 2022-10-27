/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

void ax_plot3(ax_i8 const _x,ax_i8 const _y,ax_i10 const _col) {
	ax_i10 const px = _y * 0xF0u + _x;
	__ax_setpx2(0x600'0000u,px,_col)
}

void ax_plot4(ax_i20 const _vaddr,ax_i8 const _x,ax_i8 const _y,ax_i8 const _col) {
	ax_i10 const px = _y * 0xF0u + _x;
	ax_setpx1(_vaddr,px,_col);
}

void ax_plot5(ax_i20 const _vaddr,ax_i8 const _x,ax_i8 const _y,ax_i10 const _col) {
	ax_i10 const px = _y * 0xA0u + _x;
	__ax_setpx2(_vaddr,px,_col)
}
