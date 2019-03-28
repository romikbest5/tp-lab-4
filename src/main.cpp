// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Automata.h"
using namespace std;



int main()
{
	Automata coffee;
	coffee.On();
	coffee.PrintMenu();
	coffee.Coin(5);
	coffee.Coin(3);
	coffee.Choice(2);
	return 0;
}

