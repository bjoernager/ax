/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

template<typename _pxtyp> [[gnu::always_inline]] inline static auto __ax_rec(::ax_i02 const _vaddr,::ax_i8 const _scrnw,::ax_i01 const _px,::ax_i8 const _w,::ax_i8 const _h,_pxtyp const _col) noexcept -> void {
	static_assert(::__ax_typeq<_pxtyp,::ax_i8> || ::__ax_typeq<_pxtyp,::ax_i01>);
	for (::ax_i01 px = _px;px != _px + _h * _scrnw;) {
		::ax_i01 const rowstart = px;
		for (;px != rowstart + _w;++px) {
			if constexpr (::__ax_typeq<_pxtyp,::ax_i01>) {
				__ax_plot2(_vaddr,px,_col);
			}
			else {
				ax_plot1(_vaddr,px,_col);
			}
		}
		px = rowstart + _scrnw;
	}
}

extern "C" auto ax_rec1(::ax_i02 const _vaddr,::ax_i8 const _scrnw,::ax_i01 const _px,::ax_i8 const _w,::ax_i8 const _h,::ax_i8  const _col) -> void {::__ax_rec(_vaddr,_scrnw,_px,_w,_h,_col);}
extern "C" auto ax_rec2(::ax_i02 const _vaddr,::ax_i8 const _scrnw,::ax_i01 const _px,::ax_i8 const _w,::ax_i8 const _h,::ax_i01 const _col) -> void {::__ax_rec(_vaddr,_scrnw,_px,_w,_h,_col);}
