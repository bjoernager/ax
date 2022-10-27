#include <agbx-demo.h>

#include <ax/gfx.h>

void axd_initdat(axd_dat * const _dat) {
	_dat->col   = 0x2u;
	_dat->pos.x = 0x0u;
	_dat->pos.y = 0x0u;
	_dat->vaddr = 0x600'0000u;
}
