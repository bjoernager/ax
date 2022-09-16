#include <agbx-demo.h>

#include <agbx/gfx.h>

void agbxd_chgcol(agbxd_dat * _dat,agbx_i8 const _dir) {
	constexpr agbx_i8 maxcol = 0x7u;
	agbx_i8 col = _dat->col;
	if (!_dir) {
		if (!col) {col = maxcol;}
		else      {--col;}
	}
	else {
		if (col == maxcol) {col = 0x0u;}
		else               {++col;}
	}
	_dat->col = col;
}
