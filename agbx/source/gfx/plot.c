/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

agbx_i10 agbx_plot3(agbx_i8 const _x,agbx_i8 const _y,agbx_i10 const _col) {
	agbx_i10 const px = _y * 0xF0u + _x;
	__agbx_setpx2(0x600'0000u,px,_col)
	return px;
}

agbx_i10 agbx_plot4(agbx_i20 const _vaddr,agbx_i8 const _x,agbx_i8 const _y,agbx_i8 const _col) {
	agbx_i10 const px = _y * 0xF0u + _x;
	agbx_setpx1(_vaddr,px,_col);
	return px;
}

agbx_i10 agbx_plot5(agbx_i20 const _vaddr,agbx_i8 const _x,agbx_i8 const _y,agbx_i10 const _col) {
	agbx_i10 const px = _y * 0xF0u + _x;
	__agbx_setpx2(_vaddr,px,_col)
	return px;
}
