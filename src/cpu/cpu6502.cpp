#include "../common.hpp"

void CPU6502::reset() {
   this->registers->setPInterruptFlagOn();
   this->registers->setPBreakCommandFlagOff();
   //PC
   this->bus->ram->setReset(0x00, 0x80);
   this->registers->setPC(this->bus->ram->getReset());
}

void CPU6502::init() {
   
}

uint8_t CPU6502::read(uint16_t address) {
   return this->bus->read(address);
}

uint8_t CPU6502::fetch() {
   return this->read(this->registers->pc++);
}

uint8_t CPU6502::fetchOpeland() {
   return this->read(this->registers->pc++);
}

int CPU6502::exec(uint8_t opcode) {
   auto cur = decoder[opcode];
   //No operand
   if(cur->ty == AddressingMode::Implied) {
      if(cur->opcode == Op::SEI) {
         this->registers->setPInterruptFlagOff();
      }
      else if(cur->opcode == Op::TXS) {
         this->registers->setSP_lo(this->registers->getX());
      }
   }
   //1 operand
   else if(cur->ty == AddressingMode::Immediate) {
      auto one = this->fetchOpeland();
      if(cur->opcode == Op::LDA) {
         this->registers->setA(one);
      }
      else if(cur->opcode == Op::LDX) {
         this->registers->setX(one);
      }
      else if(cur->opcode == Op::LDY) {
         this->registers->setY(one);
      }
      else if(cur->opcode == Op::INX) {
         this->registers->x++;
      }
      else if(cur->opcode == Op::DEY) {
         this->registers->y--;
      }
   }
   else if(cur->ty == AddressingMode::Absolute) {
      auto one = this->fetchOpeland();
      auto two = this->fetchOpeland();
      uint16_t address = (two >> 8) + one;
      if(cur->opcode == Op::STA) {
         this->bus->ram->memory[address] = this->registers->a;
      }
   }
   else if(cur->ty == AddressingMode::AbsoluteIndexX) {
      auto one = this->fetchOpeland();
      auto two = this->fetchOpeland();
      uint16_t address = (two >> 8) + one;
      address += this->registers->x;
      if(cur->opcode == Op::LDA) {
         this->registers->setA(this->bus->ram->memory[address]);
      }
   }
   else if(cur->ty == AddressingMode::Relative) {
      auto one = this->fetchOpeland();
      auto two = this->fetchOpeland();
      uint16_t address = two + one;
      if(cur->opcode == Op::BNE) {
         if(!this->registers->getPZeroFlag()) {
            this->registers->setPC(address);
         }
      }
   }
	return cur->ck;
}

