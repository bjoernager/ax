/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

agbx_i10 agbx_rd3(agbx_i8 const _x,agbx_i8 const _y) {
	agbx_i10 const px = _y * 0xF0u + _x;
	return agbx_getpx2(0x600'0000u,px);
}

agbx_i8 agbx_rd4(agbx_i20 const _vaddr,agbx_i8 const _x,agbx_i8 const _y) {
	agbx_i10 const px = _y * 0xF0u + _x;
	return agbx_getpx1(_vaddr,px);
}

agbx_i10 agbx_rd5(agbx_i20 const _vaddr,agbx_i8 const _x,agbx_i8 const _y) {
	agbx_i10 const px = _y * 0xA0u + _x;
	return agbx_getpx2(_vaddr,px);
}
