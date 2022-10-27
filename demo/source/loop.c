#include <agbx-demo.h>

#include <ax/key.h>
#include <ax/gfx.h>

bool axd_loop(axd_dat * const _dat) {
	bool err = false;
	_dat->prevcol = 0x0u;
	ax_plot4(_dat->vaddr,_dat->pos.x,_dat->pos.y,0x1u);
	for (;;) {
		_dat->prevpos = _dat->pos;
		axd_upd const upd = axd_chkkeys(_dat);
		if (upd.done) {
			err = upd.err;
			break;
		}
		ax_vsync();
		if (upd.drw) {
			_dat->prevcol = _dat->col;
			if (upd.mv) {ax_plot4(_dat->vaddr,_dat->pos.x,_dat->pos.y,_dat->col);}
		}
		if (upd.mv) {
			ax_plot4(_dat->vaddr,_dat->prevpos.x,_dat->prevpos.y,_dat->prevcol);
			_dat->prevcol = ax_rd4(_dat->vaddr,_dat->pos.x,_dat->pos.y);
			ax_plot4(_dat->vaddr,_dat->pos.x,_dat->pos.y,0x1u);
		}
	}
	return err;
}
