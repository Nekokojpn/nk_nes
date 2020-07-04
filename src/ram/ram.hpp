#include "../common.hpp"

class RAM {
public:
   uint8_t memory[0x800];
   uint8_t read(uint8_t address);
};