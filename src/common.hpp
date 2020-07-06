#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <memory.h>


class Registers;
class CPU6502Bus;
class CPU6502Inst;
class PPU;
class Cassette;
class RAM;

void nknes_init();
void define_instructions();

extern CPU6502Inst* decoder[256];

class Registers {
public:
   uint8_t a;
   uint8_t x;
   uint8_t y;
   uint16_t pc;
   uint8_t sp_hi;
   uint8_t sp_lo;
   uint8_t p;  //Status https://kikb.web.fc2.com/6502/index.html#cpu6502_flagregister
   void init();
   uint16_t getPC();
   void setPC(uint16_t hex);
   void setPCarryFlagOn();
   void setPCarryFlagOff();
   bool getPCarryFlag();
   void setPZeroFlagOn();
   void setPZeroFlagOff();
   bool getPZeroFlag();
   void setPInterruptFlagOn();
   void setPInterruptFlagOff();
   bool getPInterruptFlag();
   void setPDecimalModeFlagOn();
   void setPDecimalModeFlagOff();
   bool getPDecimalModeFlag();
   void setPBreakCommandFlagOn();
   void setPBreakCommandFlagOff();
   bool getPBreakCommandFlag();
   void setPReserveFlagOn();
   void setPReserveFlagOff();
   bool getPReserveFlag();
   void setPOverflowFlagOn();
   void setPOverflowFlagOff();
   bool getPOverflowFlag();
   void setPNegativeFlagOn();
   void setPNegativeFlagOff();
   bool getPNegativeFlag();
};

class CPU6502 {
public:
   Registers* registers;
   CPU6502Bus* bus;
   CPU6502(Registers* _registers, CPU6502Bus* _bus) : registers(_registers), bus(_bus) {};
   uint8_t read(uint8_t address);
   uint8_t fetch();
   uint8_t fetchOpeland();
   void reset();
   void exec(uint8_t opcode);
   void init();
};

class CPU6502Bus {
public:
   PPU* ppu;
   Cassette* cassette;
   RAM* ram;
   CPU6502Bus(PPU* _ppu, Cassette* _cassette, RAM* _ram) : ppu(_ppu), cassette(_cassette), ram(_ram) {};
   uint8_t read(uint8_t address);
};

#define ADD_INSTRUCTION(hex, opcode, ty, inst_len, ck)   decoder[hex] = new CPU6502Inst(hex, opcode, ty, inst_len, ck);

enum class Op {
   ADC,
   AND,
   ASL,
   BCC,
   BCS,
   BEQ,
   BIT,
   BMI,
   BNE,
   BPL,
   BRK,
   BVS,
   CLC,
   CLD,
   CLI,
   CLV,
   CMP,
   CPX,
   CPY,
   DEC,
   DEX,
   DEY,
   EOR,
   INC,
   INX,
   INY,
   JMP,
   JSR,
   LDA,
   LDX,
   LDY,
   LSR,
   NOP,
   ORA,
   PHA,
   PHP,
   PLA,
   PLP,
   ROL,
   ROR,
   RTI,
   RTS,
   SBC,
   SEC,
   SED,
   SEI,
   STA,
   STX,
   STY,
   TAX,
   TAY,
   TSX,
   TXA,
   TXS,
   TYA
};

//AddressingModeName,   //num of operand
enum class AddressingMode {
   Accumulator,   //0
   Implied,       //0
   Immediate,     //1
   ZeroPage,      //1
   ZeroPageIndexX,//1
   ZeroPageIndexY,//1
   Absolute,      //2
   AbsoluteIndexX,//2
   AbsoluteIndexY,//2
   Indirect,      //2
   XIndexIndirect, //1
   IndirectIndexY, //1
   Relative      //1
};

class CPU6502Inst {
public:
   uint8_t hex;
   Op opcode;
   AddressingMode ty;
   int inst_len;
   int ck; //Cycle
   CPU6502Inst(uint8_t _hex, Op _opcode, AddressingMode _ty, int _inst_len, int _ck) : hex(_hex), opcode(_opcode), ty(_ty), inst_len(_inst_len), ck(_ck) {};
};

class RAM {
public:
   uint8_t memory[0xFFFF];
   uint16_t read(uint16_t address);
   //Non maskable interrupt
   uint16_t getReset();
   void setReset(uint8_t lo, uint8_t hi);
   void debug_init();
   void print();
};

class Cassette {
public:
   const char* file_name;
   char content[40976];
   Cassette(const char* _file_name);
   void copy_to_ram(RAM* ram);
};

class PPU {
public:
};