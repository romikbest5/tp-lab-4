#include "../include/Automata.h"
#include <iostream>

int main()
{
	Automata machine;

	machine.on();
	machine.printMenu();
	machine.off();

	machine.on();
	machine.coin(40);
	machine.choice(3);
	
	machine.on();
	machine.printMenu();
	machine.coin(40);
	
	machine.coin(5);
	machine.cancel();

	machine.coin(35);
	machine.choice(3);

	machine.coin(5);
	machine.choice(3);
	machine.cancel();
	
	machine.coin(40);
	machine.choice(3);
	machine.cook();

	machine.finish();
	machine.off();
	
	return 0;
}