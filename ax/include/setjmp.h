/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#if !defined(__ax_hdr_setjmp)
#define __ax_hdr_setjmp

#include <ax/bs.h>

#define __STDC_VERSION_SETJMP_H__ (202311l)

typedef ax_i02 jmp_buf[0xBu];

int setjmp(jmp_buf env);

[[noreturn]] void longjmp(jmp_buf env,int val);

#endif
