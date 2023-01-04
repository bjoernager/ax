@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_setcol

.func
.thumb_func

ax_setcol:
	@ Get the address of the colour:
	ldr r2,.paladdr @ ax_i02 paladdr = 0x5000000u;
	adds r2,r0      @ paladdr += n;
	adds r2,r0      @ paladdr += n; /* Add the index number twice as each colour value takes up two bytes. This is also simpler than multiplying by two. */

	@ Set the colour value:
	strh r1,[r2]    @ *(ax_i01 *)paladdr = col;

	@ Return:
	bx lr           @ return;

.endfunc

.align

.paladdr:
	.word 0x5000000
