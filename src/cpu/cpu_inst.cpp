#include "../common.hpp"

CPU6502Inst* decoder[256];

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

   //JMP Jump to New Location
   ADD_INSTRUCTION(0x4C, Op::JMP, AddressingMode::Absolute, 3, 3);
   ADD_INSTRUCTION(0x6C, Op::JMP, AddressingMode::Indirect, 3, 5);

   //JSR Jump to New Location Saving Return Address
   ADD_INSTRUCTION(0x20, Op::JSR, AddressingMode::Absolute, 3, 6);

   //LDA Load Accumulator with Memory
   ADD_INSTRUCTION(0xA9, Op::LDA, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xA5, Op::LDA, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xB5, Op::LDA, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0xAD, Op::LDA, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0xBD, Op::LDA, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0xB9, Op::LDA, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0xA1, Op::LDA, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0xB1, Op::LDA, AddressingMode::IndirectIndexY, 2, 5);

   //LDX Load Index X with Memory
   ADD_INSTRUCTION(0xA2, Op::LDX, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xA6, Op::LDX, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xB6, Op::LDX, AddressingMode::ZeroPageIndexY, 2, 4);
   ADD_INSTRUCTION(0xAE, Op::LDX, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0xBE, Op::LDX, AddressingMode::AbsoluteIndexY, 3, 4);

   //LDY Load Index Y with Memory
   ADD_INSTRUCTION(0xA0, Op::LDY, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xA4, Op::LDY, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xB4, Op::LDY, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0xAC, Op::LDY, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0xBC, Op::LDY, AddressingMode::AbsoluteIndexX, 3, 4);

   //LSR Shift One Bit Right (Memory or Accumulator)
   ADD_INSTRUCTION(0x4A, Op::LSR, AddressingMode::Accumulator, 1, 2);
   ADD_INSTRUCTION(0x46, Op::LSR, AddressingMode::ZeroPage, 2, 5);
   ADD_INSTRUCTION(0x56, Op::LSR, AddressingMode::ZeroPageIndexX, 2, 6);
   ADD_INSTRUCTION(0x4E, Op::LSR, AddressingMode::Absolute, 3, 6);
   ADD_INSTRUCTION(0x5E, Op::LSR, AddressingMode::AbsoluteIndexX, 3, 7);

   //NOP No Operation
   ADD_INSTRUCTION(0xEA, Op::NOP, AddressingMode::Implied, 1, 2);

   //ORA - OR Memory with accumulator
   ADD_INSTRUCTION(0x09, Op::ORA, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0x05, Op::ORA, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x15, Op::ORA, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x0D, Op::ORA, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x1D, Op::ORA, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0x19, Op::ORA, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0x01, Op::ORA, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x11, Op::ORA, AddressingMode::IndirectIndexY, 2, 5);

   //PHA Push Accumulator on Stack
   ADD_INSTRUCTION(0x48, Op::PHA, AddressingMode::Implied, 1, 3);

   //PHP Push Processor Status on Stack
   ADD_INSTRUCTION(0x08, Op::PHP, AddressingMode::Implied, 1, 3);

   //PLA Pull Accumulator from Stack
   ADD_INSTRUCTION(0x68, Op::PLA, AddressingMode::Implied, 1, 4);

   //PLP Pull Processor Status from Stack
   ADD_INSTRUCTION(0x28, Op::PLP, AddressingMode::Implied, 1, 4);

   //ROL Rotate One Bit Left (Memory or Acuumulator)
   ADD_INSTRUCTION(0x2A, Op::ROL, AddressingMode::Accumulator, 1, 2);
   ADD_INSTRUCTION(0x26, Op::ROL, AddressingMode::ZeroPage, 2, 5);
   ADD_INSTRUCTION(0x36, Op::ROL, AddressingMode::ZeroPageIndexX, 2, 6);
   ADD_INSTRUCTION(0x2E, Op::ROL, AddressingMode::Absolute, 3, 6);
   ADD_INSTRUCTION(0x3E, Op::ROL, AddressingMode::AbsoluteIndexX, 3, 7);

   //ROR Rotate One Bit Right (Memory or Accumulator)
   ADD_INSTRUCTION(0x6A, Op::ROR, AddressingMode::Accumulator, 1, 2);
   ADD_INSTRUCTION(0x66, Op::ROR, AddressingMode::ZeroPage, 2, 5);
   ADD_INSTRUCTION(0x76, Op::ROR, AddressingMode::ZeroPageIndexX, 2, 6);
   ADD_INSTRUCTION(0x6E, Op::ROR, AddressingMode::Absolute, 3, 6);
   ADD_INSTRUCTION(0x7E, Op::ROR, AddressingMode::AbsoluteIndexX, 3, 7);

   //RTI Return from Interrupt
   ADD_INSTRUCTION(0x40, Op::RTI, AddressingMode::Implied, 1, 6);

   //RTS Return from Subroutine
   ADD_INSTRUCTION(0x60, Op::RTS, AddressingMode::Implied, 1, 6);

   //SBC Subtract Memory from Accumulator With Borrow
   ADD_INSTRUCTION(0xE9, Op::SBC, AddressingMode::Immediate, 2, 2);
   ADD_INSTRUCTION(0xE5, Op::SBC, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0xF5, Op::SBC, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0xED, Op::SBC, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0xFD, Op::SBC, AddressingMode::AbsoluteIndexX, 3, 4);
   ADD_INSTRUCTION(0xF9, Op::SBC, AddressingMode::AbsoluteIndexY, 3, 4);
   ADD_INSTRUCTION(0xE1, Op::SBC, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0xF1, Op::SBC, AddressingMode::IndirectIndexY, 2, 5);

   //SEC Set Carry Flag
   ADD_INSTRUCTION(0x38, Op::SEC, AddressingMode::Implied, 1, 2);

   //SED Set Decimal Flag
   ADD_INSTRUCTION(0xF8, Op::SED, AddressingMode::Implied, 1, 2);

   //SEI Set Interrupt Disable Status
   ADD_INSTRUCTION(0x78, Op::SEI, AddressingMode::Implied, 1, 2);

   //STA Store Accumulator in Memory
   ADD_INSTRUCTION(0x85, Op::STA, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x95, Op::STA, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x8D, Op::STA, AddressingMode::Absolute, 3, 4);
   ADD_INSTRUCTION(0x9D, Op::STA, AddressingMode::AbsoluteIndexX, 3, 5);
   ADD_INSTRUCTION(0x99, Op::STA, AddressingMode::AbsoluteIndexY, 3, 5);
   ADD_INSTRUCTION(0x81, Op::STA, AddressingMode::XIndexIndirect, 2, 6);
   ADD_INSTRUCTION(0x91, Op::STA, AddressingMode::IndirectIndexY, 2, 6);

   //STX Store Index X in Memory
   ADD_INSTRUCTION(0x86, Op::STX, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x96, Op::STX, AddressingMode::ZeroPageIndexY, 2, 4);
   ADD_INSTRUCTION(0x8E, Op::STX, AddressingMode::Absolute, 3, 4);

   //STY Store Index Y in Memory
   ADD_INSTRUCTION(0x84, Op::STY, AddressingMode::ZeroPage, 2, 3);
   ADD_INSTRUCTION(0x94, Op::STY, AddressingMode::ZeroPageIndexX, 2, 4);
   ADD_INSTRUCTION(0x8C, Op::STY, AddressingMode::Absolute, 3, 4);

   //TAX Transfer Accumulator to Index X
   ADD_INSTRUCTION(0xAA, Op::TAX, AddressingMode::Implied, 1, 2);

   //TAY Transfer Accumulator to Index Y
   ADD_INSTRUCTION(0xA8, Op::TAY, AddressingMode::Implied, 1, 2);

   //TSX Transfer Stack Pointer to Index X
   ADD_INSTRUCTION(0xBA, Op::TSX, AddressingMode::Implied, 1, 2);

   //TXA Transfer Index X to Accumulator
   ADD_INSTRUCTION(0x8A, Op::TXA, AddressingMode::Implied, 1, 2);

   //TXS Transfer Index X to Stack Register
   ADD_INSTRUCTION(0x9A, Op::TXS, AddressingMode::Implied, 1, 2);

   //TYA Transfer Index Y to Accumulator
   ADD_INSTRUCTION(0x98, Op::TYA, AddressingMode::Implied, 1, 2);
}