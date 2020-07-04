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

void CPU6502::setPCarryFlagOn() {
   this->registers->p = this->registers->p | 0x01;
}
void CPU6502::setPCarryFlagOff() {
   this->registers->p = this->registers->p & 0xFE;
}
bool CPU6502::getPCarryFlag() {
   return (this->registers->p & 0x01) == 0x01 ? true : false;
}
void CPU6502::setPZeroFlagOn() {
   this->registers->p = this->registers->p | 0x02;
}
void CPU6502::setPZeroFlagOff() {
   this->registers->p = this->registers->p & 0xFD;
}
bool CPU6502::getPZeroFlag() {
   return ((this->registers->p & 0x02) >> 1) == 0x01 ? true : false;
}
void CPU6502::setPInterruptFlagOn() {
   this->registers->p = this->registers->p | 0x04;
}
void CPU6502::setPInterruptFlagOff() {
   this->registers->p = this->registers->p & 0xFB;
}
bool CPU6502::getPInterruptFlag() {
   return ((this->registers->p & 0x04) >> 2) == 0x01 ? true : false;
}
void CPU6502::setPDecimalModeFlagOn() {
   this->registers->p = this->registers->p | 0x08;
}
void CPU6502::setPDecimalModeFlagOff() {
   this->registers->p = this->registers->p & 0xF7;
}
bool CPU6502::getPDecimalModeFlag() {
   return ((this->registers->p & 0x08) >> 3) == 0x01 ? true : false;
}
void CPU6502::setPBreakCommandFlagOn() {
   this->registers->p = this->registers->p | 0x10;
}
void CPU6502::setPBreakCommandFlagOff() {
   this->registers->p = this->registers->p & 0xEF;
}
bool CPU6502::getPBreakCommandFlag() {
   return ((this->registers->p & 0x10) >> 4) == 0x01 ? true : false;
}
void CPU6502::setPReserveFlagOn() {
   this->registers->p = this->registers->p | 0x20;
}
void CPU6502::setPReserveFlagOff() {
   this->registers->p = this->registers->p & 0xDF;
}
bool CPU6502::getPReserveFlag() {
   return ((this->registers->p & 0x20) >> 5) == 0x01 ? true : false;
}
void CPU6502::setPOverflowFlagOn() {
   this->registers->p = this->registers->p | 0x40;
}
void CPU6502::setPOverflowFlagOff() {
   this->registers->p = this->registers->p & 0xBF;
}
bool CPU6502::getPOverflowFlag() {
   return ((this->registers->p & 0x40) >> 6) == 0x01 ? true : false;
}
void CPU6502::setPNegativeFlagOn() {
   this->registers->p = this->registers->p | 0x80;
}
void CPU6502::setPNegativeFlagOff() {
   this->registers->p = this->registers->p & 0x7F;
}
bool CPU6502::getPNegativeFlag() {
   return ((this->registers->p & 0x80) >> 7) == 0x01 ? true : false;
}