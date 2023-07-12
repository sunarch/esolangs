/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
use std::collections::HashMap;

use crate::esolangs::el_montaje::tools::number;


pub struct Memory {
    _size: u32,
    _layout: HashMap<u32, i64>,
}

impl Memory {
    pub fn new(size: String) -> Self {

        return Memory {
            _size: number::int_from_size(size.as_str()).expect("Checked at argument"),
            _layout: HashMap::new(),
        };
    }

    pub fn last_address(&self) -> u32 {
        return self._size;
    }

    pub fn get(&self, address: &str) -> Result<Option<i64>, &'static str> {

        let real_address = match Self::_translate_address(address) {
            Err(message) => {return Err(message)},
            Ok(value) => value,
        };

        if real_address > self._size {
            return Err("Attempted read on uninitialized memory");
        }

        return match self._layout.get(&real_address) {
            None => Ok(None),
            Some(value) => Ok(Some(value.to_owned())),
        }
    }

    pub fn set(&mut self, address: &str, value: i64) -> Result<(), &'static str> {

        let real_address = match Self::_translate_address(address) {
            Err(message) => {return Err(message)},
            Ok(value) => {value},

        };

        if real_address > self._size {
            return Err("Memory address out of bounds");
        }

        self._layout.insert(real_address, value);

        return Ok(());
    }

    fn _translate_address(address: &str) -> Result<u32, &'static str> {

        let s = String::from(address);
        let len = s.len();
        if len < 2 {
            return Err("Memory addresses too short");
        }
        if &s[0..1] != "@" {
            return Err("Memory addresses must begin with '@'");
        }

        return match number::int_from_string(&s[1..len]) {
            Err(_) => Err("Number conversion error"),
            Ok(value) => Ok(value as u32),
        };
    }
}
*/
