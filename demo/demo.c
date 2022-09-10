#include <agbx/key.h>
#include <agbx/gfx.h>

agbx_err agbx_main(void) {
	agbx_set10(0x4000000u,0x403u);
	struct {
		agbx_i8 x;
		agbx_i8 y;
	} pos = {.x = 0x0u,.y = 0x0u,};
	agbx_setpx2(0x0u,0xFFFFu);
	for (;;) {
		agbx_keymap const keymap = agbx_getkeymap();
		if (agbx_chkkey(keymap,agbx_key_b)) {
			return (agbx_err)(((agbx_i10)pos.x + (agbx_i10)pos.y)/0x2u);
		}
		if (agbx_chkkey(keymap,agbx_key_a)) {
			return agbx_err_ok;
		}
		typeof (pos) const prevpos = pos;
		agbx_key key;
		if (agbx_chkkey(keymap,agbx_key_pade)) {
			if (pos.x != 0xEFu) {
				key = agbx_key_pade;
				++pos.x;
				goto drw;
			}
		}
		if (agbx_chkkey(keymap,agbx_key_padn)) {
			if (pos.y != 0x0u) {
				key = agbx_key_padn;
				--pos.y;
				goto drw;
			}
		}
		if (agbx_chkkey(keymap,agbx_key_pads)) {
			if (pos.y != 0x9Fu) {
				key = agbx_key_pads;
				++pos.y;
				goto drw;
			}
		}
		if (agbx_chkkey(keymap,agbx_key_padw)) {
			if (pos.x != 0x0u) {
				key = agbx_key_padw;
				--pos.x;
				goto drw;
			}
		}
		continue;
	drw:;
		agbx_plot3(prevpos.x,prevpos.y,0x19u);
		agbx_plot3(pos.x,pos.y,0xFFFFu);
		while (agbx_chkkey(agbx_getkeymap(),key)) {}
	}
}
