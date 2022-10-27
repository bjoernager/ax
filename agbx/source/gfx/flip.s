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
	ldr r0,.dispcntaddr @ agbx_i20 dispcntaddr = 0x4000000u;
	ldrh r1,[r0]        @ agbx_i10 dispcnt = *(agbx_i10 *)dispcntaddr;

	@ XOR bit five:
	movs r2,0b10000
	eors r1,r2          @ dispcnt ^= 0b10000u;

	@ Save dispcnt:
	strh r1,[r0]        @ *(agbx_i10 *)dispcntaddr = dispcnt;

	@ Get the address of the video bank:
	b __agbx_getvbnk    @ agbx_i20 vaddr = __agbx_getvbnk();
	
	bx lr               @ return vaddr;

.endfunc

.align

.dispcntaddr:
	.long 0x4000000
