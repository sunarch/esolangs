/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "reader.h"


const char PREFIX_COMMENT  = ';';  // comments (line end)
const char PREFIX_REGISTER = '$';  // registers
const char PREFIX_ADDRESS  = '@';  // addresses
const char PREFIX_POINTER  = '*';  // pointers / variables
const char PREFIX_LABEL    = '#';  // labels
const char PREFIX_STRING   = '~';  // strings
