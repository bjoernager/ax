/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

void agbx_clrscrn3(agbx_i10 const _col) {
	agbx_i20 const val = _col | _col << 0x8u | _col << 0x10u | _col << 0x18u;
	for (agbx_i20 addr = 0x400'0000u;addr != 0x401'2C00u;addr += 0x4u) {agbx_set20(addr,val);}
}

void agbx_clrscrn4(agbx_i20 const _vaddr,agbx_i8 const _col) {
	agbx_i20 const val = _col | _col << 0x8u | _col << 0x10u | _col << 0x18u;
	for (agbx_i20 addr = _vaddr;addr != _vaddr + 0x9600u;addr += 0x4u) {agbx_set20(addr,val);}
}

void agbx_clrscrn5(agbx_i20 const _vaddr,agbx_i10 const _col) {
	agbx_i20 const val = _col | _col << 0x10u;
	for (agbx_i20 addr = _vaddr;addr != _vaddr + 0xA000u;addr += 0x4u) {agbx_set20(addr,val);}
}
