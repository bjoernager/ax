#include <agbx-demo.h>

#include <agbx/gfx.h>

void agbxd_initdat(agbxd_dat * const _dat) {
	_dat->col   = 0x2u;
	_dat->pos.x = 0x0u;
	_dat->pos.y = 0x0u;
	_dat->vaddr = 0x600'0000u;
}
