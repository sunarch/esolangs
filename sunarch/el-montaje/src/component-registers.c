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
#include "component-registers.h"


typedef struct {
        uint8_t id_code;
        char name[4];
        int64_t value;
} Register;


static Register registers[REGISTER_COUNT] = {
        // general purpose registers
        {0x0, "rxa", 0x0},
        {0x1, "rxb", 0x0},
        {0x2, "rxc", 0x0},
        {0x3, "rxd", 0x0},

        // operation-related registers
        {0x4, "rra", 0x0},  // result of arithmetic, part 1 of 2
        {0x5, "rrb", 0x0},  // result of arithmetic, part 2 of 2
        {0x6, "rrc", 0x0},  //result of comparison

        // segments - data
        {0x7, "sdb", 0x0},  //segment: data - base
        {0x8, "slb", 0x0},  //segment: label - base

        // segments - heap
        {0x9, "shb", 0x0},  // base
        {0xA, "sht", 0x0},  // top

        // segments - stack
        {0xB, "ssb", 0x0},  // base = memory size
        {0xC, "sst", 0x0},  // top

        // pointers
        {0xD, "pci", 0x0},  // current instruction
        {0xE, "prt", 0x0},  // return position

        // unassigned
        {0xF, "opc", 0x0}   // internal operation cache
};


static uint8_t registers_id_by_name(char *register_name)
{
        for (uint8_t i = 0; i < REGISTER_COUNT; i++) {
                if (strcmp(register_name, registers[i].name) == STRCMP_EQUAL) {
                        return registers[i].id_code;
                }
        }

        printf("Register '%s' not found", register_name);
        exit(RETURN_CODE_ERROR);
}


static int64_t registers_get_value_by_id(uint8_t register_id)
{
        if (register_id > REGISTER_COUNT) {
                printf("Register with ID doesn't exist: %d > %d", register_id, REGISTER_COUNT);
                exit(RETURN_CODE_ERROR);
        }

        return registers[register_id].value;
}


int64_t registers_get_value_by_name(char *register_name)
{
        uint8_t register_id = registers_id_by_name(register_name);

        return registers_get_value_by_id(register_id);
}


static void registers_set_value_by_id(uint8_t register_id, int64_t value)
{
        registers[register_id].value = value;
}


void registers_set_value_by_name(char *register_name, int64_t value)
{
        uint8_t register_id = registers_id_by_name(register_name);

        registers_set_value_by_id(register_id, value);
}

void registers_serialize(int64_t *register_values)
{
        for (uint8_t i = 0; i < REGISTER_COUNT; i++) {
                register_values[i] = registers[i].value;
        }
}

void registers_deserialize(int64_t new_values[REGISTER_COUNT])
{
        /*
        if (value_count > REGISTER_COUNT) {
                printf("Tried to deserialize more values than available registers: %d > %d", value_count, REGISTER_COUNT);
                exit(RETURN_CODE_ERROR);
        }

        if (value_count < REGISTER_COUNT) {
                printf("Tried to deserialize fewer values than available registers: %d < >%d", value_count, REGISTER_COUNT);
                exit(RETURN_CODE_ERROR);
        }
        */

        for (uint8_t i = 0; i < REGISTER_COUNT; i++) {
                registers[i].value = new_values[i];
        }
}
