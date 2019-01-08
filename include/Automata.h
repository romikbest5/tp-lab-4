#pragma once
#include <string>
#include <iostream>
using namespace std;
enum STATES {
	ON,
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	STATES state;
	int paid, cash, choose, drink;
	int prices[8] = { 20, 25, 20, 25, 40, 35, 45, 10 };
	string menu[8] = 
	{ 
		"Iced Coffee",
		"Americano",
		"Espresso",
		"Cappuccino",
		"Mocha",
		"Macchiato",
		"Latte",
		"Tea",
	};
public:
	Automata();
	string on();
	string off();
	int coin(int cash);
	void printMenu();
	string printState();
	string choice(int x);
	void check();
	int cancel();
	void cook();
	int finish();
};
