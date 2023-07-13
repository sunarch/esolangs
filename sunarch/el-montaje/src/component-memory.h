/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef EL_MONTAJE_COMPONENT_MEMORY_H
#define EL_MONTAJE_COMPONENT_MEMORY_H

extern int64_t memory_get_by_address(char *address);
extern void memory_set_by_address(char *address, int64_t value);

#endif // ndef EL_MONTAJE_COMPONENT_MEMORY_H
