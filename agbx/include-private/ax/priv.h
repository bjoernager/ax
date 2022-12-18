/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_priv)
#define __ax_hdr_priv

#include <ax/bs.h>

#define __ax_get10(_addr) (*(ax_i01 volatile *)_addr)

#define __ax_get20(_addr) (*(ax_i02 volatile *)_addr)

#define __ax_get8(_addr) (*(ax_i8 volatile *)_addr)

#define __ax_set10(_addr,_val) ((void)(*(ax_i01 volatile *)_addr = _val))

#define __ax_set20(_addr,_val) ((void)(*(ax_i02 volatile *)_addr = _val))

#define __ax_set8(_addr,_val) ((void)(*(ax_i8 volatile *)_addr = _val))

#define __ax_setpx2(_vaddr,_px,_col) { \
	ax_i02 const addr = _vaddr + _px * 0x2u; /* We multiply it by two as each pixel takes up two bytes. */ \
	__ax_set10(addr,_col); \
}

#endif
