#include <agbx-demo.h>

#include <agbx/key.h>
#include <agbx/gfx.h>

#define agbxd_chk(_key) \
	curkey = _key; \
	if (agbx_chkkey(keymap,_key))

#define agbxd_wait() \
	while (agbx_chkkey(agbx_getkeymap(),curkey)) {}

agbxd_upd agbxd_chkkeys(agbxd_dat * _dat) {
	agbxd_upd upd = {};
	agbx_keymap const keymap = agbx_getkeymap();
	agbx_key          curkey;
	agbxd_chk(agbx_key_sel) {
		upd.done = true;
		upd.err  = true;
		return upd;
	}
	agbxd_chk(agbx_key_start) {
		upd.done = true;
		return upd;
	}
	agbxd_chk(agbx_key_l) {
		agbxd_chgcol(_dat,0x0u);
		agbxd_wait();
	}
	agbxd_chk(agbx_key_r) {
		agbxd_chgcol(_dat,0x1u);
		agbxd_wait();
	}
	agbxd_chk(agbx_key_pade) {
		if (_dat->pos.x != 0xEFu) {
			upd.mv = true;
			++_dat->pos.x;
			agbxd_wait();
		}
	}
	agbxd_chk(agbx_key_padn) {
		if (_dat->pos.y != 0x0u) {
			upd.mv = true;
			--_dat->pos.y;
			agbxd_wait();
		}
	}
	agbxd_chk(agbx_key_pads) {
		if (_dat->pos.y != 0x9Fu) {
			upd.mv = true;
			++_dat->pos.y;
			agbxd_wait();
		}
	}
	agbxd_chk(agbx_key_padw) {
		if (_dat->pos.x != 0x0u) {
			upd.mv = true;
			--_dat->pos.x;
			agbxd_wait();
		}
	}
	agbxd_chk(agbx_key_a) {upd.drw = true;}
	return upd;
}
