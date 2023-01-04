@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_cp

.func
.thumb_func

ax_cp:
	            @ ax_i02 tmp4;
	            @ ax_i8 tmp1;

.wrdcp:         @ wrdcp:;
	@ Check if there are at least four bytes remaining:
	cmp r1,0x4
	blt .bytecp @ if (num < 0x4u) goto bytecp;

	@ Copy one word:
	ldm r0!,{r3} @ tmp4 = *(ax_i02 *)in; /* We use ldm/stm with an exclamation mark after the source/destination as this version saves the incremented address into the register, meaning we don't have to icrement it ourselves. */
	stm r2!,{r3} @ *(ax_i02 *)out = tmp4;

	@ Continue to the next word:
	subs r1,0x4 @ num -= 0x4u;
	b .wrdcp    @ goto wrdcp;

.bytecp:        @ bytecp:;
	@ Check if we have any bytes remaining:
	cmp r1,0x0
	beq .done   @ if (num == 0x0u) goto done;

	@ Copy one byte:
	ldrb r3,[r0] @ tmp1 = *(ax_i8 *)in;
	strb r3,[r2] @ *(ax_i8 *)out = tmp1;

	@ Continue to the next byte:
	adds r0,0x1 @ ++in;
	adds r2,0x1 @ ++out;
	subs r1,0x1 @ --num;
	b .bytecp   @ goto bytecp;

.done:          @ done:;
	@ Return:
	bx lr       @ return;
	
.endfunc
