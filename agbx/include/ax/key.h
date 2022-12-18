/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_key)
#define __ax_hdr_key

#include <ax/bs.h>

typedef enum {
	ax_key_a     = 0x0u,
	ax_key_b     = 0x1u,
	ax_key_l     = 0x9u,
	ax_key_pade  = 0x4u,
	ax_key_padn  = 0x6u,
	ax_key_pads  = 0x7u,
	ax_key_padw  = 0x5u,
	ax_key_r     = 0x8u,
	ax_key_sel   = 0x2u,
	ax_key_start = 0x3u,
} ax_key;

typedef struct {
	ax_i01 _keys;
} ax_keymap;

#define ax_chkkey(_map,_key) (!(bool)(_map._keys >> (ax_i01)_key & 0x1u))

ax_keymap ax_getkeymap(void);

#endif
