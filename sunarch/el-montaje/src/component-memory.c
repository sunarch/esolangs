/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "component-memory.h"
#include "reader.h"
#include "tools-number.h"


#define  MEMORY_SIZE  UINT8_MAX


struct Memory
{
        uint8_t size;
        int64_t cells[MEMORY_SIZE];
};


static struct Memory memory = {
        .size = MEMORY_SIZE,
        .cells = {0}
};

uint8_t memory_get_address_last(void)
{
        return MEMORY_SIZE - 1;
}


static uint8_t memory_translate_address(char *address)
{
        unsigned int len = (unsigned int) strlen(address);

        if (len < 2) {
                printf("Memory addresses too short");
                exit(RETURN_CODE_ERROR);
        }

        if (address[0] != PREFIX_ADDRESS) {
                printf("Memory addresses must begin with '@'");
                exit(RETURN_CODE_ERROR);
        }

        int address_number;
        if (1 != sscanf(address, "@[^0123456789]%d", &address_number)) {
                printf("Invalid memory address: %s", address);
                exit(RETURN_CODE_ERROR);
        }

        return (uint8_t) address_number;
}


int64_t memory_get_by_address(char *address)
{
        uint8_t real_address = memory_translate_address(address);

        if (real_address > memory.size) {
                printf("Attempted read above memory size: %d > %d", real_address, memory.size);
                exit(RETURN_CODE_ERROR);
        }

        return memory.cells[real_address];
}


void memory_set_by_address(char *address, int64_t value)
{
        uint8_t real_address = memory_translate_address(address);

        if (real_address > memory.size) {
                printf("Attempted read above memory size: %d > %d", real_address, memory.size);
                exit(RETURN_CODE_ERROR);
        }

        memory.cells[real_address] = value;
}
