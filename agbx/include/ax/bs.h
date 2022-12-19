/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_bs)
#define __ax_hdr_bs

#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(__cplusplus)
/* C23 compatibility: */
#define constexpr static const
#endif

typedef unsigned short     ax_i01;
typedef unsigned int       ax_i02;
typedef unsigned long long ax_i04;
typedef unsigned char      ax_i8;

typedef enum {
	ax_err_ok      = 0x0u,
	ax_err_badaddr,
	ax_err_badalgn,
	ax_err_badcol,
	ax_err_badmd,
	ax_err_pos2big,
	ax_err_px2big,
	ax_err_max     = 0xFFu,
} ax_err;

constexpr ax_i04 ax_ver = 0x9u;

[[noreturn]] void ax_done(ax_err err);

[[nodiscard]] ax_i01 ax_get10(ax_i02 addr);
[[nodiscard]] ax_i02 ax_get20(ax_i02 addr);
[[nodiscard]] ax_i8  ax_get8( ax_i02 addr);

void ax_set10(ax_i02 addr,ax_i01 val);
void ax_set20(ax_i02 addr,ax_i02 val);
void ax_set8( ax_i02 addr,ax_i8  val);

#if defined(__cplusplus)
}
#endif

#endif
