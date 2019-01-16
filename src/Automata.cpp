#include "Automata.h"

TPrice prices[] =
{
	{ "Americano", 5 },
	{ "Latte", 7 },
	{ "Espresso", 10 },
	{ NULL, 0 } // end
};

Automata::Automata()
	{
		state = aOff;
		coins = 0;
	}

	// Ïðîñòûå ñîñòîÿíèÿ - óñëîâèÿ õâàòàåò
	void Automata::on()
	{
		if (state == aOff)
			state = aWait;
		else
			printf("Cant ON from %s state\n", StateNames[state]);
	}

	void Automata::off()
	{
		if (state == aWait)
			state = aOff;
		else
			printf("Cant OFF from %s state\n", StateNames[state]);
	}

	void Automata::coin()
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

	// Îòìåíà ìîæåò ïðîèçîéòè èç äâóõ ñîñòîÿíèé
	void Automata::cancel()
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

	void Automata::choice()
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

	bool Automata::check()
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
			// Èëè ê ïðèìåðó ìîæíî âûâåñòè "íå õâàòàåò èíãðåäèåíòîâ"
		}
		else
			printf("Cant CHECK in %s state\n", StateNames[state]);

		return false;
	}

	void Automata::cook()
	{
		if ((state == aCheck) & check())
		{
			state = aCook;
			printf("  Cook some\n");
		}
		else
			printf("Cant COOK from %s state\n", StateNames[state]);
	}

	void Automata::finish()
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

	void Automata::printState()
	{
		printf("State: %s\n", StateNames[state]);
	}
