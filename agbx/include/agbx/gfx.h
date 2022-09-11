/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__agbx_hdr_gfx)
#define __agbx_hdr_gfx

#include <agbx/bs.h>

agbx_i20 agbx_flip(void);

void agbx_setpx1(agbx_i20 vaddr,agbx_i10 px,agbx_i8  col);
void agbx_setpx2(agbx_i20 vaddr,agbx_i10 px,agbx_i10 col);

agbx_i10 agbx_plot3(agbx_i8 x,agbx_i8 y,agbx_i10 col);
agbx_i10 agbx_plot4(agbx_i8 x,agbx_i8 y,agbx_i8  col);
agbx_i10 agbx_plot5(agbx_i8 x,agbx_i8 y,agbx_i10 col);

#endif
