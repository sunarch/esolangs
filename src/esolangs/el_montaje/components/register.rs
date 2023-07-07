// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#[derive(Clone)]
pub struct Register {
    _id_code: u8,
    _name: &'static str,
    _value: i64,
}

impl Register {
    pub fn new(id_code: u8, name: &'static str) -> Self {
        return Register {
            _id_code: id_code,
            _name: name,
            _value: 0x0,
        };
    }

    pub fn id_code(&self) -> u8 {
        return self._id_code;
    }

    pub fn name(&self) -> &'static str {
        return self._name;
    }

    pub fn value(&self) -> i64 {
        return self._value;
    }

    pub fn set(&mut self, value: i64) -> Result<i64, ()> {
        self._value = value;

        return Ok(value);
    }
}
