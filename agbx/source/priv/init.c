/*
	Copyright 2022 Gabriel Jensen.
	This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
	If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <agbx/priv.h>

agbx_err agbx_main(void);

[[noreturn]] void __agbx_init(void) {
	agbx_err const err = agbx_main();
	agbx_done(err);
}
