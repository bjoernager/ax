@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.extern __agbx_getvbnk

.globl agbx_flip

.func

.thumb_func

agbx_flip:
	@ Get the current value of dispcnt:
	ldr r0,.dispcntaddr
	ldrh r1,[r0]

	@ XOR bit five:
	movs r2,0b10000
	eors r1,r2

	@ Save dispcnt:
	strh r1,[r0]

	@ Get the address of the video bank:
	b __agbx_getvbnk
	
	bx lr

.endfunc

.align

.dispcntaddr:
	.long 0x4000000
