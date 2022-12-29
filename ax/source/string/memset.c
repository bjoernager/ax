/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/algo.h>
#include <string.h>

void * memset(void * const _dest,int const _ch,size_t const _count) {
	unsigned char const byte = (unsigned char)_ch;
	ax_fill(_dest,_count,byte);
	return _dest;
}
