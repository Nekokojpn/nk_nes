#include "cpu_inst.hpp"

typedef struct {
   unsigned char a;
   unsigned char x;
   unsigned char y;
   unsigned short pc;
   unsigned char sp_hi;
   unsigned char sp_lo;
   unsigned char p;  //Status https://kikb.web.fc2.com/6502/index.html#cpu6502_flagregister
} Registers;


#define ADD_INSTRUCTION(hex, opcode, ty, inst_len, ck, desc)   decoder[hex] = new CPU6502Inst(hex, opcode, ty, inst_len, ck, desc);

class CPU6502 {
public:
   Registers* registers;
   CPU6502Inst* decoder[256];
   CPU6502(Registers* _registers) : registers(_registers) {};
   void setPCarryFlagOn();
   void setPCarryFlagOff();
   void setPZeroFlagOn();
   void setPZeroFlagOff();
   void setPInterruptFlagOn();
   void setPInterruptFlagOff();
   void setPDecimalModeFlagOn();
   void setPDecimalModeFlagOff();
   void setPBreakCommandFlagOn();
   void setPBreakCommandFlagOff();
   void setPReserveFlagOn();
   void setPReserveFlagOff();
   void setPOverflowFlagOn();
   void setPOverflowFlagOff();
   void setPNegativeFlagOn();
   void setPNegativeFlagOff();
};