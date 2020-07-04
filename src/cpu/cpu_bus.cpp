#include "../common.hpp"

uint8_t CPU6502Bus::read(uint8_t address) {
   return this->ram->read(address);
}