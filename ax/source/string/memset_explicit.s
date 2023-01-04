@ Copyright 2022-2023 Gabriel Jensen.
@ This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
@ If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.

.syntax unified

.cpu arm7tdmi
.thumb

.extern memset

.globl memset_explicit

.func
.thumb_func

memset_explicit:
	b memset

.endfunc
