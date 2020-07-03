#include "cpu6502.hpp"

void cpu_reset(CPU6502* cpu) {
   cpu->setPInterruptFlagOn();
   cpu->setPBreakCommandFlagOff();
}

uint8_t CPU6502::read(uint8_t address) {

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
void CPU6502::setPZeroFlagOn() {
   this->registers->p = this->registers->p | 0x02;
}
void CPU6502::setPZeroFlagOff() {
   this->registers->p = this->registers->p & 0xFD;
}
void CPU6502::setPInterruptFlagOn() {
   this->registers->p = this->registers->p | 0x04;
}
void CPU6502::setPInterruptFlagOff() {
   this->registers->p = this->registers->p & 0xFB;
}
void CPU6502::setPDecimalModeFlagOn() {
   this->registers->p = this->registers->p | 0x08;
}
void CPU6502::setPDecimalModeFlagOff() {
   this->registers->p = this->registers->p & 0xF7;
}
void CPU6502::setPBreakCommandFlagOn() {
   this->registers->p = this->registers->p | 0x10;
}
void CPU6502::setPBreakCommandFlagOff() {
   this->registers->p = this->registers->p & 0xEF;
}
void CPU6502::setPReserveFlagOn() {
   this->registers->p = this->registers->p | 0x20;
}
void CPU6502::setPReserveFlagOff() {
   this->registers->p = this->registers->p & 0xDF;
}
void CPU6502::setPOverflowFlagOn() {
   this->registers->p = this->registers->p | 0x40;
}
void CPU6502::setPOverflowFlagOff() {
   this->registers->p = this->registers->p & 0xBF;
}
void CPU6502::setPNegativeFlagOn() {
   this->registers->p = this->registers->p | 0x80;
}
void CPU6502::setPNegativeFlagOff() {
   this->registers->p = this->registers->p & 0x7F;
}