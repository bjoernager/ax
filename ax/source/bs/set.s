@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_set01
.globl ax_set02
.globl ax_set8

.func
.thumb_func

ax_set01:
	strh r1,[r0] @ *(ax_i01 *)addr = val;
	bx lr        @ return;

.endfunc

.func
.thumb_func

ax_set02:
	str r1,[r0] @ *(ax_i02 *)addr = val;
	bx lr       @ return;

.endfunc

.func
.thumb_func

ax_set8:
	strb r1,[r0] @ *(ax_i8 *)addr = val;
	bx lr        @ return;

.endfunc
