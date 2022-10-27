/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__ax_hdr_bs)
#define __ax_hdr_bs

/* C23 compatibility: */
#define constexpr static const
#define typeof __typeof__

typedef unsigned short     ax_i10;
typedef unsigned int       ax_i20;
typedef unsigned long long ax_i40;
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

constexpr ax_i40 ax_ver = 0x6u;

[[noreturn]] void ax_done(ax_err err);

[[nodiscard]] ax_i10 ax_get10(ax_i20 addr);
[[nodiscard]] ax_i20 ax_get20(ax_i20 addr);
[[nodiscard]] ax_i8  ax_get8( ax_i20 addr);

void ax_set10(ax_i20 addr,ax_i10 val);
void ax_set20(ax_i20 addr,ax_i20 val);
void ax_set8( ax_i20 addr,ax_i8  val);

#endif
