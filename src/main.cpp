#include "automata.h"
int main(){
	Automata coffee;
	int money;
	int ch;
	int change;
	coffee.on();
	coffee.printState();
	cout<<"Insert cash\n";
	cin>>money;
	coffee.coin(money);
	coffee.printState();
	cout<<"Continue?0 or 1\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			coffee.choise(1);
			break;
		case 0:
			coffee.cancel();
			break;
	}
	coffee.printState();
	coffee.check();
	coffee.printState();
	coffee.cook();
	coffee.printState();
	coffee.finish();
	coffee.printState();
	change=coffee.giveChange();
	coffee.off();
	coffee.printState();
	system("pause");
	
	
	
}