/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

template<typename _pxtyp> [[gnu::always_inline]] inline static auto __ax_clrscrn(::ax_i02 const _vaddr,_pxtyp const _col) noexcept -> void {
	static_assert(::__ax_typeq<_pxtyp,::ax_i8> || ::__ax_typeq<_pxtyp,::ax_i01>);
	::ax_i02 const val = [&_col] {
		if constexpr (::__ax_typeq<_pxtyp,::ax_i01>) {
			return (ax_i02)_col | (ax_i02)_col << 0x10u;
		}
		return (ax_i02)_col | (ax_i02)_col << 0x8u | (ax_i02)_col << 0x10u | (ax_i02)_col << 0x18u;
	}();
	for (::ax_i02 addr = _vaddr;addr != _vaddr + 0x9600u;addr += 0x4u) {__ax_set02(addr,val);}
}

extern "C" auto ax_clrscrn1(::ax_i02 const _vaddr,::ax_i8  const _col) -> void {::__ax_clrscrn(_vaddr,_col);}
extern "C" auto ax_clrscrn2(::ax_i02 const _vaddr,::ax_i01 const _col) -> void {::__ax_clrscrn(_vaddr,_col);}
