#include "cpu_inst.hpp"

typedef struct {
   unsigned char a;
   unsigned char x;
   unsigned char y;
   unsigned short pc;
   unsigned char sp_hi;
   unsigned char sp_lo;
   unsigned char p;
} Registers;

extern CPU6502Inst* decoder[256];

#define ADD_INSTRUCTION(hex, opcode, ty, inst_len, ck, desc)   decoder[hex] = new CPU6502Inst(hex, opcode, ty, inst_len, ck, desc);