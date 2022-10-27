@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl agbx_set10
.globl agbx_set20
.globl agbx_set8

.func
.thumb_func

agbx_set10:
	strh r1,[r0] @ *(agbx_i10 *)addr = val;
	bx lr        @ return;

.endfunc

.func
.thumb_func

agbx_set20:
	str r1,[r0] @ *(agbx_i20 *)addr = val;
	bx lr       @ return;

.endfunc

.func
.thumb_func

agbx_set8:
	strb r1,[r0] @ *(agbx_i8 *)addr = val;
	bx lr        @ return;

.endfunc
