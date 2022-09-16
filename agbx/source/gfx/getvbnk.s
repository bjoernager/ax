@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl __agbx_getvbnk
.globl agbx_getvbnk

.func

.thumb_func

agbx_getvbnk:
	@ Get the current value of dispcnt:
	ldr r0,.dispcntaddr
	ldrh r1,[r0]

	@ Get the address:
	b __agbx_getvbnk
	
	bx lr

.endfunc

.func

.thumb_func

__agbx_getvbnk: @ Takes the value of dispcnt in r1.
	@ Check if the fifth bit is set:
	movs r0,0b10000
	tst r1,r0

	bne .vbnk1

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

.dispcntaddr:
	.long 0x4000000

.align

.vbnk0addr:
	.long 0x6000000

.align

.vbnk1addr:
	.long 0x600A000
