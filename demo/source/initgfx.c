#include <agbx-demo.h>

#include <ax/gfx.h>

void axd_initgfx(void) {
	ax_set10(0x500'0000u,0b0u);
	ax_set10(0x500'0002u,0b111111111111111u);
	ax_set10(0x500'0004u,0b11111u);
	ax_set10(0x500'0006u,0b1111111111u);
	ax_set10(0x500'0008u,0b1111100000u);
	ax_set10(0x500'000Au,0b111111111100000u);
	ax_set10(0x500'000Cu,0b111110000000000u);
	ax_set10(0x500'000Eu,0b111110000011111u);
	ax_set10(0x400'0000u,0x404u);
	ax_clrscrn4(0x600'0000u,0x0u);
	ax_clrscrn4(0x600'A000u,0x0u);
}
