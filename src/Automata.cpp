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

	// Простые состояния - условия хватает
	void Automata::on()
	{
		if (state == aOff)
			state = aWait;
		else
			std::cout << "Cant ON from" << StateNames[state] << "state" << std::endl;
	}

	void Automata::off()
	{
		if (state == aWait)
			state = aOff;
		else
		std::cout << "Cant OFF from" << StateNames[state] << "state" << std::endl;
	}

	void Automata::coin()
	{
		if (state == aWait)
		{
			std::cout << "Enter coin count: " << std::endl;
			std::cin >> coins;
			state = aAccept;
		}
		else
			std::cout << "Cant ACCEPT COIN from" << StateNames[state] << "state" << std::endl;
	}

	// Отмена может произойти из двух состояний
	void Automata::cancel()
	{
		switch (state)
		{
		case aWait:
		case aCheck:
			state = aAccept;
			std::cout << "  Return" << coins << "coins" << std::endl;
			coins = 0;
			break;
		default:
			std::cout << "Cant CANCEL from" << StateNames[state] << "state" << std::endl;
		};
	}

	void Automata::choice()
	{
		if (state == aAccept)
		{
			std::cout << "Select:" << std::endl;
			for (int i = 0; prices[i].price != 0; i++)
				std::cout << i+1<<"-"<< prices[i].name <<":"<< prices[i].price << "coins" << std::endl;
			std::cout << "Enter:" << std::endl;
			std::cin >> sel;
			sel--;

			state = aCheck;
		}
		else
			std::cout << "Cant CHOICE from" << StateNames[state] << "state" << std::endl;
	}

	bool Automata::check()
	{
		if (state == aCheck)
		{
			if (prices[sel].price > coins)
				std::cout << "No enought coins (" << coins << "and price is" << coins << ")" << prices[sel].price << std::endl;
			else
			{
				std::cout << "Check: All ok" <<  std::endl;
				return true;
			}
			// Или к примеру можно вывести "не хватает ингредиентов"
		}
		else
			std::cout << "Cant CHECK in" << StateNames[state] << "state" << std::endl;

		return false;
	}

	void Automata::cook()
	{
		if ((state == aCheck) & check())
		{
			state = aCook;
			std::cout << "Cook some" <<  std::endl;
		}
		else
			std::cout << "Cant COOK from " << StateNames[state] << "state" << std::endl;
	}

	void Automata::finish()
	{
		if (state == aCook)
		{
			coins -= prices[sel].price;

			if (coins > 0)
			{
				std::cout << "Return" <<  coins << std::endl;
				coins = 0;
			}

			state = aWait;
		}
		else
			std::cout << "Cant FINISH from" << StateNames[state] << "state" << std::endl;
	}

	void Automata::printState()
	{
		std::cout << "State:" << StateNames[state] << std::endl;
	}

