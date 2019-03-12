#ifndef _AUTOMATA_H
#define _AUTOMATA_H

#include <string>
#include <iostream>
using namespace std;
#define AMOUNT 7

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
const string name_state[] = { "OFF","WAIT","ACCEPT","CHECK","COOK" };

class Automata
{
private:
	int cash;
	string menu[AMOUNT];
	int prices[AMOUNT];
	STATES state;

	bool checked;  //статус проверки суммы
	int position_number;
public:
	Automata();
	void on();
	void off();
	int coin(int);
	void printMenu();
	void printState();
	int choice(int);
	bool check(int);
	int cancel();
	void cook();
	void finish();
};


#endif
