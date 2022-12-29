@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.arm

.extern ax_done
.extern ax_start

.globl __ax_font
.globl __ax_init

.func

__ax_init:
	@ Call start:
	ldr r0,=ax_start @ We load the address of start into a register so we can use bx to call it, allowing for the programmer to implement the function in either ARM or THUMB. This processor doesn't support blx, so we aren't able to use that instead.
	mov lr,pc @ bx doesn't set the return address, so we do it ourselves. pc stores the instruction after the next one, so we don't have to apply any arithmetic on it. THUMB doesn't support using pc in a mov expression, which is why this function is ARM.
	bx r0

	@ Call done:
	ldr r1,=ax_done
	mov lr,pc
	bx r1 @ The error code (returned by ax_start) is already in r0, so there's no need to move it.

.endfunc

.section .bss

.align

__ax_font:
	.byte
	.byte
	.short
	.word
