/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */


/*
struct Cli {

    #[arg(short, long)]
    path: std::path::PathBuf,

    #[arg(short, long, default_value_t = String::from("1M"))]
    #[arg(help = "Memory size")]
    memory: String,
}

fn main() {
    let cli = Cli::parse();

    let _mem = Memory::new(cli.memory);
    let _processor_state = ProcessorState::new();
}
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "version.h"


#ifdef DEBUG
#include "util-debug.h"
#endif


// MACRO VALUES ////////////////////////////////////////////////////////////////

#define  FLAG_LENGTH_STRING  3


// COMMAND NAMES and HANDLERS //////////////////////////////////////////////////

static const char FLAG_VERSION [FLAG_LENGTH_STRING] = "-v";
static void command_version(void)
{
        printf("%s %s\n", PROGRAM_NAME, PROGRAM_VERSION);
}


// ENTRY POINT /////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
#ifdef DEBUG
        debug_print_prefix();
        printf("Invoked as: '%s'\n", argv[0]);
        if (argc > 1) {
                debug_print_prefix();
                printf("Options (%d) :", argc - 1);
                for (int i = 1; i < argc; i++) {
                        printf(" '%s'", argv[i]);
                }
                printf("\n");
        }
#endif

        if (argc == 2) {
                if (strcmp(FLAG_VERSION, argv[1]) == STRCMP_EQUAL) {
                        command_version();
                        exit(RETURN_CODE_SUCCESS);
                }
                else {
                        printf("Unrecognized command line argument (%s)\n", argv[1]);
                        exit(RETURN_CODE_ERROR);
                }
        }
        else if (argc > 2) {
                printf("Too many command line arguments (%d)\n", argc - 1);
                exit(RETURN_CODE_ERROR);
        }

        // printf("Welcome to %s - an esoteric programming language\n", PROGRAM_NAME);

        printf("Thank you for using %s!\n", PROGRAM_NAME);

        return RETURN_CODE_SUCCESS;
}
