
#include "Automata.h"
#include <iostream>
using namespace std;


int main() {

	Automata machine;

	cout << "TEST 1" << endl;
	machine.on();
	machine.coin(15);
	machine.choice(6);
	machine.coin(15);
	machine.choice(6);
	machine.cancel();
	machine.off();
	cout << endl << endl<<"TEST 2"<<endl;

	machine.on();
	machine.coin(23);
	machine.choice(3);
	machine.cook();
	
	machine.off();
	cout << endl << endl << "TEST 3" << endl;

	machine.on();
	machine.coin(30);
	machine.choice(7);
	machine.cook();
	machine.cancel();
	machine.off();
	cout << endl << endl << "TEST 4" << endl;

	machine.on();
	machine.coin(32);
	machine.choice(7);
	machine.cook();
	machine.off();
}