@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_blnk

.func
.thumb_func

ax_blnk:
	@ Get the current value of dispcnt:
	ldr r0,.dispcntaddr @ ax_i02 dispcntaddr = 0x4000000u;
	ldrh r1,[r0]        @ ax_i01 dispcnt = *(ax_i01 *)dispcntaddr;

	@ XOR bit seven:
	movs r2,0b10000000
	eors r1,r2          @ dispcnt ^= 0b10000000u;

	@ Save dispcnt:
	strh r1,[r0]        @ *(ax_i01 *)dispcntaddr = dispcnt;

	@ Return:	
	bx lr               @ return vaddr;

.endfunc

.align

.dispcntaddr:
	.long 0x4000000
