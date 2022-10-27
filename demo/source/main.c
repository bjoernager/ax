#include <agbx-demo.h>

#include <ax/key.h>
#include <ax/gfx.h>

ax_err ax_main(void) {
	axd_dat dat;
	axd_initdat(&dat);
	axd_initgfx();
	bool const err = axd_loop(&dat);
	if (err) {
		for (ax_i10 px = 0x0u;px != 0x9600u;++px) {
			ax_setpx1(dat.vaddr,px,dat.col);
			axd_chgcol(&dat,0x1u);
		}
	}
	return err ? ax_err_max : ax_err_ok;
}
