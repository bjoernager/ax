/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_stdbit)
#define __ax_hdr_stdbit

#include <ax/bs.h>

#define __STDC_VERSION_STDBIT_H__ (202311l)

#define __STDC_ENDIAN_LITTLE__ ax_minval_i
#define __STDC_ENDIAN_BIG__    ax_maxval_i
#define __STDC_ENDIAN_NATIVE__ (0x0) /* This CPU can use both. */

typedef ax_i02 size_t;

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

int stdc_leading_zerosuc( unsigned char      value);
int stdc_leading_zerosus( unsigned short     value);
int stdc_leading_zerosui( unsigned int       value);
int stdc_leading_zerosul( unsigned long      value);
int stdc_leading_zerosull(unsigned long long value);

int stdc_leading_onesuc( unsigned char      value);
int stdc_leading_onesus( unsigned short     value);
int stdc_leading_onesui( unsigned int       value);
int stdc_leading_onesul( unsigned long      value);
int stdc_leading_onesull(unsigned long long value);

int stdc_trailing_zerosuc( unsigned char      value);
int stdc_trailing_zerosus( unsigned short     value);
int stdc_trailing_zerosui( unsigned int       value);
int stdc_trailing_zerosul( unsigned long      value);
int stdc_trailing_zerosull(unsigned long long value);

int stdc_trailing_onesuc( unsigned char      value);
int stdc_trailing_onesus( unsigned short     value);
int stdc_trailing_onesui( unsigned int       value);
int stdc_trailing_onesul( unsigned long      value);
int stdc_trailing_onesull(unsigned long long value);

int stdc_first_leading_zerouc( unsigned char      value);
int stdc_first_leading_zerous( unsigned short     value);
int stdc_first_leading_zeroui( unsigned int       value);
int stdc_first_leading_zeroul( unsigned long      value);
int stdc_first_leading_zeroull(unsigned long long value);

int stdc_first_leading_oneuc( unsigned char      value);
int stdc_first_leading_oneus( unsigned short     value);
int stdc_first_leading_oneui( unsigned int       value);
int stdc_first_leading_oneul( unsigned long      value);
int stdc_first_leading_oneull(unsigned long long value);

int stdc_first_trailing_zerouc( unsigned char      value);
int stdc_first_trailing_zerous( unsigned short     value);
int stdc_first_trailing_zeroui( unsigned int       value);
int stdc_first_trailing_zeroul( unsigned long      value);
int stdc_first_trailing_zeroull(unsigned long long value);

int stdc_first_trailing_oneuc( unsigned char      value);
int stdc_first_trailing_oneus( unsigned short     value);
int stdc_first_trailing_oneui( unsigned int       value);
int stdc_first_trailing_oneul( unsigned long      value);
int stdc_first_trailing_oneull(unsigned long long value);

int stdc_count_zerosuc( unsigned char      value);
int stdc_count_zerosus( unsigned short     value);
int stdc_count_zerosui( unsigned int       value);
int stdc_count_zerosul( unsigned long      value);
int stdc_count_zerosull(unsigned long long value);

int stdc_count_onesuc( unsigned char      value);
int stdc_count_onesus( unsigned short     value);
int stdc_count_onesui( unsigned int       value);
int stdc_count_onesul( unsigned long      value);
int stdc_count_onesull(unsigned long long value);

bool stdc_has_single_bituc( unsigned char      value);
bool stdc_has_single_bitus( unsigned short     value);
bool stdc_has_single_bitui( unsigned int       value);
bool stdc_has_single_bitul( unsigned long      value);
bool stdc_has_single_bitull(unsigned long long value);

int stdc_bit_widthuc( unsigned char      value);
int stdc_bit_widthus( unsigned short     value);
int stdc_bit_widthui( unsigned int       value);
int stdc_bit_widthul( unsigned long      value);
int stdc_bit_widthull(unsigned long long value);

unsigned char      stdc_bit_flooruc( unsigned char      value);
unsigned short     stdc_bit_floorus( unsigned short     value);
unsigned int       stdc_bit_floorui( unsigned int       value);
unsigned long      stdc_bit_floorul( unsigned long      value);
unsigned long long stdc_bit_floorull(unsigned long long value);

unsigned char      stdc_bit_ceiluc( unsigned char      value);
unsigned short     stdc_bit_ceilus( unsigned short     value);
unsigned int       stdc_bit_ceilui( unsigned int       value);
unsigned long      stdc_bit_ceilul( unsigned long      value);
unsigned long long stdc_bit_ceilull(unsigned long long value);

#endif
