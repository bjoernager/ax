#include <ax-demo.h>

#include <ax/key.h>
#include <ax/gfx.h>

#define axd_chk(_key) \
	curkey = _key; \
	if (ax_chkkey(keymap,_key))

#define axd_wait() \
	while (ax_chkkey(ax_getkeymap(),curkey)) {}

axd_upd axd_chkkeys(axd_dat * _dat) {
	axd_upd upd = {};
	ax_keymap const keymap = ax_getkeymap();
	ax_key          curkey;
	axd_chk(ax_key_sel) {
		upd.done = true;
		upd.err  = true;
		return upd;
	}
	axd_chk(ax_key_start) {
		upd.done = true;
		return upd;
	}
	axd_chk(ax_key_l) {
		axd_chgcol(_dat,0x0u);
		axd_wait()
	}
	axd_chk(ax_key_r) {
		axd_chgcol(_dat,0x1u);
		axd_wait()
	}
	axd_chk(ax_key_pade) {
		if (_dat->pos.x != 0xEEu) {
			upd.mv = true;
			++_dat->pos.x;
			axd_wait()
		}
	}
	axd_chk(ax_key_padn) {
		if (_dat->pos.y != 0x1u) {
			upd.mv = true;
			--_dat->pos.y;
			axd_wait()
		}
	}
	axd_chk(ax_key_pads) {
		if (_dat->pos.y != 0x9Eu) {
			upd.mv = true;
			++_dat->pos.y;
			axd_wait()
		}
	}
	axd_chk(ax_key_padw) {
		if (_dat->pos.x != 0x1u) {
			upd.mv = true;
			--_dat->pos.x;
			axd_wait()
		}
	}
	axd_chk(ax_key_a) {upd.drw = true;}
	return upd;
}
