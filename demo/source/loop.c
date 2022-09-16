#include <agbx-demo.h>

#include <agbx/key.h>
#include <agbx/gfx.h>

bool agbxd_loop(agbxd_dat * const _dat) {
	bool err = false;
	_dat->prevcol = 0x0u;
	agbx_plot4(_dat->vaddr,_dat->pos.x,_dat->pos.y,0x1u);
	for (;;) {
		_dat->prevpos = _dat->pos;
		agbxd_upd const upd = agbxd_chkkeys(_dat);
		if (upd.done) {
			err = upd.err;
			break;
		}
		agbx_vsync();
		if (upd.drw) {
			_dat->prevcol = _dat->col;
			if (upd.mv) {agbx_plot4(_dat->vaddr,_dat->pos.x,_dat->pos.y,_dat->col);}
		}
		if (upd.mv) {
			agbx_plot4(_dat->vaddr,_dat->prevpos.x,_dat->prevpos.y,_dat->prevcol);
			_dat->prevcol = agbx_rd4(_dat->vaddr,_dat->pos.x,_dat->pos.y);
			agbx_plot4(_dat->vaddr,_dat->pos.x,_dat->pos.y,0x1u);
		}
	}
	return err;
}
