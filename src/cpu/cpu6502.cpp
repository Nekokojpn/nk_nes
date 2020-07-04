#include "../common.hpp"

void cpu_reset(CPU6502* cpu) {
   cpu->setPInterruptFlagOn();
   cpu->setPBreakCommandFlagOff();
}

void CPU6502::init() {
   
}

uint8_t CPU6502::read(uint8_t address) {
   return this->bus->read(address);
}

uint8_t CPU6502::fetch() {
   return this->read(this->registers->pc++);
}

