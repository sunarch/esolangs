/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
use std::collections::HashMap;

use crate::esolangs::el_montaje::components::register::Register;


const REGISTER_NAMES: [(&'static str,u8);16] = [
// general purpose registers
("rxa", 0x0),
("rxb", 0x1),
("rxc", 0x2),
("rxd", 0x3),

// operation-related registers
("rra", 0x4), // result of arithmetic, part 1 of 2
("rrb", 0x5), // result of arithmetic, part 2 of 2
("rrc", 0x6), //result of comparison

// segments - data
("sdb", 0x7), //segment: data - base
("slb", 0x8), //segment: label - base

// segments - heap
("shb", 0x9), // base
("sht", 0xA), // top

// segments - stack
("ssb", 0xB), // base = memory size
("sst", 0xC), // top

// pointers
("pci", 0xD), // current instruction
("prt", 0xE), // return position

// unassigned
("opc", 0xF), // internal operation cache
];

pub struct ProcessorState {
    _registers: HashMap<u8, Register>
}

impl ProcessorState {
    pub fn new() -> Self {

        let mut registers: HashMap<u8, Register> = HashMap::new();
        let _ = REGISTER_NAMES.iter().map(|(name, index)| {
            let index_owned = index.to_owned();
            registers.insert(index_owned, Register::new(index_owned, name));
        });

        return ProcessorState {
            _registers: registers,
        };
    }

    fn register_id_by_name(&self, register_name: &str) -> Result<u8, String> {

        for (name, index) in REGISTER_NAMES {
            if name == register_name {
                return Ok(index);
            }
        }

        return Err(format!("Register '{}' not found", register_name));
    }

    fn get_by_id(&self, register_id: u8) -> Result<i64, String> {

        return match self._registers.get(&register_id) {
            None => Err(format!("Register with ID '{}' not found", register_id)),
            Some(register) => Ok(register.value()),
        };
    }

    pub fn get(&self, register_name: &str) -> Result<i64, String> {

        return match self.register_id_by_name(register_name) {
            Err(message) => Err(message),
            Ok(register_id) => self.get_by_id(register_id),
        };
    }

    fn set_by_id(&mut self, register_id: u8, value: i64) -> Result<i64, String> {

        let register: &mut Register = match self._registers.get_mut(&register_id) {
            None => { return Err(format!("Register with ID '{}' not found", register_id)); },
            Some(register) => register,
        };

        return match register.set(value) {
            Err(_) => Err(format!("Setting of register with ID '{register_id}' unsuccessful")),
            Ok(value) => Ok(value),
        };
    }

    pub fn set(&mut self, register_name: &str, value: i64) -> Result<i64, String> {

        return match self.register_id_by_name(register_name) {
            Err(message) => Err(message),
            Ok(register_id) => self.set_by_id(register_id, value),
        };
    }

    pub fn serialize(&self) -> Vec<i64> {

        let mut vec: Vec<i64> = Vec::new();
        for (_, register_id) in REGISTER_NAMES {
            vec.push(self.get_by_id(register_id).expect("Created from source"));
        }

        return vec;
    }

    pub fn deserialize(&mut self, values: Vec<i64>) -> Result<(), &'static str> {

        if values.len() > REGISTER_NAMES.len() {
            return Err("Tried to deserialize more values than available registers");
        }
        if values.len() < REGISTER_NAMES.len() {
            return Err("Tried to deserialize less values than available registers");
        }

        for (_, register_id) in REGISTER_NAMES {
            self.set_by_id(register_id, values[register_id as usize]).expect("Length for IDs checked");
        }

        return Ok(());
    }
}
*/
