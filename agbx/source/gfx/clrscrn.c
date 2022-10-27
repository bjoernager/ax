/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

void ax_clrscrn3(ax_i10 const _col) {
	ax_i20 const val = _col | _col << 0x8u | _col << 0x10u | _col << 0x18u;
	for (ax_i20 addr = 0x400'0000u;addr != 0x401'2C00u;addr += 0x4u) {ax_set20(addr,val);}
}

void ax_clrscrn4(ax_i20 const _vaddr,ax_i8 const _col) {
	ax_i20 const val = _col | _col << 0x8u | _col << 0x10u | _col << 0x18u;
	for (ax_i20 addr = _vaddr;addr != _vaddr + 0x9600u;addr += 0x4u) {ax_set20(addr,val);}
}

void ax_clrscrn5(ax_i20 const _vaddr,ax_i10 const _col) {
	ax_i20 const val = _col | _col << 0x10u;
	for (ax_i20 addr = _vaddr;addr != _vaddr + 0xA000u;addr += 0x4u) {ax_set20(addr,val);}
}
