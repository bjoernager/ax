/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_stdlib)
#define __ax_hdr_stdlib

#include <ax/bs.h>

#define __STDC_VERSION_STDLIB_H__ (202311l)

#define NULL nullptr

typedef ax_i02 size_t;
typedef ax_i02 wchar_t;

size_t memalignment(void const * p);

#endif
