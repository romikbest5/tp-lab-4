#include "Automata.h"


Automata::Automata()
{
	state = aOff;
	this->coins = 0;
}

void Automata::on()
{
	if (state == aOff) {
		this->state = aWait;
		std::cout << "Hello!" << std::endl;
	}
}

void Automata::off()
{
	if (this->state == aWait) {
		state = aOff;
		std::cout << "Bye!" << std::endl;
	}
}

void Automata::coin(unsigned int currency)
{
	if (this->state == aWait || this->state == aAccept)
	{
		this->coins += currency;
		std::cout << "Cash:  " << currency << std::endl;
	}
}

void Automata::cancel()
{
	if (this->state != aOff) {
		this->state = aWait;
		std::cout << " Return " << coins << " coins" << std::endl;
		coins = 0;
	}
}

void Automata::choice(unsigned int num)
{
	if (this->state == aWait || this->state == aAccept)
	{
		this->state = aCheck;
		if (check(num) == true)
		{
			this->state = aCook;
			cook(num);
		}
		else
		{
			cancel();
		}

	}
}

bool Automata::check(unsigned int num)
{
	if (this->coins >= this->price[num - 1])
	{
		this->coins -= price[num - 1];
		return true;
	}
	else
	{
		cout << "Not enough cash!" << endl;
		return false;
	}
}

void Automata::cook(unsigned int num)
{
	if ((state == aCheck) & (check(num) == true))
	{
		std::cout << "Please,wait. Your drink is cooking." << std::endl;
		this->state = aWait;
		std::cout << "Ready!Please, take a drink." << std::endl;
	}
}

int Automata::getCash()
{
	cout << "Get cash" << endl;
	return this->coins;
}


