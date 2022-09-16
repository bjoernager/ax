#include <agbx-demo.h>

#include <agbx/key.h>
#include <agbx/gfx.h>

agbx_err agbx_main(void) {
	agbxd_dat dat;
	agbxd_initdat(&dat);
	agbxd_initgfx();
	bool const err = agbxd_loop(&dat);
	if (err) {
		for (agbx_i10 px = 0x0u;px != 0x9600u;++px) {
			agbx_setpx1(dat.vaddr,px,dat.col);
			agbxd_chgcol(&dat,0x1u);
		}
	}
	return err ? agbx_err_max : agbx_err_ok;
}
