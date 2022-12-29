/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/algo.h>
#include <string.h>

size_t strlen(char const * const _s) {
	char const * pos = _s;
	while (*pos++) {}
	return (size_t)(pos - _s);
}
