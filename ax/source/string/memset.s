@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.extern ax_fill

.globl memset

.func
.thumb_func

memset:
	push {r0,lr}

	@ Order the parameters correctly:
	movs r3,r1
	movs r1,r2
	movs r2,r3
	
	bl ax_fill
	pop {r0,r1} @ We cannot pop into lr.
	bx r1

.endfunc
