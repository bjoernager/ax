/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__agbx_hdr_bs)
#define __agbx_hdr_bs

/* C23 compatibility: */
#define constexpr static const
#define nullptr ((void *)0x0u)
#define typeof __typeof__

typedef unsigned short     agbx_i10;
typedef unsigned int       agbx_i20;
typedef unsigned long long agbx_i40;
typedef unsigned char      agbx_i8;

typedef enum {
	agbx_err_badmd,
	agbx_err_misc,
	agbx_err_ok,
	agbx_err_pos2big,
	agbx_err_px2big,
	agbx_err_max     = 0xFFu,
} agbx_err;

constexpr agbx_i40 agbx_ver = 0x0u;

[[noreturn]] void agbx_done(agbx_err err);

agbx_i10 agbx_get10(agbx_i20 addr);
agbx_i20 agbx_get20(agbx_i20 addr);
agbx_i8  agbx_get8( agbx_i20 addr);

void agbx_set10(agbx_i20 addr,agbx_i10 val);
void agbx_set20(agbx_i20 addr,agbx_i20 val);
void agbx_set8( agbx_i20 addr,agbx_i8  val);

#endif
