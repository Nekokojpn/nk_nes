#include <iostream>

enum class AddressingMode {
   Accumulator,
   Implied,
   Immediate,
   ZeroPage,
   ZeroPageIndexX,
   ZeroPageIndexY,
   Absolute,
   AbsoludeIndexX,
   AbsoluteIndexY,
   Indirect,
   IndexIndirect,
   IndirectIndex,
   Relative
};

class CPU6502Inst {
public:
   uint8_t hex;
   uint8_t opcode;
   AddressingMode ty;
   int inst_len;
   int ck; //Cycle
   std::string desc;
   CPU6502Inst(uint8_t _hex, uint8_t _opcode, AddressType _ty, int _inst_len, int _ck, std::string _desc) : hex(_hex), opcode(_opcode), ty(_ty), inst_len(_inst_len), ck(_ck), desc(_desc) {};
};