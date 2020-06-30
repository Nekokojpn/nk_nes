#include <iostream>

//AddressingModeName,   //num of operand
enum class AddressingMode {
   Accumulator,   //0
   Implied,       //0
   Immediate,     //1
   ZeroPage,      //1
   ZeroPageIndexX,//1
   ZeroPageIndexY,//1
   Absolute,      //2
   AbsoludeIndexX,//2
   AbsoluteIndexY,//2
   Indirect,      //2
   IndexIndirect, //1
   IndirectIndex, //1
   Relative       //1
};

class CPU6502Inst {
public:
   uint8_t hex;
   uint8_t opcode;
   AddressingMode ty;
   int inst_len;
   int ck; //Cycle
   std::string desc;
   CPU6502Inst(uint8_t _hex, uint8_t _opcode, AddressingMode _ty, int _inst_len, int _ck, std::string _desc) : hex(_hex), opcode(_opcode), ty(_ty), inst_len(_inst_len), ck(_ck), desc(_desc) {};
};