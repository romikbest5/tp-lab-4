#include <iostream>
#include "Automata.h"
using namespace std;

Automata::Automata() {
	state = OFF;
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		cash = 0;
		printMenu();
	}
}

void Automata::off() {
	state = OFF;
}

void Automata::coin(int money) {
	if(money > 0){
		state = ACCEPT;
		cout << "you put " << money << endl;
		cash = cash + money;
	}
}

void Automata::choice(int item) {
	if(item>-1 && item<5){
		cout << "you choose " << menu[item] << endl;
		state = CHECK;
	}
}

bool Automata::contined(bool answer) {
	if (answer == 1) {
		cout << "You want to continue" << endl;
	}
	else
		cout << "You want to cancel" << endl;
	return answer;
}

void Automata::printMenu() {
	cout << "menu:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i << ") " << menu[i] << " - " << prices[i] << endl;
	}
}

void Automata::printState(int item) {
	switch (state) {
	case 0:cout << "AUTOMATE IS OFF" << endl;
		break;
	case 1:cout << "AUTOMATE IS WAITING" << endl;
		break;
	case 2:cout << "ACCEPTING MONEY" << endl;
		break;
	case 3:cout << "CHECKING BALANCE" << endl;
		break;
	case 4:cout << "COOKING" << endl;
		break;
	}
	if (item > -1 && item < 5) {
		cout << "You order " << menu[item] << endl;
		cout << "Your cash is " << cash << endl;
		if (prices[item] - cash > 0)
			cout << "Also need " << prices[item] - cash << endl;
		else
			cout << "No more money is needed" << endl;
	}
}

bool Automata::check(int item) {
	state = CHECK;
	printState(item);
	if (cash>=prices[item]) {
		return true;
	}
	else {
		return false;
	}
}

void Automata::cancel() {
	state = WAIT;
	printMenu();
}

void Automata::cook(int item) {
	cash = cash - prices[item];
	state = COOK;
}

void Automata::finish() {
	if (cash == 0) {
		off();
	}
	else {
		state = WAIT;
	}
}

STATES Automata::getState(){
	return state;
}