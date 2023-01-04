/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_stdarg)
#define __ax_hdr_stdarg

#include <ax/bs.h>

#define __STDC_VERSION_STDARG_H__ (202311l)

#define va_arg(_ap,_type) ((_type)0x0u)

#define va_copy(_dest,_src) ((void)0x0u)

#define va_end(_ap) ((void)0x0u)

#define va_start(_ap,...) ((void)0x0u)

typedef void * va_list;

#endif
