#include <iostream>
#include "Automata.h"
using namespace std;

Automata::Automata()
{
	cash = 0;
	state = OFF;
};
string Automata::printState()
{
	string st;
	switch (state)
	{
	case(OFF):
		cout << "Automata is OFF" << endl;
		st = "Automata is OFF.";
		break;

	case(WAIT):
		cout << "Waiting... " << endl;
		st = "Waiting... ";
		break;

	case(ACCEPT):
		cout << "Insert money:" << endl;
		st = "Insert money:";
		break;
		

	case(CHECK):
		cout << "Wait... Checking for cash..." << endl;
		break;

	case(COOK):
		cout << "Cooking... Cooking " << endl;
		st = "Cooking... Cooking ";
		break;
	}
	return st;
}

string Automata::on()
{
	if (state == OFF) {
		state = WAIT;
		cout << "Automata is ON. Waiting..." << endl;
		string str = "Automata is ON. Waiting...";
		return str;
	}
	else
	{
		return "ERROR";
	}
}

string Automata::off()
{
	if (state == WAIT) {
		state = OFF;
		cout << "Automata is OFF" << endl;
		string str = "Automata is OFF";
		return str;
	}
	else
	{
		return "ERROR";
	}
}


int Automata::coin(int paid)
{
		state = ACCEPT;
		if (paid < 100 && paid >= 0)
		{
			cash += paid;
			cout << "You have " << cash << " coins.\n" << endl;
			state == ACCEPT;
			return cash;
		}
		else
		{
			cout << "Max cash is 100. Insert coins again:" << endl;
		}
}



int Automata::cancel()  
{
	if (state == ACCEPT || state == CHECK) {
		cout << "Your refund: " << cash << endl;
		cash = 0;
		state = WAIT;
		return cash;
	}
	else {
		cout << "ERROR" << endl;
		return 0;
	}
}


string Automata::choice(int x)
{
	if ((x > 0) && (x < 9))
	{
		cout << "Your choice is -  " << menu[x - 1] << endl;
		drink = prices[x - 1];
		state = CHECK;
		check();
		return menu[x - 1];
	}
	else
	{
		cout << "Not found this item" << endl;
		cout << "Select a item from the list below or cancel:" << endl;
		printMenu();
	}
}

void Automata::printMenu()
{
	for (int i = 0; i < 8; i++)
	{
		cout <<'['<<i+1<<']'<< menu[i] <<"  "<< prices[i]<<endl;
	}
	cout <<  endl;
}



void Automata::check()
{
	if (state == CHECK) {
		
		if (cash < drink) {
			cout << "Insufficient funds, please try again..Refund" << endl;
			cancel();
		}
		else
		{
			cout << "It`s all right..Prepare to cook"<<endl;
			cook();
		}
	}
}


void Automata::cook()
{
	if (state == CHECK)
	{
		state = COOK;
		printState();
	}
	else {
		cout << "ERROR" << endl;
	}
}

int Automata::finish()
{
	if (state == COOK) {
		if (drink == cash) {
			cout << "Here is your drink" << endl;
			state = WAIT;
			return cash - drink;
		}
		else
		{
			cout << "Here is your drink and change -  " << cash - drink << endl;
			cash = 0;
			state = WAIT;
			return cash - drink;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}
