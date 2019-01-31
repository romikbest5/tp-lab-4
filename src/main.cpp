#include <iostream>
#include "Automata.h"
#include "Automata.cpp"
using namespace std;

int main()
{
	int money;
	int choice;
	Automata coffeeAutomata;
	coffeeAutomata.on();
	coffeeAutomata.coin(money);
	coffeeAutomata.choice(choice);
	if (coffeeAutomata.check(choice))
		coffeeAutomata.cook();
	else {
		coffeeAutomata.contined(1);
		while (!coffeeAutomata.check(choice)) {
			coffeeAutomata.coin(money);
		}
	}
	coffeeAutomata.finish();
	coffeeAutomata.printState(-1);
    return 0;
}