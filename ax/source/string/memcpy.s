@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.extern ax_cp

.globl memcpy

.func
.thumb_func

memcpy:
	push {r0,lr} @ Save the value of s1 (r0) as we need to return it later.

	@ Order the parameters correctly:
	movs r3,r2
	movs r2,r0
	movs r0,r1
	movs r1,r3
	
	bl ax_cp
	pop {r0,r1} @ We cannot pop into lr.
	bx r1

.endfunc
