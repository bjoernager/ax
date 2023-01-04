/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_stdint)
#define __ax_hdr_stdint

#include <ax/bs.h>

#define __STDC_VERSION_STDINT_H__ (202311l)

#define INT8_WIDTH  (0x8)
#define INT16_WIDTH (0x10)
#define INT32_WIDTH (0x20)
#define INT64_WIDTH (0x40)

#define UINT8_WIDTH  (0x8)
#define UINT16_WIDTH (0x10)
#define UINT32_WIDTH (0x20)
#define UINT64_WIDTH (0x40)

#define INT_LEAST8_WIDTH  INT8_WIDTH
#define INT_LEAST16_WIDTH INT16_WIDTH
#define INT_LEAST32_WIDTH INT32_WIDTH
#define INT_LEAST64_WIDTH INT64_WIDTH

#define UINT_LEAST8_WIDTH  UINT8_WIDTH
#define UINT_LEAST16_WIDTH UINT16_WIDTH
#define UINT_LEAST32_WIDTH UINT32_WIDTH
#define UINT_LEAST64_WIDTH UINT64_WIDTH

#define INT_FAST8_WIDTH  INT8_WIDTH
#define INT_FAST16_WIDTH INT16_WIDTH
#define INT_FAST32_WIDTH INT32_WIDTH
#define INT_FAST64_WIDTH INT64_WIDTH

#define UINT_FAST8_WIDTH  UINT8_WIDTH
#define UINT_FAST16_WIDTH UINT16_WIDTH
#define UINT_FAST32_WIDTH UINT32_WIDTH
#define UINT_FAST64_WIDTH UINT64_WIDTH

#define INTPTR_WIDTH (0x20)

#define UINTPTR_WIDTH (0x20)

#define INTMAX_WIDTH (0x40)

#define UINTMAX_WIDTH (0x40)

#define PTRDIFF_WIDTH (0x20)

#define SIG_ATOMIC_WIDTH (0x20)

#define SIZE_WIDTH (0x20)

#define WCHAR_WIDTH (0x20)

#define INT8_C( _val) (_val)
#define INT16_C(_val) (_val)
#define INT32_C(_val) (_val)
#define INT64_C(_val) (_val##ll)

#define UINT8_C( _val) (_val##u)
#define UINT16_C(_val) (_val##u)
#define UINT32_C(_val) (_val##u)
#define UINT64_C(_val) (_val##ull)

#define INTMAX_C(_val) (_val##ll)

#define UINTMAX_C(_val) (_val##ull)

#define INT8_MAX   ax_maxval_sc
#define INT16_MAX  ax_maxval_s
#define INT32_MAX  ax_maxval_i
#define INT64_MAX  ax_maxval_ll
#define UINT8_MAX  ax_maxval_uc
#define UINT16_MAX ax_maxval_us
#define UINT32_MAX ax_maxval_ui
#define UINT64_MAX ax_maxval_ull

#define INT_LEAST8_MAX   INT8_MAX
#define INT_LEAST16_MAX  INT16_MAX
#define INT_LEAST32_MAX  INT32_MAX
#define INT_LEAST64_MAX  INT64_MAX
#define UINT_LEAST8_MAX  UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#define INT_FAST8_MAX   INT8_MAX
#define INT_FAST16_MAX  INT16_MAX
#define INT_FAST32_MAX  INT32_MAX
#define INT_FAST64_MAX  INT64_MAX
#define UINT_FAST8_MAX  UINT8_MAX
#define UINT_FAST16_MAX UINT16_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define INTPTR_MAX  ax_maxval_i
#define UINTPTR_MAX ax_maxval_ui

#define INTMAX_MAX  ax_maxval_ll
#define UINTMAX_MAX ax_maxval_ull

#define PTRDIFF_MAX ax_maxval_i

#define SIG_ATOMIC_MAX ax_maxval_ui

#define SIZE_MAX ax_maxval_ui

#define WCHAR_MAX ax_maxval_ui

#define INT8_MIN  ax_minval_sc
#define INT16_MIN ax_minval_s
#define INT32_MIN ax_minval_i
#define INT64_MIN ax_minval_ll

#define INT_LEAST8_MIN  INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

#define INT_FAST8_MIN  INT8_MIN
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN

#define INTPTR_MIN ax_minval_i

#define INTMAX_MIN ax_minval_ll

#define PTRDIFF_MIN ax_minval_i

#define SIG_ATOMIC_MIN ax_minval_ui

#define WCHAR_MIN ax_minval_ui
#define WINT_MIN ax_minval_ui

typedef ax_i8s  int8_t;
typedef ax_i01s int16_t;
typedef ax_i02s int32_t;
typedef ax_i04s int64_t;

typedef ax_i8  uint8_t;
typedef ax_i01 uint16_t;
typedef ax_i02 uint32_t;
typedef ax_i04 uint64_t;

typedef int8_t  int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t  uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int8_t  int_fast8_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint8_t  uint_fast8_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef int32_t  intptr_t;
typedef uint32_t uintptr_t;

typedef long long          intmax_t;
typedef unsigned long long uintmax_t;

#endif
