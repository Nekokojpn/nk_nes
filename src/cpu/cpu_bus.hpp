#include "../common.hpp"

class CPU6502;
class PPU;
class Cassette;
class RAM;

class CPU6502Bus {
public:
   CPU6502* cpu;
   PPU* ppu;
   Cassette* cassette;
   RAM* ram;
   CPU6502Bus(CPU6502* _cpu, PPU* _ppu, Cassette* _cassette, RAM* _ram) : cpu(_cpu), ppu(_ppu), cassette(_cassette), ram(_ram) {};
   uint8_t read(uint8_t address);
};