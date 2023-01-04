@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_cp8

.func
.thumb_func

ax_cp8:
	             @ ax_i8 tmp;
	adds r1,r0   @ void * end = in + num;
.cp:             @ cp:;
	@ Check if we have any bytes remaining:
	cmp r0,r1
	beq .done    @ if (num == end) goto done;

	@ Copy one byte:
	ldrb r3,[r0] @ tmp = *(ax_i8 *)in;
	strb r3,[r2] @ *(ax_i8 *)out = tmp;

	@ Continue to the next byte:
	adds r0,0x1 @ ++in;
	adds r2,0x1 @ ++out;
	b .cp       @ goto cp;

.done:          @ done:;
	@ Return:
	bx lr       @ return;
	
.endfunc
