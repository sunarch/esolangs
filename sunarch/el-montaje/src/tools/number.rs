// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

use std::num::ParseIntError;


pub fn int_from_string(number_string: &str) -> Result<i64, &'static str> {

    let length: usize = number_string.len();
    let number_indetifier:&str = &number_string[0..2];
    let number_identified_value:&str = &number_string[2..length];

    let converted: Result<i64, ParseIntError> = match number_indetifier {
        "0o" => i64::from_str_radix(number_identified_value, 8),
        "0x" => i64::from_str_radix(number_identified_value, 16),
        _ => i64::from_str_radix(number_string, 10),
    };

    return match converted {
        Err(_) => Err("String to int conversion failed"),
        Ok(value) => Ok(value),
    };
}


fn modifier_to_factor(factor: &str) -> Result<u32, String> {

    return match factor {
        "K" => Ok(1),
        "M" => Ok(2),
        "G" => Ok(3),
        &_ => Err(format!("Illegal size modifier '{}' (Valid: K/M/G)", factor)),
    };
}

pub fn int_from_size(size_string: &str) -> Result<u32, String> {

    let length: usize = size_string.len();
    let count: &str = &size_string[0..length-1];
    let modifier: &str = &size_string[length-1..length];

    let count_value: u32 = match u32::from_str_radix(count, 10) {
        Err(_) => {return Err(format!("Badly formatted size number: '{}'", count))},
        Ok(value) => {value},
    };

    let modifier_value: u32 = match modifier_to_factor(modifier) {
        Err(message) => {return Err(message)},
        Ok(value) => {value},
    };

    let modifier_base: u32 = 2;
    let modifier_power: u32 = modifier_value * 10;
    let modifier_powered: u32 = modifier_base.pow(modifier_power);
    let total: u32 = count_value * modifier_powered;

    return Ok(total);
}
