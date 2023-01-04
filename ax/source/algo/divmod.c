/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0>.
*/

#include <ax/priv.h>

#include <ax/algo.h>

ax_quotrem ax_divmod(ax_i02 const _num,ax_i02 const _den) {
	if (__builtin_expect(_den == 0x0,0x0)) {
        ax_done(ax_err_divzero);
    }
	ax_quotrem quotrem;
	for (quotrem = (ax_quotrem){.quot = 0x0u,.rem = _num};quotrem.rem >= _den;++quotrem.quot,quotrem.rem -= _den) {}
	return quotrem;
}
