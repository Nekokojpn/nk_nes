#include "./common.hpp"

std::vector<std::string> sources;

int main (int argc, char** argv) {
   if(argc < 2) {
      std::cout << "Expected a few args!\n";
      return 1;
   }
   std::ifstream ifs(argv[1]);
   if (ifs.fail()) {
		std::cout << "No such directory or file name!";
		return 1;
	}
   define_instructions();
   auto ram = new RAM();
   auto cpu = new CPU6502(
      new Registers(),
      new CPU6502Bus(
		  new Ppu(
			&ram->memory[0x2000],
			&ram->memory[0x2001],
			&ram->memory[0x2002],
			&ram->memory[0x2003],
			&ram->memory[0x2004],
			&ram->memory[0x2005],
			&ram->memory[0x2006],
			&ram->memory[0x2007]
		  ), new Cassette(argv[1]), ram)
   );
   cpu->bus->cassette->copy_to_ram(cpu->bus->ram);
   cpu->init();
   cpu->reset();
   if(cpu->fetch() != 0x4E || cpu->fetch() != 0x45 || cpu->fetch() != 0x53 || cpu->fetch() != 0x1A) {
      std::cout << "NES cassette header is invalid\n";
      return 1;
   }
   cpu->registers->pc += 12;
   for(;;) {
      cpu->exec(cpu->fetch());
      cpu->bus->ram->debug_print();
      cpu->registers->debug_print();
      int x;std::cin>>x;
   }
   //nes->bus->ram->debug_init();
   
}