#include "ram.hpp"

uint8_t RAM::read(uint8_t address) {
   return this->memory[address];
}