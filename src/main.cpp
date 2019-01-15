#include "Header.h"

int main() {
	Automata automata;
	automata.on();
	automata.coin(75);
	automata.choice(2);
	automata.choice(2);
	automata.getCash();
	automata.off();
	system("pause");
	return 0;
}