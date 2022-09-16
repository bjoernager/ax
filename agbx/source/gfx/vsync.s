@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl agbx_vsync

.func

.thumb_func

agbx_vsync:
	@ Set the constants:
	ldr r0,.scancnt @ Address of the scanline counter register.
	movs r1,0xA0 @ Number of horizontal lines;
	
.loop:
	@ Check the scanline counter:
	ldr r2,[r0] @ Load the counter.
	cmp r2,r1 @ Check if it has reached the bottom.
	beq .ret @ Return if so.

.ret:
	@ Return:
	bx lr

.endfunc

.align

.scancnt:
	.long 0x4000000

.align
