#include "./common.hpp"

std::vector<std::string> sources;

int main (int argc, char** argv) {
   std::ifstream ifs(argv[1]);
   if (ifs.fail()) {
		std::cout << "No such directory or file name";
		return 1;
	}
   std::string buf;
	while (getline(ifs, buf)) {
		std::string t = buf + '\n';
		sources.push_back(t);
      std::cout << t;
	}
   define_instructions();
   auto nes = new CPU6502(
      new Registers(),
      new CPU6502Bus(new PPU(), new Cassette(), new RAM())
   );
   nes->init();
   //nes->bus->ram->debug_init();
   //nes->bus->ram->print();
}