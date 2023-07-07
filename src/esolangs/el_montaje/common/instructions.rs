// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

pub struct Instruction {
    opcode: u32,
    syntax_short: &'static str,
    syntax_long: &'static str,
    operands: u8,
}

impl Instruction {
    pub fn no_operation() -> Self {
        // No operation

        return Instruction {
            opcode: 0x0,
            syntax_short: "NOP",
            syntax_long: "no-operation",
            operands: 0,
        };
    }

    pub fn add() -> Self {
        // Addition

        return Instruction {
            opcode: 0x0,
            syntax_short: "ADD",
            syntax_long: "add",
            operands: 2,
        };
    }

    pub fn subtract() -> Self {
        // Subtraction

        return Instruction {
            opcode: 0x0,
            syntax_short: "SUB",
            syntax_long: "subtract",
            operands: 2,
        };
    }

    pub fn multiply() -> Self {
        // Multiply

        return Instruction {
            opcode: 0x0,
            syntax_short: "MUL",
            syntax_long: "multiply",
            operands: 2,
        };
    }

    pub fn divide() -> Self {
        // Divide

        return Instruction {
            opcode: 0x0,
            syntax_short: "DIV",
            syntax_long: "divide",
            operands: 2,
        };
    }
}


/*

ABS     Absolute value

CALL 	Call procedure
RET     Return from procedure

PUSH 	Push data onto stack
POP 	Pop data from stack

OR 	    Logical OR
AND 	Logical AND
XOR 	Exclusive OR
NOT 	Negate the operand, logical NOT

NEG 	Two's complement negation

BOR     | Bitwise Inclusive Or.
BND     & Bitwise And.
BXR     ^ Bitwise Exclusive Or.
BNT     ! Bitwise Or Not.

CMP 	Compare operands

INC 	Increment by 1
DEC 	Decrement by 1

MOV 	Move
SWAP
XCHG    Exchange register content / Values

ROL 	Rotate left
ROR 	Rotate right

SAL 	Shift Arithmetically left (signed shift left)
SAR 	Shift Arithmetically right (signed shift right)
SHL 	Shift left (unsigned shift left)
SHR 	Shift right (unsigned shift right)

INT 	Call to interrupt
IRET 	Return from interrupt
HLT 	Enter halt state

LOOP/LOOPx 	Loop control 	(LOOPE, LOOPNE, LOOPNZ, LOOPZ)
                             if (x && --CX) goto lbl;
IN 	Input from port
OUT 	Output to port

JMP 	Jump
Jcc 	Jump if condition
GT greater than
LT less than
GE greater than or equal
LE less than or equal
EQ equal
NE not equal


zero (implies equal for sub/cmp)
JZ; JNZ
zero; not zero

negative (N), sign (S), or minus (M)
JS; JNS
negative; not negative

arithmetic overflow (flag called O or V)
JO; JNO
overflow; not overflow

carry (from add, cmp, shift, etc.)
JC; JNC
carry; not carry

unsigned below (lower)
JB
borrow

unsigned below or equal (lower or same)
JBE
borrow or zero

unsigned above or equal (higher or same)
JAE
not borrow

unsigned above (higher)
JA
not borrow and not zero

signed less than
JL
sign≠overflow

signed less or equal
JLE
(sign≠overflow) or zero

signed greater or equal
JGE
sign=overflow

signed greater than
JG
(sign=overflow) and not zero

*/
