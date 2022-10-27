@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.globl ax_getpx1
.globl ax_getpx2

.func
.thumb_func

ax_getpx1:
	adds r0,r1 @ Get the address of the pixel by adding the offset to the video address.
	ldrh r0,[r0]
	bx lr

.endfunc

.func
.thumb_func

ax_getpx2:
	adds r0,r1 @ Get the address of the pixel by adding the offset to the video address.
	adds r0,r1 @ Add the offset twice as each pixel takes up two bytes.
	ldrh r0,[r0]
	bx lr

.endfunc
