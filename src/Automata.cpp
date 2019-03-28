#include "Automata.h"
#include "stdafx.h"
#include <iostream>
#include <string>


Automata::Automata()
{
	cash = 0;
	state = OFF;
	menu[0] = "Espresso";
	prices[0] = 3;
	menu[1] = "Americano";
	prices[1] = 10;
	menu[2] = "Latte";
	prices[2] = 15;
}
statelist Automata::PrintState()
{
	return this->state;
}
void Automata::PrintMenu()
{
	for (int i=0;i<SizeMenu;i++)
		cout << menu[i]<<"   Price:"<<prices[i]<<endl;
}
void Automata::On()
{
	if (this->state == OFF)
		this->state = WAIT;
}
void Automata::Off()
{
	if (this->state == WAIT)
		this->state = ON;
}
void Automata::Coin(int value)
{
	if (this->state == WAIT)
	{
		this->state = ACCEPT;
		this->cash += value;
	}
	if (this->state == ACCEPT)
	{
		this->cash += value;
	}
}
void Automata::Cancel()
{
	if (this->state == CHECK || this->state == ACCEPT)
	{
		this->state = WAIT;
		this->cash = 0;
	}
}
void Automata::Choice(int number)
{
	this->state = CHECK;
	if (this->Check(number))
	{
		cout << "NOT ENOUGHT MONEY";
		Cancel();
	}
	else
	{
		this->cash -= this->prices[number - 1];
		this->Cook(number);
	}
}
bool Automata::Check(int number)
{
	if (this->cash < number)
		return 1;
	else
		return 0;
}
void Automata::Cook(int number)
{
	this->state = COOK;
	cout << "COOKING " << menu[number - 1]<<endl;
	this->Finish();
}
void Automata::Finish()
{
	cout << "Take your coffee"<< endl;
	this->ReturnMoney();
	this->state = WAIT;
}

void Automata::ReturnMoney()
{
	if (this->cash > 0)
	{
		this->cash = 0;
		cout << "Take your money";
	}
}

