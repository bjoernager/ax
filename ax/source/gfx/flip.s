@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.extern __ax_getvbnk

.globl ax_flip

.func
.thumb_func

ax_flip:
	@ Get the current value of dispcntrl:
	ldr r0,.dispcntrladdr @ ax_i02 dispcntrladdr = 0x4000000u;
	ldrh r1,[r0]         @ ax_i01 dispcntrl = *(ax_i01 *)dispcntrladdr;

	@ XOR bit four:
	movs r2,0b10000
	eors r1,r2           @ dispcntrl ^= 0b10000u;

	@ Save dispcntrl:
	strh r1,[r0]         @ *(ax_i01 *)dispcntrladdr = dispcntrl;

	@ Get the address of the video bank:
	b __ax_getvbnk       @ ax_i02 vaddr = __ax_getvbnk();
	
	@ Return:
	bx lr                @ return vaddr;

.endfunc

.align

.dispcntrladdr:
	.word 0x4000000
