/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

void agbx_setpx1(agbx_i20 const _vaddr,agbx_i10 const _px,agbx_i8 const _col) {
	/* We can only write halfwords to VRAM, so we load the adjacent pixel value and combine it into a halfword. */
	agbx_i20 const addr = _vaddr + _px - (_px & 0x1u) * 0x1u;
	agbx_i10 col;
	if (_px & 0x1u) {col = (agbx_i10)agbx_get8(addr) | (agbx_i10)_col << 0x8u;}
	else            {col = (agbx_i10)agbx_get8(addr + 0x1u) << 0x8u | (agbx_i10)_col;}
	__agbx_set10(addr,col);
}

void agbx_setpx2(agbx_i20 const _vaddr,agbx_i10 const _px,agbx_i10 const _col) {
	__agbx_setpx2(_vaddr,_px,_col)
}
