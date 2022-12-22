@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_getkeymap

.func
.thumb_func

ax_getkeymap:
	@ Load the keys:
	ldr r0,.addr @ ax_i02 addr = 0x4000130u;
	ldrh r0,[r0] @ ax_keymap keymap = *(ax_i01 *)addr;

	bx lr        @ return keymap;

.endfunc

.align

.addr:
	.long 0x4000130
