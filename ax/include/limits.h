/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_limits)
#define __ax_hdr_limits

#include <ax/bs.h>

#define __STDC_VERSION_LIMITS_H__ (202311l)

#define BOOL_WIDTH (0x8)

#define CHAR_BIT    (0x8)
#define CHAR_WIDTH  CHAR_BIT
#define SCHAR_WIDTH CHAR_BIT
#define UCHAR_WIDTH CHAR_BIT

#define USHRT_WIDTH (0x10)
#define SHRT_WIDTH  USHRT_WIDTH

#define UINT_WIDTH (0x20)
#define INT_WIDTH  UINT_WIDTH

#define ULONG_WIDTH (0x20)
#define LONG_WIDTH  ULONG_WIDTH

#define ULLONG_WIDTH (0x40)
#define LLONG_WIDTH  ULLONG_WIDTH

#define BITINT_MAXWIDTH ULLONG_WIDTH

#define MB_LEN_MAX (0x4)

#define UCHAR_MAX ((unsigned int)+ax_maxval_uc)
#define CHAR_MAX  CHAR_MAX

#define USHRT_MAX ((unsigned int)+ax_maxval_us)

#define UINT_MAX ax_maxval_ui

#define ULONG_MAX ax_maxval_ul

#define ULLONG_MAX ax_maxval_ull

#define SCHAR_MAX ((int)+ax_maxval_sc)
#define SCHAR_MIN ((int)+ax_minval_sc)

#define SHRT_MAX ((int)+ax_maxval_s)
#define SHRT_MIN ((int)+ax_minval_s)

#define INT_MAX ax_maxval_i
#define INT_MIN ax_minval_i

#define LONG_MAX ax_maxval_l
#define LONG_MIN ax_minval_l

#define LLONG_MAX ax_maxval_ll
#define LLONG_MIN ax_minval_ll

#endif
