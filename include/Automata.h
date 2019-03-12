#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

enum AState
{
	aOff = 0,
	aWait,
	aAccept,
	aCheck,
	aCook,
};

const char StateNames[6][9] ={	"Off",	"Wait",	"Accept",	"Check",	"Cook",	"Unknown"};

struct TPrice
{
	char name[100];
	int price;
};

class Automata
{
private:
	AState state;
	int coins, sel;

public:
	Automata();
	void on();
	void off();
	void coin(unsigned int);
	void cancel();
	void choice(unsigned int);
	bool check(unsigned int);
	void cook();
	void finish();
	void printState();
};
