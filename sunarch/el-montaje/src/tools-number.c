/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "tools-number.h"
#include "util-math.h"


uint64_t int_from_string(char *number_string)
{
        char scan_format_oct[] = "..[^0123456789]%o";
        char scan_format_dec[] = "..[^0123456789]%d";
        char scan_format_hex[] = "..[^0123456789]%x";
        char *scan_format = scan_format_dec;

        if (number_string[0] == '0') {
                switch (number_string[1]) {
                        case 'o':
                                scan_format = scan_format_oct;
                                break;
                        case 'x':
                                scan_format = scan_format_hex;
                                break;
                        default:
                                printf("Number format not recognized: %s", number_string);
                                exit(RETURN_CODE_ERROR);
                }
        }

        uint32_t number_value;
        if (1 != sscanf(number_string, scan_format, &number_value)) {
                printf("Badly formatted size number: '%s'", number_string);
                exit(RETURN_CODE_ERROR);
        }

        return number_value;
}


static uint32_t modifier_to_factor(char factor)
{
        switch (factor) {
                case 'K':
                        return 1;
                        break;
                case 'M':
                        return 2;
                        break;
                case 'G':
                        return 3;
                        break;
                default:
                        printf("Illegal size modifier '%c' (Valid: K/M/G)", factor);
                        exit(RETURN_CODE_ERROR);
        }
}


uint32_t int_from_size(char *size_string)
{
        uint32_t count;
        if (1 != sscanf(size_string, "[^0123456789]%u.", &count)) {
                printf("Badly formatted size number: '%s'", size_string);
                exit(RETURN_CODE_ERROR);
        }
        char modifier_char = size_string[-1];
        uint32_t modifier = modifier_to_factor(modifier_char);


        uint8_t modifier_base = 2;
        uint32_t modifier_exponent = modifier * 10;
        uint32_t modifier_powered = pow_uint32(modifier_base, modifier_exponent);
        uint32_t total = count * modifier_powered;

        return total;
}
