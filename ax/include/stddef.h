/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_stddef)
#define __ax_hdr_stddef

#include <ax/bs.h>

#define __STDC_VERSION_STDDEF_H__ (202311l)

#define NULL nullptr

#if __has_builtin(__builtin_unreachable)
#define unreachable() __builtin_unreachable()
#else
#define unreachable() ax_trap()
#endif

#if __has_builtin(__builtin_offsetof)
#define offsetof(_typ,_memb) __builtin_offsetof((_typ),(_memb))
#else
/* uhmmm */
#define offsetof(_typ,_memb) ((size_t)+0x0u)
#endif

typedef ax_i02s                 ptrdiff_t;
typedef ax_i02                  size_t;
typedef unsigned long long      max_align_t;
typedef ax_i02                  wchar_t;
typedef typeof_unqual (nullptr) nullptr_t;

#endif
