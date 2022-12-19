#include <agbx-demo.h>

#include <ax/key.h>
#include <ax/gfx.h>

bool axd_loop(axd_dat * const _dat) {
	bool err = false;
	_dat->prevcol = 0x0u;
	axd_setcolbdr(_dat->vaddr,_dat->col);
	ax_plot1(_dat->vaddr,ax_coord(ax_scrnw3,_dat->pos.x,_dat->pos.y),0x4u);
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
			if (upd.mv) {ax_plot1(_dat->vaddr,ax_coord(ax_scrnw3,_dat->pos.x,_dat->pos.y),_dat->col);}
		}
		if (upd.mv) {
			ax_plot1(_dat->vaddr,ax_coord(ax_scrnw3,_dat->prevpos.x,_dat->prevpos.y),_dat->prevcol);
			_dat->prevcol = ax_rd1(_dat->vaddr,ax_coord(ax_scrnw3,_dat->pos.x,_dat->pos.y));
			ax_plot1(_dat->vaddr,ax_coord(ax_scrnw3,_dat->pos.x,_dat->pos.y),0x4u);
		}
	}
	return err;
}
