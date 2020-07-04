#include "../common.hpp"

uint8_t RAM::read(uint8_t address) {
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
   for(int i = 0x000; i < 0x800; i++) {
      if(i % 0x10 == 0x00)
         printf("\n%3x|", i);
      printf("%3x ", this->memory[i]);
   }
}