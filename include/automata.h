#include <iostream>
#include <string>
using namespace std;
enum STATES{OFF,WAIT,ACCEPT,CHECK,COOK};
#ifndef _AUTOMATA_H 
#define _AUTOMATA_H 
class Automata{
private:
	int N=6;
	int cash;
	string menu[6]={"Cappuccino","Latte","Espresso","Irish","Macchiato","Vienna Coffee"};
	int prices[6]={30,45,25,60,35,55};
	int select;
	STATES state;
public:
    Automata();
	STATES on();
	STATES off();
	STATES coin(int money);
	void printMenu();
	void printState();
	STATES choise(int f);
	bool check();
	STATES cancel();
	STATES cook();
	STATES finish();
	int giveChange();
};
#endif 