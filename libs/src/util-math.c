/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdint.h>


uint32_t pow_uint32(uint32_t base, uint32_t exponent)
{
        if (exponent == 0) {
                return 1;
        }

        uint32_t result = base;

        for (uint32_t i = 2; i <= exponent; i++) {
                result *= base;
        }

        return result;
}
