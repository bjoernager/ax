@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl agbx_flip

.func

.thumb_func

agbx_flip:
	ldr r0,.dispcntaddr
	ldrh r1,[r0] @ Get the current value of dispcnt.
	movs r2,#0b10000
	eors r1,r2 @ XOR bit five.
	strh r1,[r0] @ Save dispcnt.
	movs r0,#0x10
	tst r1,r0 @ Check what video bank we should return the address of.
	beq .vbnk0
.vbnk1:
	ldr r0,.vbnk1addr
	bx lr
.vbnk0:
	ldr r0,.vbnk0addr
	bx lr

.endfunc

.align

.dispcntaddr:
	.long 0x4000000

.align

.vbnk0addr:
	.long 0x6000000

.align

.vbnk1addr:
	.long 0x600A000
