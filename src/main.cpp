#include "Automata.h"

using namespace std;



void Automata::on() {
	State = WAIT;
	cout << "Machine is working\n";
}


void Automata::off()
{
	if (State != OFF) //���� ��� ��������, �� �� ��������� ��� ��� 
	{
		if (cash != 0)
		{
			cout << "Your change: " << cash << endl;
			cash = 0;
		}
		State = OFF;
		ch = 0;
		cout << "Turning off the machine..\n";
	}
}

void Automata::coin(int a) {
	switch (State) {

	case (WAIT):
		State = ACCEPT;
		cash = a;
		cout << "Balance: " << cash << endl;
		break;

	case (OFF):
		State = ACCEPT;
		cash = a;
		cout << "Balance: " << cash << endl;
		break;

	case (ACCEPT):
		cash = cash + a;
		cout << "Balance: " << cash << endl;
		break;

	case (CHECK):
		cash = cash + a;
		cout << "Balance: " << cash << endl;
		State = CHECK;
		choice(ch);
		break;

	default:
		break;
	}
}

void Automata::choice(int a) {
	switch (State) {
	case(ACCEPT):
		ch = a - 1;
		State = CHECK;
		//break;

	case(CHECK):
		if (cash < prices[ch])
		{
			cout << "\nNot enough money..\n";
		}
		else {
			cout << "Everything is allright\n";
			cook();
		}
		break;

	default:
		break;
	}
}

void Automata::printMenu() {
	int size = sizeof(prices) / sizeof(int);
	for (int i = 0; i < size; i++)
		cout << menu[i] << " - " << prices[i] << endl;
}

void Automata::printState()
{
	switch (State) {
	case(WAIT):
		cout << "WAITING...\n";
	case (OFF):
		cout << "OFF\n";
	case (ACCEPT):
		cout << "MONEY ACCEPT\n";
	case (COOK):
		cout << "COOKING...\n";

	default:
		break;
	}
}

void Automata::cancel() {
	switch (State)
	{
	case (OFF):
		cout << "Machine is off, can not cancel\n";
		break;
	case (COOK):
		cout << "Can not cancel, wait until drink will be cooked\n";
	case (WAIT):
		break;
	default:
		State = WAIT;
		cout << "Your change: " << cash << endl;
		cash = 0;
		ch = 0;
	}
}

void Automata::cook()
{
	State = COOK;
	cout << menu[ch] << endl;
	printState();
	finish();
}

void Automata::finish() {
	State = WAIT;
	cout << "Your change: " << cash - prices[ch] << endl;
	cash = 0;
	ch = 0;
	cout << "Thank you, have a good day! \n";
}

Automata::Automata() {
	cash = 0;
	State = OFF;
	ch = 0;
}


int main()
{
	Automata m;
	m.on();
	m.coin(20);
	m.coin(7);
	m.choice(3);
	m.coin(2);
	m.coin(1);
	/*m.off();
	//m.coin(5);
	m.cancel();
	m.coin(1);
	m.coin(2);
	m.coin(26);
	m.choice(3);
	m.coin(2);
	*/
	_getch();
}