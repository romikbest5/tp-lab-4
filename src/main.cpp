#include "Automata.h"

int main()
{
	Automata a;
	std::cout << "Actions: 1 On. 2 Off. 3 Coin. 4. Cancel. 5 Choice. 6 Check. 7 Cook. 8 Get Cash. 9 Quit " << std::endl;
	std::cout << "Menu: 1. Americano - 15, 2. Latte - 20, 3. Espresso - 25, 4. Tea - 30 " << std::endl;
	a.on();
	a.coin(75);
	a.choice(2);
	a.choice(2);
	a.getCash();
	a.off();
	system("pause");
	return 0;
}
