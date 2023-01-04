@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl strlen

.func
.thumb_func

strlen:
	             @ char chr;

	movs r1,r0   @ char const * start = s;

.loop:           @ loop:;
	@ Move the character into a register:
	ldrb r2,[r0] @ chr = *s;

	@ Check if we have reached the null-terminator:
	cmp r2,0x0
	beq .done    @ if (chr == '\x0') goto done;

	@ Continue to the next character:
	adds r0,0x1  @ ++s;
	b .loop      @ goto loop;

.done:
	@ Calculate the length:
	subs r0,r1   @ s -= start;

	bx lr        @ return (size_t)s;

.endfunc
