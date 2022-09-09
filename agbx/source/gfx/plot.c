/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

agbx_i10 agbx_plot3(agbx_i8 const _x,agbx_i8 const _y,agbx_i10 const _col) {
#if defined(__agbx_dbg)
	if (_x >= 0xF0u || _y >= 0xA0u) {agbx_done(agbx_err_pos2big);}
#endif
	agbx_i10 const px = _y * 0xF0u + _x;
	__agbx_setpx2(px,_col)
	return px;
}

agbx_i10 agbx_plot4(agbx_i8 const _x,agbx_i8 const _y,agbx_i8 const _col) {
#if defined(__agbx_dbg)
	if (_x >= 0xF0u || _y >= 0xA0u) {agbx_done(agbx_err_pos2big);}
#endif
	agbx_i10 const px = _y * 0xF0u + _x;
	__agbx_setpx1(px,_col)
	return px;
}

agbx_i10 agbx_plot5(agbx_i8 const _x,agbx_i8 const _y,agbx_i10 const _col) {
#if defined(__agbx_dbg)
	if (_x >= 0xA0u || _y >= 0x80u) {agbx_done(agbx_err_pos2big);}
#endif
	agbx_i10 const px = _y * 0xA0u + _x;
	__agbx_setpx2(px,_col)
	return px;
}
