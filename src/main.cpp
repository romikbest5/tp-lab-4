#include "Automata.h"

 int main(int argc, char *argv[])
{
	Automata a;

	while (true)
	{
		std::cout<< <<std::endl;
		a.printState();

		std::cout << "Actions: " << std::endl;
		std::cout << "1 On. 2 Off. 3 Coin. 4. Cancel. 5 Choice. 6 Check. 7 Cook. 8 Finish. 9 Quit " << std::endl;
		std::cout << "Select action: " << std::endl;
		int t;
		std::cin >> t;

		if ((t == 9) | (t == 0)) break;

		if (t == 1) a.on();
		if (t == 2) a.off();
		if (t == 3) a.coin();
		if (t == 4) a.cancel();
		if (t == 5) a.choice();
		if (t == 6) a.check();
		if (t == 7) a.cook();
		if (t == 8) a.finish();
	}
	return 0;
}

