/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef EL_MONTAJE_INSTRUCTIONS_H
#define EL_MONTAJE_INSTRUCTIONS_H

struct Instruction;

extern const struct Instruction no_operation;
extern const struct Instruction add;
extern const struct Instruction subtract;
extern const struct Instruction multiply;
extern const struct Instruction divide;

#endif // ndef EL_MONTAJE_INSTRUCTIONS_H
