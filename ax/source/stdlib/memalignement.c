/*
	Copyright 2022-2023 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t memalignment(void const * const _p) {
	if (_p == nullptr) {
		return 0x0u;
	}
	uintptr_t const ptr = (uintptr_t)_p;
	size_t algn;
	for (algn = alignof (max_align_t);(ptr & (algn - 0x1u)) == 0x0u;algn >>= 0x1u) {} /* Check if the pointer value is a multiple of the alignment. We know that all alignments are powers of two. */
	return algn;
}
