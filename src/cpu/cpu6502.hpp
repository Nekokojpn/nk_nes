#include "common.hpp"

class CPU6502Inst;

typedef struct {
   uint8_t a;
   uint8_t x;
   uint8_t y;
   uint16_t pc;
   uint8_t sp_hi;
   uint8_t sp_lo;
   uint8_t p;  //Status https://kikb.web.fc2.com/6502/index.html#cpu6502_flagregister
} Registers;


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