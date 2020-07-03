#include "../common.hpp"

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

class CPU6502Inst;

CPU6502Inst* decoder[256];

class CPU6502Inst {
public:
   uint8_t hex;
   Op opcode;
   AddressingMode ty;
   int inst_len;
   int ck; //Cycle
   CPU6502Inst(uint8_t _hex, Op _opcode, AddressingMode _ty, int _inst_len, int _ck) : hex(_hex), opcode(_opcode), ty(_ty), inst_len(_inst_len), ck(_ck) {};
};