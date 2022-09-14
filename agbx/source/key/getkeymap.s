@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl agbx_getkeymap

.func

.thumb_func

agbx_getkeymap:
	ldr r0,.addr
	ldrh r0,[r0]
	bx lr

.endfunc

.align

.addr:
	.long 0x4000130
