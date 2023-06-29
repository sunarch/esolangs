// -*- coding: utf-8, vim: expandtab:ts=4 -*-

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

use crate::esolangs::el_montaje::common::instructions::Instruction;
use crate::esolangs::el_montaje::components::processor_state::ProcessorState;


pub struct RegisterReference {
    _original: String,
    stack_frame: ProcessorState,
    reference: Instruction,
}

impl RegisterReference {
    pub fn new(original_text: &str, processor_state: ProcessorState) -> Self {
        let instruction = Instruction::no_operation();

        return RegisterReference {
            _original: original_text.to_owned(),
            stack_frame: processor_state,
            reference: instruction,
        };
    }
}
