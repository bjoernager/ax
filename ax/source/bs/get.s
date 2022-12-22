@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_get01
.globl ax_get02
.globl ax_get8

.func
.thumb_func

ax_get01:
	ldrh r0,[r0] @ ax_i01 val = *(ax_i01 *)addr;
	bx lr        @ return val;

.endfunc

.func
.thumb_func

ax_get02:
	ldr r0,[r0] @ ax_i02 val = *(ax_i02 *)addr;
	bx lr       @ return val;

.endfunc

.func
.thumb_func

ax_get8:
	ldrb r0,[r0] @ ax_i8 val = *(ax_i8 *)addr;
	bx lr        @ return val;

.endfunc
