#include "./common.hpp"

std::vector<std::string> sources;

int main () {


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
		  ), new Cassette("D:\\nk_nes\\test\\hello.nes"), ram)
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
	  WaitTimer(1000);
   }
   //nes->bus->ram->debug_init();
   
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	main();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}