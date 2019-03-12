#include <iostream>
#include "Automata.h"
using namespace std;

int main()
{
	Automata coffeeAutomata;
	coffeeAutomata.on();
	coffeeAutomata.coin(40);
	coffeeAutomata.choice(1);
	if (coffeeAutomata.check(1))
		coffeeAutomata.cook(1);
	else {
		coffeeAutomata.contined(1);
		while (!coffeeAutomata.check(1)) {
			coffeeAutomata.coin(1);
		}
		coffeeAutomata.cook(1);
	}
	coffeeAutomata.finish();
    return 0;
}