#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#define SizeMenu 3
enum statelist {OFF,ON, WAIT, CHECK, COOK, ACCEPT};
using namespace std;
class Automata
{
private:
	unsigned int cash;
	string menu[SizeMenu];
	unsigned int prices[SizeMenu];
	statelist state;
public:
	Automata();
	void On();
	void Off();
	void Coin(int value);
	void PrintMenu();
	statelist PrintState();
	void Choice(int number);
	bool Check(int number);
	void Cancel();
	void Cook(int number);
	void Finish();
	void ReturnMoney();
};

