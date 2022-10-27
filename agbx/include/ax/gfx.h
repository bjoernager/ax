/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__ax_hdr_gfx)
#define __ax_hdr_gfx

#include <ax/bs.h>

ax_i20 ax_flip(   void);
ax_i20 ax_getvbnk(void);
void   ax_vsync(  void);

void ax_setpx1(ax_i20 vaddr,ax_i10 px,ax_i8  col);
void ax_setpx2(ax_i20 vaddr,ax_i10 px,ax_i10 col);

ax_i8  ax_getpx1(ax_i20 vaddr,ax_i10 px);
ax_i10 ax_getpx2(ax_i20 vaddr,ax_i10 px);

void ax_clrscrn3(ax_i10 col);
void ax_clrscrn4(ax_i20 vaddr,ax_i8  col);
void ax_clrscrn5(ax_i20 vaddr,ax_i10 col);

void ax_plot3(ax_i8  x,    ax_i8 y,ax_i10 col);
void ax_plot4(ax_i20 vaddr,ax_i8 x,ax_i8  y,  ax_i8  col);
void ax_plot5(ax_i20 vaddr,ax_i8 x,ax_i8  y,  ax_i10 col);

ax_i10 ax_rd3(ax_i8  x,    ax_i8 y);
ax_i8  ax_rd4(ax_i20 vaddr,ax_i8 x,ax_i8 y);
ax_i10 ax_rd5(ax_i20 vaddr,ax_i8 x,ax_i8 y);

void ax_cir3(ax_i8  x,    ax_i8 y,ax_i8 r);
void ax_cir4(ax_i20 vaddr,ax_i8 x,ax_i8 y,ax_i8 r);
void ax_cir5(ax_i20 vaddr,ax_i8 x,ax_i8 y,ax_i8 r);

#endif
