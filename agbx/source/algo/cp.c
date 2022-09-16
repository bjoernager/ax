/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

#include <agbx/algo.h>

void agbx_cp(void const * const _src,agbx_i20 const _num,void * const _dest) {
	unsigned char const *       src      = _src;
	unsigned char  *            dest     = _dest;
	unsigned char const * const aftersrc = src + _num;
	for (;src != aftersrc;++src,++dest) {*dest = *src;}
}