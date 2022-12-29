#include <ax-demo.h>

#include <ax/gfx.h>

void axd_initdat(axd_dat * const _dat) {
	_dat->col   = 0x4u;
	_dat->pos.x = 0x2u;
	_dat->pos.y = 0x2u;
	_dat->vaddr = 0x600'0000u;
}
