/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_ax_bs)
#define __ax_hdr_ax_bs

#if defined(__cplusplus)
#define __ax_cdecl    extern "C" {
#define __ax_endcdecl }
#define __ax_unseq
#else
/* C23 compatibility: */
#define alignas       _Alignas
#define alignof       _Alignof
#define bool          _Bool
#define constexpr     static const
#define false         ((_Bool)+0x0u)
#define nullptr       ((void *)0x0)
#define static_assert _Static_assert
#define thread_local  _Thread_local
#define true          ((_Bool)+0x1u)
#define typeof        __typeof__
#define typeof_unqual __typeof__

#define __ax_cdecl
#define __ax_endcdecl
#define __ax_unseq    [[unsequenced]]
#endif

__ax_cdecl

#define ax_maxval_i ((int)+0x7FFFFFFF)
#define ax_minval_i ((int)-0x80000000)

#define ax_maxval_l ((long)+0x7FFFFFFF)
#define ax_minval_l ((long)-0x80000000)

#define ax_maxval_ll ((long long)+0x7FFFFFFFFFFFFFFF)
#define ax_minval_ll ((long long)-0x8000000000000000)

#define ax_maxval_s ((short)+0x7FFF)
#define ax_minval_s ((short)-0x8000)

#define ax_maxval_sc ((signed char)+0x7F)
#define ax_minval_sc ((signed char)-0x80)

#define ax_maxval_uc ((unsigned char)+0xFFu)
#define ax_minval_uc ((unsigned char)+0x0u)

#define ax_maxval_ui ((unsigned int)+0xFFFFFFFFu)
#define ax_minval_ui ((unsigned int)+0x0u)

#define ax_maxval_ul ((unsigned long)+0xFFFFFFFFu)
#define ax_minval_ul ((unsigned long)+0x0u)

#define ax_maxval_ull ((unsigned long long)+0xFFFFFFFFFFFFFFFFu)
#define ax_minval_ull ((unsigned long long)+0x0u)

#define ax_maxval_c ((char)+ax_maxval_uc)
#define ax_minval_c ((char)+ax_minval_uc)

typedef unsigned short     ax_i01;
typedef unsigned int       ax_i02;
typedef unsigned long long ax_i04;
typedef unsigned char      ax_i8;

typedef short     ax_i01s;
typedef int       ax_i02s;
typedef long long ax_i04s;
typedef char      ax_i8s;

typedef enum {
	ax_err_ok         = 0x0u,
	ax_err_badaddr,   /* bad address */
	ax_err_badalgn,   /* bad alignment */
	ax_err_badcol,    /* bad colour */
	ax_err_badgfxmd,  /* bad graphics mode */
	ax_err_badparam,  /* bad parameter */
	ax_err_divzero,   /* division by zero */
	ax_err_misc,      /* miscellaneous */
	ax_err_nullptr,   /* null pointer */
	ax_err_oflow,     /* overflow */
	ax_err_pos2big,   /* position too big */
	ax_err_px2big,    /* pixel number too big */
	ax_err_max        = 0xFFu,
} ax_err;

constexpr ax_i04 ax_ver = 0xCu;

ax_i01 ax_get01(ax_i02 addr);
ax_i02 ax_get02(ax_i02 addr);
ax_i8  ax_get8( ax_i02 addr);

void ax_set01(ax_i02 addr,ax_i01 val);
void ax_set02(ax_i02 addr,ax_i02 val);
void ax_set8( ax_i02 addr,ax_i8  val);

[[noreturn]] void ax_done(ax_err err);
[[noreturn]] void ax_trap(void);

__ax_endcdecl

#endif
