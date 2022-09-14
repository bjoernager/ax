@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl agbx_get10
.globl agbx_get20
.globl agbx_get8

.func

.thumb_func

agbx_get10:
	ldrh r0,[r0]
	bx lr

.endfunc

.func

.thumb_func

agbx_get20:
	ldr r0,[r0]
	bx lr

.endfunc

.func

.thumb_func

agbx_get8:
	ldrb r0,[r0]
	bx lr

.endfunc