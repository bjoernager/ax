/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

void ax_done(ax_err const _err) {
	if (_err == ax_err_ok) {
		__asm__ (
			"svc 0x3\n"
		);
		__builtin_unreachable();
	}
	{
		ax_set01(0x400'0000u,0b00000100'10000100u);
		ax_setcol(0x0u,ax_col(0x0Fu,0x0Fu,0x0Fu));
		ax_setcol(0x1u,ax_col(0x1Fu,0x1Fu,0x1Fu));
		ax_setcol(0x2u,ax_col(0x00u,0x00u,0x00u));
		ax_blnk();
		ax_i02 const vaddr = 0x600'0000u;
		ax_rec1(vaddr,ax_scrnw3,0x0u,0x11u,0x3u,0x2u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x01u,0x1u),(ax_i8)_err         & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x03u,0x1u),(ax_i8)_err >> 0x1u & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x05u,0x1u),(ax_i8)_err >> 0x2u & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x07u,0x1u),(ax_i8)_err >> 0x3u & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x09u,0x1u),(ax_i8)_err >> 0x4u & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x0Bu,0x1u),(ax_i8)_err >> 0x5u & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x0Du,0x1u),(ax_i8)_err >> 0x6u & 0b00000001u);
		ax_plot1(vaddr,ax_coord(ax_scrnw3,0x0Fu,0x1u),(ax_i8)_err >> 0x7u & 0b00000001u);
	}
	ax_trap();
}
