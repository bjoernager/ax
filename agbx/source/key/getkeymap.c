/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/key.h>

agbx_keymap agbx_getkeymap(void) {
	agbx_keymap map;
	map._keys = agbx_get10(0x4000130u);
	return map;
}
