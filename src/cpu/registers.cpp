#include "../common.hpp"

void Registers::init() {
   
}

void Registers::debug_print() {
   printf("accu = %x\n", this->a);
   printf("indx = %x\n", this->x);
   printf("indy = %x\n", this->y);
   printf("proc = %x\n", this->pc);
   printf("sphi = %x\n", this->sp_hi);
   printf("splo = %x\n", this->sp_lo);
   printf("carr = %x\n", this->getPCarryFlag());
   printf("zero = %x\n", this->getPZeroFlag());
   printf("intr = %x\n", this->getPInterruptFlag());
   printf("deci = %x\n", this->getPDecimalModeFlag());
   printf("brek = %x\n", this->getPBreakCommandFlag());
   printf("rsve = %x\n", this->getPReserveFlag());
   printf("ovfl = %x\n", this->getPOverflowFlag());
   printf("negt = %x\n", this->getPNegativeFlag());
}

void Registers::setA(uint8_t n) {
   this->a = n;
}
uint8_t Registers::getA() {
   return this->a;
}
void Registers::setX(uint8_t n) {
   this->x = n;
}
uint8_t Registers::getX() {
   return this->x;
}
void Registers::setY(uint8_t n) {
   this->y = n;
}
uint8_t Registers::getY() {
   return this->y;
}

void Registers::setSP_lo(uint8_t n) {
   this->sp_lo = n;
}
uint8_t Registers::getSP_lo() {
   return this->sp_lo;
}
void Registers::setSP_hi(uint8_t n) {
   this->sp_hi = n;
}
uint8_t Registers::getSP_hi() {
   return this->sp_hi;
}

uint16_t Registers::getPC() {
   return this->pc;
}

void Registers::setPC(uint16_t hex) {
   this->pc = hex;
}

void Registers::setPCarryFlagOn() {
   this->p = this->p | 0x01;
}
void Registers::setPCarryFlagOff() {
   this->p = this->p & 0xFE;
}
bool Registers::getPCarryFlag() {
   return (this->p & 0x01) == 0x01 ? true : false;
}
void Registers::setPZeroFlagOn() {
   this->p = this->p | 0x02;
}
void Registers::setPZeroFlagOff() {
   this->p = this->p & 0xFD;
}
bool Registers::getPZeroFlag() {
   return ((this->p & 0x02) >> 1) == 0x01 ? true : false;
}
void Registers::setPInterruptFlagOn() {
   this->p = this->p | 0x04;
}
void Registers::setPInterruptFlagOff() {
   this->p = this->p & 0xFB;
}
bool Registers::getPInterruptFlag() {
   return ((this->p & 0x04) >> 2) == 0x01 ? true : false;
}
void Registers::setPDecimalModeFlagOn() {
   this->p = this->p | 0x08;
}
void Registers::setPDecimalModeFlagOff() {
   this->p = this->p & 0xF7;
}
bool Registers::getPDecimalModeFlag() {
   return ((this->p & 0x08) >> 3) == 0x01 ? true : false;
}
void Registers::setPBreakCommandFlagOn() {
   this->p = this->p | 0x10;
}
void Registers::setPBreakCommandFlagOff() {
   this->p = this->p & 0xEF;
}
bool Registers::getPBreakCommandFlag() {
   return ((this->p & 0x10) >> 4) == 0x01 ? true : false;
}
void Registers::setPReserveFlagOn() {
   this->p = this->p | 0x20;
}
void Registers::setPReserveFlagOff() {
   this->p = this->p & 0xDF;
}
bool Registers::getPReserveFlag() {
   return ((this->p & 0x20) >> 5) == 0x01 ? true : false;
}
void Registers::setPOverflowFlagOn() {
   this->p = this->p | 0x40;
}
void Registers::setPOverflowFlagOff() {
   this->p = this->p & 0xBF;
}
bool Registers::getPOverflowFlag() {
   return ((this->p & 0x40) >> 6) == 0x01 ? true : false;
}
void Registers::setPNegativeFlagOn() {
   this->p = this->p | 0x80;
}
void Registers::setPNegativeFlagOff() {
   this->p = this->p & 0x7F;
}
bool Registers::getPNegativeFlag() {
   return ((this->p & 0x80) >> 7) == 0x01 ? true : false;
}