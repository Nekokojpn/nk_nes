#include "cpu_inst.hpp"

void define_instructions() {

   //ADC - Add Memory to Accumulator with Carry
   ADD_INSTRUCTION(0x69, Op::ADC, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x65, Op::ADC, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x75, Op::ADC, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x6D, Op::ADC, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x7D, Op::ADC, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0x79, Op::ADC, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x61, Op::ADC, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x71, Op::ADC, AddressingMode::IndirectIndexY, 2, 5);

   //AND AND Memory with Accumulator
   ADD_INSTRUCTION(0x29, Op::AND, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x25, Op::AND, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x35, Op::AND, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x2D, Op::AND, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x3D, Op::AND, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0x39, Op::AND, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x21, Op::AND, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x31, Op::AND, AddressingMode::IndirectIndexY, 2, 5);

   //ASL Shift Left One Bit (Memory or Accumulator)
   ADD_INSTRUCTION(0x0A, Op::ASL, AddressingMode::Accumulator, 1, 2);
   ADD_INSTRUCTION(0x06, Op::ASL, AddressingMode::ZeroPage, 2, 5);
   ADD_INSTRUCTION(0x16, Op::ASL, AddressingMode::ZeroPageIndexX, 2, 6);
   ADD_INSTRUCTION(0x0E, Op::ASL, AddressingMode::Absolute, 3, 6);
   ADD_INSTRUCTION(0x1E, Op::ASL, AddressingMode::AbsoluteIndexX, 3, 7);

   //BCC Branch on Carry Clear
   ADD_INSTRUCTION(0x90, Op::BCC, AddressingMode::Relative, 2, 2);

   //BCS Branch on Carry  Set
   ADD_INSTRUCTION(0xB0, Op::BCS, AddressingMode::Relative, 2, 2);

   //BEQ Branch on Result Zero
   ADD_INSTRUCTION(0xF0, Op::BEQ, AddressingMode::Relative, 2, 2);

   //BIT Test Bits in Memory with Accumulator
   ADD_INSTRUCTION(0x24, Op::BIT, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x2C, Op::BIT, AddressingMode::Absolute, 3, 4);

   //BMI Branch on Result Minus
   ADD_INSTRUCTION(0x30, Op::BMI, AddressingMode::Relative, 2, 2);

   //BNE Branch on Result not Zero
   ADD_INSTRUCTION(0xD0, Op::BNE, AddressingMode::Relative, 2, 2);

   //BPL Branch on Result Plus
   ADD_INSTRUCTION(0x10, Op::BPL, AddressingMode::Relative, 2, 2);

   //BRK Force Break
   ADD_INSTRUCTION(0x00, Op::BRK, AddressingMode::Implied, 1, 7);

   //BVS Branch on Overflow Set
   ADD_INSTRUCTION(0x70, Op::BVS, AddressingMode::Relative, 2, 2);

   //CLC Clear Carry Flag
   ADD_INSTRUCTION(0x18, Op::CLC, AddressingMode::Implied, 1, 2);

   //CLD Clear Decimal Mode
   ADD_INSTRUCTION(0xD8, Op::CLD, AddressingMode::Implied, 1, 2);

   //CLI Clear Interrupt Disable Bit
   ADD_INSTRUCTION(0x58, Op::CLI, AddressingMode::Implied, 1, 2);

   //CLV Clear Overflow Flag
   ADD_INSTRUCTION(0xB8, Op::CLV, AddressingMode::Implied, 1, 2);

   //CMP Compare Memory with Accumulator
   ADD_INSTRUCTION(0xC9, Op::CMP, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xC5, Op::CMP, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xD5, Op::CMP, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0xCD, Op::CMP, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0xDD, Op::CMP, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0xD9, Op::CMP, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0xC1, Op::CMP, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0xD1, Op::CMP, AddressingMode::IndirectIndexY, 2, 5);

   //CPX Compare Memory and Index X
   ADD_INSTRUCTION(0xE0, Op::CPX, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xE4, Op::CPX, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xEC, Op::CPX, AddressingMode::Absolute, 3, 4);

   //CPY Compare Memory and Index Y
   ADD_INSTRUCTION(0xC0, Op::CPY, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xC4, Op::CPY, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xCC, Op::CPY, AddressingMode::Absolute, 3, 4);

   //DEC Decrement Memory by One
   ADD_INSTRUCTION(0xC6, Op::DEC, AddressingMode::ZeroPage, 2, 5);
   ADD_INSTRUCTION(0xD6, Op::DEC, AddressingMode::ZeroPageIndexX, 2, 6);
   ADD_INSTRUCTION(0xCE, Op::DEC, AddressingMode::Absolute, 3, 6);
   ADD_INSTRUCTION(0xDE, Op::DEC, AddressingMode::AbsoluteIndexX, 3, 7);

   //DEX Decrement Index X by One
   ADD_INSTRUCTION(0xCA, Op::DEX, AddressingMode::Implied, 1, 2);

   //DEY Decrement Index Y by One
   ADD_INSTRUCTION(0x88, Op::DEY, AddressingMode::Implied, 1, 2);

   //EOR Exclusive-OR Memory with Accumulator
   ADD_INSTRUCTION(0x49, Op::EOR, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x45, Op::EOR, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x55, Op::EOR, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x4D, Op::EOR, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x5D, Op::EOR, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0x59, Op::EOR, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x41, Op::EOR, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x51, Op::EOR, AddressingMode::IndirectIndexY, 2, 5);

   //INC Increment Memory by One
   ADD_INSTRUCTION(0xE6, Op::INC, AddressingMode::ZeroPage, 2, 5);
   ADD_INSTRUCTION(0xF6, Op::INC, AddressingMode::ZeroPageIndexX, 2, 6);
   ADD_INSTRUCTION(0xEE, Op::INC, AddressingMode::Absolute, 3, 6);
   ADD_INSTRUCTION(0xFE, Op::INC, AddressingMode::AbsoluteIndexX, 3, 7);

   //INX Increment Index X by One
   ADD_INSTRUCTION(0xE8, Op::INX, AddressingMode::Implied, 1, 2);

   //INY Increment Index Y by One
   ADD_INSTRUCTION(0xC8, Op::INY, AddressingMode::Implied, 1, 2);
   

   //ORA - OR Memory with accumulator
   ADD_INSTRUCTION(0x09, Op::ORA, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x05, Op::ORA, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x15, Op::ORA, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x0D, Op::ORA, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x1D, Op::ORA, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0x19, Op::ORA, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x01, Op::ORA, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x11, Op::ORA, AddressingMode::IndirectIndexY, 2, 5);
}