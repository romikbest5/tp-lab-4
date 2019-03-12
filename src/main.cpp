#include "Automata.h"
#include <iostream>
//SCENARIO
int main()
{
	Automata cof;
	cof.printState(); 
	cof.on();
	cof.printMenu();
	cof.off();
	cof.on();
	cof.printMenu();
	cof.coin(40);
	cof.coin(5);
	cof.cancel();
	cof.coin(35);
	cof.choice(3);
	cof.finish();
	system("pause");
	return 0;
}