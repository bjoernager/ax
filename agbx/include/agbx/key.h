/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#if !defined(__agbx_hdr_key)
#define __agbx_hdr_key

#include <agbx/bs.h>

typedef enum {
	agbx_key_a     = 0x0u,
	agbx_key_b     = 0x1u,
	agbx_key_l     = 0x9u,
	agbx_key_pade  = 0x4u,
	agbx_key_padn  = 0x6u,
	agbx_key_pads  = 0x7u,
	agbx_key_padw  = 0x5u,
	agbx_key_r     = 0x8u,
	agbx_key_sel   = 0x2u,
	agbx_key_start = 0x3u,
} agbx_key;

typedef struct {
	agbx_i10 _keys;
} agbx_keymap;

#define agbx_chkkey(_map,_key) (!(bool)(_map._keys >> (agbx_i10)_key & 0x1u))

agbx_keymap agbx_getkeymap(void);

#endif
