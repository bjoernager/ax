#include <ax-demo.h>

#include <ax/key.h>
#include <ax/gfx.h>

#define axd_chk(_key) \
	if ((upd.keydwn = ax_chkkey(keymap,(upd.key = _key))))

axd_upd axd_chkkeys(axd_dat * _dat) {
	axd_upd upd = {};
	ax_keymap const keymap = ax_getkeymap();
	if (ax_chkkey(keymap,ax_key_a)) {
		upd.drw = true;
	}
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
		return upd;
	}
	axd_chk(ax_key_r) {
		axd_chgcol(_dat,0x1u);
		return upd;
	}
	axd_chk(ax_key_pade) {
		if (_dat->pos.x != 0xEEu) {
			upd.mv = true;
			++_dat->pos.x;
			return upd;
		}
	}
	axd_chk(ax_key_padn) {
		if (_dat->pos.y != 0x1u) {
			upd.mv = true;
			--_dat->pos.y;
			return upd;
		}
	}
	axd_chk(ax_key_pads) {
		if (_dat->pos.y != 0x9Eu) {
			upd.mv = true;
			++_dat->pos.y;
			return upd;
		}
	}
	axd_chk(ax_key_padw) {
		if (_dat->pos.x != 0x1u) {
			upd.mv = true;
			--_dat->pos.x;
			return upd;
		}
	}
	return upd;
}
