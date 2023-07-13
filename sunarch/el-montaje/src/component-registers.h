/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef EL_MONTAJE_COMPONENT_REGISTERS_H
#define EL_MONTAJE_COMPONENT_REGISTERS_H

#include <stdint.h>

#define  REGISTER_COUNT  16

extern int64_t registers_get_value_by_name(char *register_name);
extern void registers_set_value_by_name(char *register_name, int64_t value);

extern void registers_serialize(int64_t *register_values);
extern void registers_deserialize(int64_t new_values[REGISTER_COUNT]);

#endif // ndef EL_MONTAJE_COMPONENT_REGISTERS_H
