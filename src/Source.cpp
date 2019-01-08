#include "pch.h"
#include "Automata.h"

using namespace std;


void WAITFor(double seconds) {
	clock_t endWAIT;
	endWAIT = static_cast<clock_t>(clock() + seconds * CLOCKS_PER_SEC);
	while (clock() < endWAIT) {}
}

void tbl() {
	cout << "\n================================\n";
}

Automata::Automata()
{
	cash = 0; //по умолчанию 0 монет и он выключен
	state = OFF;
	num = -1;
}

 string Automata::On() {
	 if (state == OFF) {
		 cout << "\nTo turn on the machine press on\n";
		 state = WAIT; //если введено on, то переход в сост WAIT
		 tbl();
		 cout << "Machine is ready";
		 tbl();
		 changeState();
		 return "Ready";
	 }
	 else return "Already on";
}

void Automata::changeState() {

	switch (state)
	{
		// если выключен, то предлагается On()
	case OFF:
		tbl();
		cout << "***MACHINE DOESN'T WORK***";
		tbl();
		//On();
		break;


		//ожидание вненесения денег
	case WAIT:
	{
		if (num == -1) {
			tbl();
			cout << "Enter the money or choose a drink..";
			tbl();
			break;
		}
		else {
			tbl();
			cout << "Enter the money or cancel the order :c";
			tbl();
			break;
		}

	}

	//принятие денег
	case ACCEPT:
	{
		tbl();
		cout << "Balance: " << cash;
		tbl();

		if (num != -1)
		{
			state = CHECK;
			changeState();
			break;
		}
		state = WAIT;
		changeState();

		//Choice();
		break;
	}
	//проверка баланса
	case CHECK:
	{
		if (cash < prices[num]) {
			tbl();
			cout << "Oh, not enough money \nAdd money or cancel the order..";
			cout << "\nYou need at least " << prices[num] - cash << "rub";
			tbl();
			state = WAIT;
			changeState();
		}
		else {
			cook();
		};
		break;
	}
	//если всё хорошо, то готовим
	case COOKING:
		cook();
		finish();
		break;
	}
}


void Automata::Choice(int a) {
	printMenu();
	cout << "\n================================\nEnter a number of drink: " << a << endl;
	cout << "================================\n";
	num = a - 1;
	cout << "\n================================\nYour drink is " << menu[num] << endl << "================================\n";
	state = CHECK;
	changeState();
}

void Automata::Cancel() {
	cout << "\n================================\nReturning your " << cash << "rub..\n";
	cout << "================================\n";
	cash = 0;
	state = WAIT;
	changeState();
}

int Automata::Coin(int a) {
	if (state == OFF)
		cout << "\nMachine is ready\n";
	state = ACCEPT;
	cash = cash + a;
	changeState();
	return cash;
}

int Automata::getCash() {
	return cash;
}

int Automata::getNum() {
	return num;
}

int Automata::getChange() {
	return prices[num] - cash;
}


void Automata::printMenu() {
	int menuSize = sizeof(prices) / sizeof(int);
	tbl();
	for (int i = 0; i < menuSize; i++)
	{
		cout << i + 1 << ": " << menu[i] << " - " << prices[i] << "\n";
	}
	cout << "================================\n";
}

void Automata::cook() {
	tbl();
	if (cash - prices[num] != 0)
	{
		cout << "\nPlease, don't forget your change: " << cash - prices[num] << "rub" << endl;
	}
	cout << "\nCooking";
	/*WAITFor(0.8);
	cout << ".";
	WAITFor(0.8);
	cout << ".";
	WAITFor(0.8);
	cout << ".";
	WAITFor(0.8);*/
	tbl();
	finish();
}

bool Automata::finish() {
	tbl();
	cout << "Your drink is ready!\n";
	tbl();
	state = WAIT;
	cash = 0;
	num = -1;
	changeState();
	return 1;
}

void Automata::Off() {
	cout << "\nShutdown...\n";
	state = OFF;
	cash = 0; //по умолчанию 0 монет и он выключен
	num = -1;
	changeState();
}
