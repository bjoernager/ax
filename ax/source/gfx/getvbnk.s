@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl __ax_getvbnk
.globl ax_getvbnk

.func
.thumb_func

ax_getvbnk:
	@ Get the current value of dispcntrl:
	ldr r0,.dispcntrladdr @ ax_i02 dispcntrladdr = 0x4000000u;
	ldrh r1,[r0]        @ ax_i01 dispcntrl = *(ax_i01 *)dispcntrladdr;

	@ Get the address:
	b __ax_getvbnk      @ ax_i02 vaddr = __ax_getvbnk();
	
	bx lr               @ return vaddr;

.endfunc

.func
.thumb_func

__ax_getvbnk: @ Takes the value of dispcntrl in r1.
	@ Check if the fifth bit is set:
	movs r0,0b10000
	tst r1,r0
	beq .vbnk1

.vbnk0:
	@ Return the address of the first video bank:
	ldr r0,.vbnk0addr
	bx lr

.vbnk1:
	@ Return the address of the second video bank:
	ldr r0,.vbnk1addr
	bx lr

.endfunc

.align

.dispcntrladdr:
	.word 0x4000000

.align

.vbnk0addr:
	.word 0x6000000

.align

.vbnk1addr:
	.word 0x600A000
