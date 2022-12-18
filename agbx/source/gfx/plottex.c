/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/gfx.h>

void ax_plottex3(ax_i01 const * const _tex,ax_i8 const _x,ax_i8 const _y,ax_i8 const _w,ax_i8 const _h) {
	ax_i01 const * texpos = _tex;
	for (ax_i8 y = _y;y != _y + _h;++y) {
		for (ax_i8 x = _x;x != _x + _w;++x) {
			ax_plot3(x,y,*(texpos++));
		}
	}
}

void ax_plottex4(ax_i02 const _vaddr,ax_i8 const * const _tex,ax_i8 const _x,ax_i8 const _y,ax_i8 const _w,ax_i8 const _h) {
	ax_i8 const * texpos = _tex;
	for (ax_i8 y = _y;y != _y + _h;++y) {
		for (ax_i8 x = _x;x != _x + _w;++x) {
			ax_plot4(_vaddr,x,y,*(texpos++));
		}
	}
}

void ax_plottex5(ax_i02 const _vaddr,ax_i01 const * const _tex,ax_i8 const _x,ax_i8 const _y,ax_i8 const _w,ax_i8 const _h) {
	ax_i01 const * texpos = _tex;
	for (ax_i8 y = _y;y != _y + _h;++y) {
		for (ax_i8 x = _x;x != _x + _w;++x) {
			ax_plot5(_vaddr,x,y,*(texpos++));
		}
	}
}
