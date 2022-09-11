#include <agbx/key.h>
#include <agbx/gfx.h>

agbx_err agbx_main(void) {
	agbx_set10(0x500'0000u,0x0u);
	agbx_set10(0x500'0002u,0x19u);
	agbx_set10(0x500'0004u,0xFFFFu);
	agbx_set10(0x400'0000u,0x404u);
	struct {
		agbx_i8 x;
		agbx_i8 y;
	} pos = {.x = 0x0u,.y = 0x0u,};
	agbx_setpx1(0x600'0000u,0x0u,0x2u);
	for (;;) {
		agbx_keymap const keymap = agbx_getkeymap();
		if (agbx_chkkey(keymap,agbx_key_b)) {
			return (agbx_err)(((agbx_i10)pos.x + (agbx_i10)pos.y)/0x2u);
		}
		if (agbx_chkkey(keymap,agbx_key_a)) {
			return agbx_err_ok;
		}
		if (agbx_chkkey(keymap,agbx_key_l)) {
			agbx_plot4(pos.x,pos.y,0x1u);
			agbx_flip();
			agbx_plot4(pos.x,pos.y,0x2u);
			while (agbx_chkkey(agbx_getkeymap(),agbx_key_l)) {}
			continue;
		}
		typeof (pos) const prevpos = pos;
		agbx_key key = agbx_key_pade;
		if (agbx_chkkey(keymap,key)) {
			if (pos.x != 0xEFu) {
				++pos.x;
				goto drw;
			}
		}
		key = agbx_key_padn;
		if (agbx_chkkey(keymap,key)) {
			if (pos.y != 0x0u) {
				--pos.y;
				goto drw;
			}
		}
		key = agbx_key_pads;
		if (agbx_chkkey(keymap,key)) {
			if (pos.y != 0x9Fu) {
				++pos.y;
				goto drw;
			}
		}
		key = agbx_key_padw;
		if (agbx_chkkey(keymap,key)) {
			if (pos.x != 0x0u) {
				--pos.x;
				goto drw;
			}
		}
		continue;
	drw:;
		agbx_plot4(prevpos.x,prevpos.y,0x1u);
		agbx_plot4(pos.x,pos.y,0x2u);
		while (agbx_chkkey(agbx_getkeymap(),key)) {}
	}
}
