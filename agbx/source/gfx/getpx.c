/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

agbx_i8 agbx_getpx1(agbx_i20 const _vaddr,agbx_i10 const _px) {
	agbx_i20 const addr = _vaddr + _px;
	return __agbx_get8(addr);
}

agbx_i10 agbx_getpx2(agbx_i20 const _vaddr,agbx_i10 const _px) {
	agbx_i20 const addr = _vaddr + _px * 0x2u;
	return __agbx_get8(addr);
}
