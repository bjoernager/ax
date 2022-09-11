/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__agbx_hdr_priv)
#define __agbx_hdr_priv

#include <agbx/bs.h>

#define __agbx_set10(_addr,_val) { \
	__asm__ ( \
		"strh %1,[%0]" \
		: \
		: "r" (_addr),"r" (_val) \
		: "memory" \
	); \
}

#define __agbx_set20(_addr,_val) { \
	__asm__ ( \
		"str %1,[%0]" \
		: \
		: "r" (_addr),"r" (_val) \
		: "memory" \
	); \
}

#define __agbx_set8(_addr,_val) { \
	__asm__ ( \
		"strb %1,[%0]" \
		: \
		: "r" (_addr),"r" (_val) \
		: "memory" \
	); \
}

#define __agbx_setpx2(_vaddr,_px,_col) { \
	agbx_i20 const addr = _vaddr + _px * 0x2u; /* We multiply it by two as each pixel takes up two bytes. */ \
	__agbx_set10(addr,_col); \
}

#endif
