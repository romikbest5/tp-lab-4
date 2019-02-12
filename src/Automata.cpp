#include <iostream>
#include <string>
#include <array>
#include "Automata.h"

using namespace std;

Automata::Automata() {
	state = OFF;
}
void Automata::on(){
	state = WAIT;
	cout << "I'm ready!" << endl;
	printMenu();
}
void Automata::off(){
	if (state == WAIT){
		state = OFF;
		cout << "Good bye!" << endl;
	}
	else cout << "You cannot turn off the automata" << endl;
} 
void Automata::coin(int money){
	if (state == WAIT || state == ACCEPT){
		cash_tmp += money;
		state = ACCEPT;	
	}
} 
void Automata::printMenu(){
	
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ".:" << menu[i] << "(" << prices[i] << ")" << endl;
	}
	
} 

STATES Automata::printState(){
	switch (state){
	case OFF:
		cout << "OFF" << endl;
		break;
	case WAIT:
		cout << "Waiting..." << endl;
		break;
	case ACCEPT:
		cout << "Accepting money" << endl;
		break; 
	case CHECK:
		cout << "Checking" << endl;
		break;
	case COOK:
		cout << "Cooking" << endl;
		break;
	}
	return state;
}
void Automata::choice(int ch){	
	if (state == ACCEPT && ch<=7 && ch>=1){
		choice_int=ch-1;
		state = CHECK;
		check();
	}
	else cout << "You cannot choose any drink" << endl;
} 
void Automata::check(){
	if (state == CHECK){
		if (cash_tmp < prices[choice_int]){
			cout << "Not enough funds. Your money: " << cash_tmp<<endl;
			cout << "You can: \n 1) Add some money \n 2) Choose something other \n 3) To cencel" << endl;
			state = ACCEPT;

		}
		if (cash_tmp > prices[choice_int]) getChange();
		if (cash_tmp == prices[choice_int]){
			cash = cash_tmp;
			state = COOK;
			cook();
		}

	}
} 
int Automata::getChange(){	
		int ost;
		cout << "cash=" << cash_tmp << endl;
		cout << "ptice=" << prices[choice_int];
			ost = cash_tmp - prices[choice_int];	
			cash_tmp = prices[choice_int];
			cout << "Your change: " << ost << endl;
			check();		
		return ost;

}
void Automata::cancel(){
		if (state == ACCEPT){
			int change;
			change = cash_tmp;
			cash_tmp = 0;
			cout << "Your change: " << change << endl;
			on();
		}
} 
void Automata::cook(){
	if (state == COOK){
		cout << "Your drink is cooking..." << endl;
		finish();
	}
} 
void Automata::finish(){
	cout << "Your " << menu[choice_int] << " had cooked. Thank you!" << endl;
	cash_tmp = 0;
	state = WAIT;
} 
