#include <agbx-demo.h>

#include <ax/gfx.h>

void axd_initdat(axd_dat * const _dat) {
	_dat->col   = 0x4u;
	_dat->pos.x = 0x1u;
	_dat->pos.y = 0x1u;
	_dat->vaddr = 0x600'0000u;
}
