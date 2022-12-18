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
	ldr r0,.vcountaddr @ ax_i02 vcountaddr = 0x4000006u;
	movs r1,0xA0       @ ax_i02 numhline = 0xA0;
	
.loop:
	@ Check the scanline counter:
	ldrh r2,[r0]       @ ax_i02 vcount = *(ax_i01 *)vcountaddr;
	cmp r2,r1
	beq .ret           @ if (vcount == numhline) {goto ret;}

	b .loop            @ goto loop;

.ret:
	@ Return:
	bx lr              @ return;

.endfunc

.align

.vcountaddr:
	.long 0x4000006
