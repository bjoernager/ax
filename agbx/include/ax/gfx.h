/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_gfx)
#define __ax_hdr_gfx

#include <ax/bs.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define ax_coord3(_x,_y) ((ax_i01)_y * ax_scrnw3 + (ax_i01)_x)
#define ax_coord5(_x,_y) ((ax_i01)_y * ax_scrnw5 + (ax_i01)_x)

ax_i02 ax_flip(   void);
ax_i02 ax_getvbnk(void);
void   ax_vsync(  void);

void ax_clrscrn1(ax_i02 vaddr,ax_i8  col);
void ax_clrscrn2(ax_i02 vaddr,ax_i01 col);

void ax_plot1(ax_i02 vaddr,ax_i01 px, ax_i8  col);
void ax_plot2(ax_i02 vaddr,ax_i01 px, ax_i01 col);

void ax_plottex1(ax_i02 vaddr,ax_i8 scrnw,ax_i8 const *  tex,ax_i01 px,ax_i8 w,ax_i8 h);
void ax_plottex2(ax_i02 vaddr,ax_i8 scrnw,ax_i01 const * tex,ax_i01 px,ax_i8 w,ax_i8 h);

ax_i8  ax_rd1(ax_i02 vaddr,ax_i01 px);
ax_i01 ax_rd2(ax_i02 vaddr,ax_i01 px);

void ax_cir1(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 r,ax_i8  col);
void ax_cir2(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 r,ax_i01 col);

#if defined(__cplusplus)
}
#endif

#endif
