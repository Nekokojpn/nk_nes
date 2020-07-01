#include "cpu_inst.hpp"

void define_instructions() {
   ADD_INSTRUCTION(0x00, Op::BRK, AddressingMode::Implied, 1, 7);

   //ADC - Add Memory to Accumulator with Carry
   ADD_INSTRUCTION(0x69, Op::ADC, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x65, Op::ADC, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x75, Op::ADC, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x6D, Op::ADC, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x7D, Op::ADC, AddressingMode::AbsoludeIndexX, 3, 4);
   ADD_INSTRUCTION(0x79, Op::ADC, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x61, Op::ADC, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x71, Op::ADC, AddressingMode::IndirectIndexY, 2, 5);

   //AND AND Memory with Accumulator
   ADD_INSTRUCTION(0x29, Op::AND, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x25, Op::AND, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x35, Op::AND, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x2D, Op::AND, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x3D, Op::AND, AddressingMode::AbsoludeIndexX, 3, 4);
   ADD_INSTRUCTION(0x39, Op::AND, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x21, Op::AND, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x31, Op::AND, AddressingMode::IndirectIndexY, 2, 5);

   //ORA - OR Memory with accumulator
   ADD_INSTRUCTION(0x09, Op::ORA, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x05, Op::ORA, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x15, Op::ORA, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x0D, Op::ORA, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x1D, Op::ORA, AddressingMode::AbsoludeIndexX, 3, 4);
   ADD_INSTRUCTION(0x19, Op::ORA, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x01, Op::ORA, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x11, Op::ORA, AddressingMode::IndirectIndexY, 2, 5);
}