@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.arm

.globl longjmp

.func

longjmp:
	ldm r0,{r4,r5,r6,r7,r8,r9,r10,fp,ip,sp,lr} @ Load registers from buffer.
	mov r0,r1 @ Set the return code for setjmp.
	bx lr @ We loaded the return address of setjmp.

.endfunc
