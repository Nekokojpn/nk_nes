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

uint8_t CPU6502::read(uint8_t address) {
   return this->bus->read(address);
}

uint8_t CPU6502::fetch() {
   return this->read(this->registers->pc++);
}

void CPU6502::exec(uint8_t opcode) {

}

