#include <agbx-demo.h>

#include <ax/gfx.h>

void axd_chgcol(axd_dat * _dat,ax_i8 const _dir) {
	constexpr ax_i8 maxcol = 0xEu;
	ax_i8 col = _dat->col;
	if (!_dir) {
		if (!col) {col = maxcol;}
		else      {--col;}
	}
	else {
		if (col == maxcol) {col = 0x0u;}
		else               {++col;}
	}
	_dat->col = col;
	axd_setcolbdr(_dat->vaddr,col);
}
