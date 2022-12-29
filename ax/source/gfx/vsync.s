@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_vsync

.func
.thumb_func

ax_vsync:
	@ Set the constants:
	ldr r0,.vcntaddr @ ax_i02 vcntaddr = 0x4000006u;
	
.waitvdrw:             @ waitvdrw:;
	@ Wait for the next VDraw:
	ldrh r2,[r0]       @ ax_i02 vcnt = *(ax_i01 *)vcntaddr;
	cmp r2,0x0
	beq .waitvblnk     @ if (vcnt == 0x0u) goto waitvblnk;
	b .waitvdrw        @ goto waitvdrw;

.waitvblnk:            @ waitvblnk:;
	@ Wait for the VBlank:
	ldrh r2,[r0]       @ ax_i02 vcnt = *(ax_i01 *)vcntaddr;
	cmp r2,0xA0
	beq .ret           @ if (vcnt == 0xA0u) goto ret;
	b .waitvblnk       @ goto waitvblnk;

.ret:
	@ Return:
	bx lr              @ return;

.endfunc

.align

.vcntaddr:
	.word 0x4000006
