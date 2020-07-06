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
   cpu->init();
   cpu->reset();
   //nes->bus->ram->debug_init();
   //nes->bus->ram->print();
}