#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <memory.h>
#include <windows.h>

#include "DxLib.h"


class Registers;
class CPU6502Bus;
class CPU6502Inst;
class Ppu;
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
    void debug_print();
    void setA(uint8_t);
    uint8_t getA();
    void setX(uint8_t);
    uint8_t getX();
    void setY(uint8_t);
    uint8_t getY();
    void setPC(uint16_t hex);
    uint16_t getPC();
    void setSP_lo(uint8_t);
    uint8_t getSP_lo();
    void setSP_hi(uint8_t);
    uint8_t getSP_hi();
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
    uint8_t read(uint16_t address);
    uint8_t fetch();
    uint8_t fetchOpeland();
    void reset();
    int exec(uint8_t opcode);
    void init();
};

class CPU6502Bus {
public:
    Ppu* ppu;
    Cassette* cassette;
    RAM* ram;
    CPU6502Bus(Ppu* _ppu, Cassette* _cassette, RAM* _ram) : ppu(_ppu), cassette(_cassette), ram(_ram) {};
    uint8_t read(uint16_t address);
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
   uint8_t read(uint16_t address);
   //Non maskable interrupt
   uint16_t getReset();
   void setReset(uint8_t lo, uint8_t hi);
   void debug_init();
   void debug_print();
};

class VRAM {
public:
   uint8_t memory[0x4000];
   uint8_t read(uint16_t address);
};

#define CHR_ROM_START 0x8220

class Cassette {
public:
   const char* file_name;
   char content[40976];
   Cassette(const char* _file_name);
   void copy_to_ram(RAM* ram);
   //Without offset
   uint8_t read_chr(uint16_t address);
};

class Ppu {
public:
   uint8_t* ctrl;
   uint8_t* mask;
   uint8_t* stat;
   uint8_t* maddr;
   uint8_t* data;
   uint8_t* scrl;
   uint8_t* paddr;
   uint8_t* pdata;
   uint8_t memory[0x4000];
   Ppu(uint8_t* _ctrl,
   uint8_t* _mask,
   uint8_t* _status,
   uint8_t* _maddr,
   uint8_t* _data,
   uint8_t* _scrl,
   uint8_t* _paddr,
   uint8_t* _pdata) :
   ctrl(_ctrl), mask(_mask), stat(_status), maddr(_maddr), data(_data), scrl(_scrl), paddr(_paddr), pdata(_pdata) {};
   int exec(int cycle);
};