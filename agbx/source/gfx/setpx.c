/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

void agbx_setpx1(agbx_i10 const _px,agbx_i8 const  _col) {
#if defined(__agbx_dbg)
	agbx_i10 const dispcnt = agbx_get10(0x4000000u);
	agbx_i8 const  md      = dispcnt & 0x7u;
	if (md == 0x3u || md == 0x5u) {agbx_done(agbx_err_badmd);}
	if (_px >= 0x9600u)           {agbx_done(agbx_err_px2big);}
#endif
	__agbx_setpx1(_px,_col)
}

void agbx_setpx2(agbx_i10 const _px,agbx_i10 const _col) {
#if defined(__agbx_dbg)
	agbx_i10 const dispcnt = agbx_get10(0x4000000u);
	agbx_i8 const  md      = dispcnt & 0x7u;
	if (md == 0x4u) {agbx_done(agbx_err_badmd);}
	if (md == 0x5u) {
		if (_px >= 0x5000u) {agbx_done(agbx_err_px2big);}
	}
	else {
		if (md != 0x3u)     {agbx_done(agbx_err_badmd);}
		if (_px >= 0x9600u) {agbx_done(agbx_err_px2big);}
	}
#endif
	__agbx_setpx2(_px,_col)
}
