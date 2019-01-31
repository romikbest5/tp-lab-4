#include <iostream>
#include "Automata.h"
#include "Automata.cpp"
using namespace std;

int main()
{
	Automata coffeeAutomata;
	coffeeAutomata.on();
	coffeeAutomata.coin(40);
	coffeeAutomata.choice(1);
	if (coffeeAutomata.check(1))
		coffeeAutomata.cook();
	else {
		coffeeAutomata.contined(1);
		while (!coffeeAutomata.check(1)) {
			coffeeAutomata.coin(1);
		}
		coffeeAutomata.cook();
	}
	coffeeAutomata.finish();
    return 0;
}