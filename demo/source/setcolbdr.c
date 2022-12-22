#include <ax-demo.h>

#include <ax/gfx.h>

void axd_setcolbdr(ax_i02 const _vaddr,ax_i01 const _col) {
	for (ax_i01 px = 0x0u;px != 0xF0u;++px) {
		ax_plot1(_vaddr,px,_col);
	}
	for (ax_i01 px = 0xEFu;px != ax_scrnh3 * ax_scrnw3 + 0xEFu;px += ax_scrnw3) {
		ax_plot1(_vaddr,px,_col);
	}
	for (ax_i01 px = 0x9Fu * ax_scrnw3;px != 0x9Fu * ax_scrnw3 + 0xF0u;++px) {
		ax_plot1(_vaddr,px,_col);
	}
	for (ax_i01 px = 0x0u;px != ax_scrnh3 * ax_scrnw3;px += ax_scrnw3) {
		ax_plot1(_vaddr,px,_col);
	}
}
