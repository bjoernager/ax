/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/algo.h>

void ax_fill(void * const _ptr,ax_i02 const _num,unsigned char const _byte) {
	unsigned char *       pos      = _ptr;
	unsigned char * const afterbuf = pos + _num;
	for (;pos != afterbuf;++pos) {*pos = _byte;}
}
