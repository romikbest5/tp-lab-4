#include <iostream>
enum STATES{ OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
private:
	int cash;
	char menu[5][255] = {"espresso","cappuccino","latte","green tea","black tea"};
	int prices[5] = { 30,40,50,30,30 };
	STATES state;
public:
	Automata();
	void on();
	void off();
	void coin(int money);
	bool contined(bool answer);
	void printMenu();
	void printState(int item);
	void choice(int item);
	bool check(int item);
	void cancel();
	void cook(int item);
	void finish();
	STATES getState();
};