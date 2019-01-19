#pragma once

#include <iostream>
#include <string.h>

class Automata {
private:
	int cash, ch;
	string menu[4] = { "tea", "coffee with milk", "cappuccino", "espresso" };
	int prices[4] = { 15, 20, 30, 25 };
	enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK }; // ïåðå÷èñëèòåëíûé òèï
	STATES State; // ïåðåìåííàÿ äëÿ õðàíåíèÿ ñîñòîÿíèÿ

	void printMenu();
	void cook();
	void finish();


public:
	Automata(); // êîíñòðóêòîð
	void on();
	void off();
	void coin(int a);
	void choice(int a);
	void cancel();
	void printState();
};
