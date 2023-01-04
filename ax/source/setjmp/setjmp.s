@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.arm

.globl setjmp

.func

setjmp:
	stm r0,{r4,r5,r6,r7,r8,r9,r10,fp,ip,sp,lr} @ Save the registers into the registers.
	mov r0,0x0 @ Set the return code.
	bx lr

.endfunc
