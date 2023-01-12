/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_ax_key)
#define __ax_hdr_ax_key

#include <ax/bs.h>

__ax_cdecl

typedef enum {
	ax_key_a     = 0b00000000'00000001u,
	ax_key_b     = 0b00000000'00000010u,
	ax_key_l     = 0b00000010'00000000u,
	ax_key_pade  = 0b00000000'00010000u,
	ax_key_padn  = 0b00000000'01000000u,
	ax_key_pads  = 0b00000000'10000000u,
	ax_key_padw  = 0b00000000'00100000u,
	ax_key_r     = 0b00000001'00000000u,
	ax_key_sel   = 0b00000000'00000100u,
	ax_key_start = 0b00000000'00001000u,
} ax_key;

typedef struct {
	ax_i01 _keys;
} ax_keymap;

#define ax_chkkey(_map,_key) ((bool)(((_map)._keys ^ 0b11111111'11111111u) & (ax_i01)(_key)))

ax_keymap ax_getkeymap(void);

__ax_endcdecl

#endif
