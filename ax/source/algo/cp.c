/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/algo.h>

void ax_cp(void const * const _in,ax_i02 const _num,void * const _out) {
	unsigned char const *       in       = _in;
	unsigned char *             out      = _out;
	unsigned char const * const afterbuf = in + _num;
	for (;in != afterbuf;++in,++out) {*out = *in;}
}
