@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.extern ax_done
.extern ax_main

.globl __ax_init

.func
.thumb_func

__ax_init:
	@ Call main:
	bl ax_main

	@ Call done:
	bl ax_done @ The return value is already in r0, so there's no need to move it.

.endfunc
