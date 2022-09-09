/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

agbx_i10 agbx_get10(agbx_i20 const _addr) {
	agbx_i10 val;
	__asm__ ( \
		"ldrh %0,[%1]"
		: "=r" (val)
		: "r" (_addr)
		: "memory"
	);
	return val;
}

agbx_i20 agbx_get20(agbx_i20 const _addr) {
	agbx_i20 val;
	__asm__ ( \
		"ldr %0,[%1]"
		: "=r" (val)
		: "r" (_addr)
		: "memory"
	);
	return val;
}

agbx_i8 agbx_get8(agbx_i20 const _addr) {
	agbx_i8 val;
	__asm__ ( \
		"ldrb %0,[%1]"
		: "=r" (val)
		: "r" (_addr)
		: "memory"
	);
	return val;
}
