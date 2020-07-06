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
   auto cpu = new CPU6502(
      new Registers(),
      new CPU6502Bus(new PPU(), new Cassette(argv[1]), new RAM())
   );
   cpu->bus->cassette->copy_to_ram(cpu->bus->ram);
   cpu->init();
   cpu->reset();
   //printf("%x", cpu->bus->ram->read(0x8000));
   printf("%x", cpu->fetch());
   printf("%x", cpu->fetch());
   printf("%x", cpu->fetch());
   printf("%x", cpu->fetch());
   if(cpu->fetch() != 0x4E || cpu->fetch() != 0x45 || cpu->fetch() != 0x53 || cpu->fetch() != 0x1A) {
      std::cout << "NES cassette header is invalid\n";
      return 1;
   }
   //nes->bus->ram->debug_init();
   
}