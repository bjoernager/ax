/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

ax_i01 ax_rd3(ax_i8 const _x,ax_i8 const _y) {
	ax_i01 const px = _y * 0xF0u + _x;
	return ax_getpx2(0x600'0000u,px);
}

ax_i8 ax_rd4(ax_i02 const _vaddr,ax_i8 const _x,ax_i8 const _y) {
	ax_i01 const px = _y * 0xF0u + _x;
	return ax_getpx1(_vaddr,px);
}

ax_i01 ax_rd5(ax_i02 const _vaddr,ax_i8 const _x,ax_i8 const _y) {
	ax_i01 const px = _y * 0xA0u + _x;
	return ax_getpx2(_vaddr,px);
}
