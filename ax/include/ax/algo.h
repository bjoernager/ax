/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_ax_algo)
#define __ax_hdr_ax_algo

#include <ax/bs.h>

__ax_cdecl

typedef struct {
	ax_i02 quot;
	ax_i02 rem;
} ax_quotrem;

void ax_cp(  void const * in, ax_i02 num,void * out);
void ax_cp8( void const * in, ax_i02 num,void * out);
void ax_fill(void *       ptr,ax_i02 num,ax_i8  byte);

[[unsequenced]] ax_quotrem ax_divmod(ax_i02 num,ax_i02 den);

__ax_endcdecl

#endif
