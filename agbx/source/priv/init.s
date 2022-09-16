@ Copyright 2022 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

.syntax unified

.cpu arm7tdmi
.thumb

.extern agbx_done
.extern agbx_main

.globl __agbx_init

.func

.thumb_func

__agbx_init:
	@ Call main:
	bl agbx_main

	@ Call done:
	bl agbx_done @ The return value is already in r0, so there's no need to move it.

.endfunc
