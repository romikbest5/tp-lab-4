#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
	Automata nescaffe;
	STATES p;
	
	nescaffe.printState();
	nescaffe.on();

	nescaffe.coin(10);
	nescaffe.choice(2);
	nescaffe.coin(50);
	nescaffe.choice(2);
	cout << "********************************************" << endl;
	nescaffe.coin(20);
	nescaffe.choice(1);
	nescaffe.cancel();
	cout << "********************************************" << endl;
	nescaffe.coin(35);
	nescaffe.choice(7);
	nescaffe.choice(4);
	cout << "********************************************" << endl;
	nescaffe.choice(5);
}
