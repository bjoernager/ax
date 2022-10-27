/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__agbx_hdr_gfx)
#define __agbx_hdr_gfx

#include <agbx/bs.h>

agbx_i20 agbx_flip(   void);
agbx_i20 agbx_getvbnk(void);
void     agbx_vsync(  void);

void agbx_setpx1(agbx_i20 vaddr,agbx_i10 px,agbx_i8  col);
void agbx_setpx2(agbx_i20 vaddr,agbx_i10 px,agbx_i10 col);

agbx_i8  agbx_getpx1(agbx_i20 vaddr,agbx_i10 px);
agbx_i10 agbx_getpx2(agbx_i20 vaddr,agbx_i10 px);

void agbx_clrscrn3(agbx_i10 col);
void agbx_clrscrn4(agbx_i20 vaddr,agbx_i8  col);
void agbx_clrscrn5(agbx_i20 vaddr,agbx_i10 col);

void agbx_plot3(agbx_i8  x,    agbx_i8 y,agbx_i10 col);
void agbx_plot4(agbx_i20 vaddr,agbx_i8 x,agbx_i8  y,  agbx_i8  col);
void agbx_plot5(agbx_i20 vaddr,agbx_i8 x,agbx_i8  y,  agbx_i10 col);

agbx_i10 agbx_rd3(agbx_i8  x,    agbx_i8 y);
agbx_i8  agbx_rd4(agbx_i20 vaddr,agbx_i8 x,agbx_i8 y);
agbx_i10 agbx_rd5(agbx_i20 vaddr,agbx_i8 x,agbx_i8 y);

void agbx_cir3(agbx_i8  x,    agbx_i8 y,agbx_i8 r);
void agbx_cir4(agbx_i20 vaddr,agbx_i8 x,agbx_i8 y,agbx_i8 r);
void agbx_cir5(agbx_i20 vaddr,agbx_i8 x,agbx_i8 y,agbx_i8 r);

#if false
void agbx_setpx1(agbx_i20 const _vaddr,agbx_i10 const _px,agbx_i8 const _col) {
	/* We can only write halfwords to VRAM, so we need to load the adjacent pixel value and combine it into a halfword. */
	agbx_i20 const addr = _vaddr + _px - (_px & 0x1u) * 0x1u;
	agbx_i10 col;
	if (_px & 0x1u) {col = (agbx_i10)agbx_get8(addr) | (agbx_i10)_col << 0x8u;}
	else            {col = (agbx_i10)agbx_get8(addr + 0x1u) << 0x8u | (agbx_i10)_col;}
	__agbx_set10(addr,col);
}

void agbx_setpx2(agbx_i20 const _vaddr,agbx_i10 const _px,agbx_i10 const _col) {
	__agbx_setpx2(_vaddr,_px,_col)
}
#endif

#endif
