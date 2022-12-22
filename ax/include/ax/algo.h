/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_algo)
#define __ax_hdr_algo

#include <ax/bs.h>

#if defined(__cplusplus)
extern "C" {
#endif

void ax_cp(  void const * in, ax_i02 num,void * out);
void ax_fill(void *       ptr,ax_i02 num,ax_i8  byte);

#if defined(__cplusplus)
}
#endif

#endif
