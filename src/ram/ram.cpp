#include "../common.hpp"

uint16_t RAM::read(uint16_t address) {
   printf("add is %x\n", address);
   return this->memory[address];
}

void RAM::debug_init() {
   for(int i = 0x000; i < 0x800; i++) {
      this->memory[i] = 0;
   }
}

void RAM::print() {
   std::cout << "    000 001 002 003 004 005 006 007 008 009 00A 00B 00C 00D 00E 00F\n";
   std::cout << "   |---------------------------------------------------------------";
   for(int i = 0x8000; i < 0x8200; i++) {
      if(i % 0x10 == 0x00)
         printf("\n%3x|", i);
      printf("%3x ", this->memory[i]);
   }
}

uint16_t RAM::getReset() {
   return (this->memory[0xFFFD] << 8) + this->memory[0xFFFC];
}

void RAM::setReset(uint8_t lo, uint8_t hi) {
   this->memory[0xFFFC] = lo;
   this->memory[0xFFFD] = hi;
}