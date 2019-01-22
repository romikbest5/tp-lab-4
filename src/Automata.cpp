#include "Automata.h"

Automata::Automata()  //конструктор
{
	cash = 0;
	state = OFF;
	string name_list[]={ "Espresso",
					     "Americano",
					     "Latte",
					     "Cappuccino",
					     "Glace",
					     "Tea",
					     "Hot chocolate" };
	int money_list[]{ 18,19,22,21,25,20,32 };
	for (int i = 0; i < AMOUNT; i++) {
		menu[i] = name_list[i];
		prices[i] = money_list[i];
		
	}
	checked = false;
}
void Automata::on()
{
	if (state == OFF) {
		state = WAIT;
		cout << "The Automata is on" << endl;
	}
}
void Automata::off()
{
	if (state != OFF) {
		cout << "The Automata is off!"<<endl;
		state = OFF;
	}
}
int Automata::coin(int money)
{
	state = ACCEPT;
	if (cash > 0) {
		cout << "Your previos balance is " << cash << endl;
	}
	cash += money;
	cout << "You have "<<cash<< endl;
	return cash;
}
void Automata::printMenu()
{
	for (int i=0; i<AMOUNT;i++ ) {   
		cout <<i+1<<" - "<< menu[i] <<" - "<<prices[i]<< endl;
	}
}
void Automata::printState()
{
	cout << name_state[state] <<"..."<< endl; 

}
int Automata::choice(int number)
{
	position_number = number-1;
	if (state == ACCEPT) {
		cout << "Select a drink from the list" << endl;
		printMenu();
		if ((number > 0) && (number <= AMOUNT)) {
			cout << "You choose " << menu[number - 1] << endl;
			state = CHECK;
			printState();
			checked=check(number);
		}
		else {
			cout << "This position is not found" << endl;
			return 0;
		}
		return number;
	}
	else {
		cout<<"The balance is 0... Deposit the money."<<endl;
		return 0;
	}
}
bool Automata::check(int number) 
{
	if (cash >= prices[number - 1]) {
		cout << "Checked!..." << endl;
		if (cash > prices[number - 1]) {
			cout<<"Your change "<<cash-prices[number-1]<<endl;
		}
		return true;
	}
	else {
		cout<<"Sorry... You don't have enough money "<<endl;
		cout << "Not enough " << prices[number-1]-cash << ". Please deposit the remaining amount or complete the transaction" << endl;
		return false;
	}
}
int Automata::cancel()
{
	if ((state == ACCEPT) || (state == CHECK)) {
		cout<<"The operation is canceled"<<endl;
		cout << "Your change is " << cash << endl;
		cash = 0;
		state = WAIT;
		printState();
	}
	return cash;
}
void Automata::cook()
{
	if (checked==true) {
		state = COOK;
		cout<<"Your order is being prepared"<<endl;
		cout << "_______"<< endl << "      /_" << endl << "\     /_/" << endl<<" \___/"<<endl;;
		finish();
	}
	else {
		cout<<"Check failed!.. "<<endl;
	}
}
void Automata::finish()
{
	if (state == COOK) {
		cout << "Your drink is ready!" << endl;
		if (cash - prices[position_number] > 0) {
			cout << "Your change is " << cash - prices[position_number] << endl;
		}
		state = WAIT;
		cash = 0;
	}
	
}
