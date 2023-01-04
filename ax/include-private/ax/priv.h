/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_ax_priv)
#define __ax_hdr_ax_priv

#include <ax/bs.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define __ax_get01(_addr) (*(ax_i01 volatile *)_addr)

#define __ax_get02(_addr) (*(ax_i02 volatile *)_addr)

#define __ax_get8(_addr) (*(ax_i8 volatile *)_addr)

#define __ax_set01(_addr,_val) ((void)(*(ax_i01 volatile *)_addr = _val))

#define __ax_set02(_addr,_val) ((void)(*(ax_i02 volatile *)_addr = _val))

#define __ax_set8(_addr,_val) ((void)(*(ax_i8 volatile *)_addr = _val))

#define __ax_plot2(_vaddr,_px,_col) { \
	ax_i02 const addr = _vaddr + _px * 0x2u; /* We multiply it by two as each pixel takes up two bytes. */ \
	__ax_set01(addr,_col); \
}

#if defined(__cplusplus)
}
#endif

#if defined(__cplusplus)

template<typename _ltyp,typename _rtyp> struct __ax_typeqimpl            {constexpr static bool eq = false;};
template<typename _typ>                 struct __ax_typeqimpl<_typ,_typ> {constexpr static bool eq = true;};

template<typename _ltyp,typename _rtyp> constexpr bool __ax_typeq = ::__ax_typeqimpl<_ltyp,_rtyp>::eq;

#endif

#endif
