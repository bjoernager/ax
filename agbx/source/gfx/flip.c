/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/gfx.h>

agbx_i20 agbx_flip(void) {
	agbx_i10 dispcnt = agbx_get10(0x400'0000u);
	dispcnt ^= 0b10000u;
	agbx_set10(0x400'0000u,dispcnt);
	if (dispcnt & 0x10000u) {return 0x600'A000u;}
	return 0x600'0000u;
}
