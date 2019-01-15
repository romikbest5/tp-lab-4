#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>


enum AState
{
	aOff = 0,
	aWait,
	aAccept,
	aCheck,
	aCook,
};

const char StateNames[6][9] =
{
	"Off",
	"Wait",
	"Accept",
	"Check",
	"Cook",
	"Unknown"
};

struct TPrice
{
	char name[100];
	int price;
};

TPrice prices[] =
{
	{ "Coffee", 5 },
	{ "Latte", 7 },
	{ "Cherry pie", 10 },
	{ NULL, 0 } // end
};

class Automata
{
private:
	AState state;
	int coins, sel;
public:
	Automata()
	{
		state = aOff;
		coins = 0;
	}

	// Простые состояния - условия хватает
	void on()
	{
		if (state == aOff)
			state = aWait;
		else
			printf("Cant ON from %s state\n", StateNames[state]);
	}

	void off()
	{
		if (state == aWait)
			state = aOff;
		else
			printf("Cant OFF from %s state\n", StateNames[state]);
	}

	void coin()
	{
		if (state == aWait)
		{
			printf("Enter coin count: ");
			scanf_s("%d", &coins);
			state = aAccept;
		}
		else
			printf("Cant ACCEPT COIN from %s state\n", StateNames[state]);
	}

	// Отмена может произойти из двух состояний
	void cancel()
	{
		switch (state)
		{
		case aWait:
		case aCheck:
			state = aAccept;
			printf("  Return %d coins\n", coins);
			coins = 0;
			break;
		default:
			printf("Cant CANCEL from %s state\n", StateNames[state]);
		};
	}

	void choice()
	{
		if (state == aAccept)
		{
			printf("Select:\n");
			for (int i = 0; prices[i].price != 0; i++)
				printf("  %d. %s - %d coins\n", i + 1, prices[i].name, prices[i].price);
			printf("Enter: ");
			scanf_s("%d", &sel);
			sel--;

			state = aCheck;
		}
		else
			printf("Cant CHOICE from %s state\n", StateNames[state]);
	}

	bool check()
	{
		if (state == aCheck)
		{
			if (prices[sel].price > coins)
				printf("  No enought coins (%d and price is %d)\n", coins, prices[sel].price);
			else
			{
				printf("  Check: All ok\n");
				return true;
			}
			// Или к примеру можно вывести "не хватает ингредиентов"
		}
		else
			printf("Cant CHECK in %s state\n", StateNames[state]);

		return false;
	}

	void cook()
	{
		if ((state == aCheck) & check())
		{
			state = aCook;
			printf("  Cook some\n");
		}
		else
			printf("Cant COOK from %s state\n", StateNames[state]);
	}

	void finish()
	{
		if (state == aCook)
		{
			coins -= prices[sel].price;

			if (coins > 0)
			{
				printf("  Return %d\n", coins);
				coins = 0;
			}

			state = aWait;
		}
		else
			printf("Cant FINISH from %s state\n", StateNames[state]);
	}

	void printState()
	{
		printf("State: %s\n", StateNames[state]);
	}
};