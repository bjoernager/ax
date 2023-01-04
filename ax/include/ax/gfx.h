/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_ax_gfx)
#define __ax_hdr_ax_gfx

#include <ax/bs.h>

#if defined(__cplusplus)
extern "C" {
#endif

constexpr ax_i8 ax_scrnw3 = 0xF0u;
constexpr ax_i8 ax_scrnw5 = 0xA0u;
constexpr ax_i8 ax_scrnh3 = 0xA0u;
constexpr ax_i8 ax_scrnh5 = 0x80u;

#define ax_coord(_scrnw,_x,_y) ((ax_i01)((ax_i01)(_y) * (ax_i01)(_scrnw) + (ax_i01)(_x)))

#define ax_col(_r,_g,_b) ((ax_i01)(((ax_i01)_r | (ax_i01)_g << 0x5u | (ax_i01)_b << 0xAu) & 0b000000111111111111111))

void   ax_blnk(   void);
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

void ax_setcol(ax_i8 n,ax_i01 col);

void ax_cir1( ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 r,ax_i8  col);
void ax_cir2( ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 r,ax_i01 col);
void ax_hcir1(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 r,ax_i8  col);
void ax_hcir2(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 r,ax_i01 col);

void ax_ell1( ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 rx,ax_i8 ry,ax_i8  col);
void ax_ell2( ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 rx,ax_i8 ry,ax_i01 col);
void ax_hell1(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 rx,ax_i8 ry,ax_i8  col);
void ax_hell2(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 rx,ax_i8 ry,ax_i01 col);

void ax_ln1(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px0,ax_i01 px1,ax_i8  col);
void ax_ln2(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px0,ax_i01 px1,ax_i01 col);

void ax_rec1( ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 w,ax_i8 h,ax_i8  col);
void ax_rec2( ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 w,ax_i8 h,ax_i01 col);
void ax_hrec1(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 w,ax_i8 h,ax_i8  col);
void ax_hrec2(ax_i02 vaddr,ax_i8 scrnw,ax_i01 px,ax_i8 w,ax_i8 h,ax_i01 col);

#if defined(__cplusplus)
}
#endif

#endif
