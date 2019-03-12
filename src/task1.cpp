#include "Header.h"

Automata::Automata() 
{
	this->state = OFF;
	this->cash = 0;
}

void Automata::on() 
{
	if (state == OFF) {
		this->state = WAIT;
		cout << "Hello!" << endl;
	}
}

void Automata::off()
{
	if (this->state == WAIT) {
		this->state = OFF;
		cout << "Goodbye!" << endl;
	}
}

void Automata::cancel() 
{
	if (this->state != OFF)
	{
		this->state = WAIT;
	}
}

void Automata::coin(unsigned int currency)
{
	if (this->state == WAIT || this->state == ACCEPT) 
	{
		this->cash += currency;
		cout << "Cash:  " << currency << std::endl;
	}
}

void Automata::choice(unsigned int num)
{
	if (this->state == WAIT || this->state == ACCEPT) 
	{
		this->state = CHECK;
		if (check(num)== true)
		{
			this->state = COOK;
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
	if (this->cash>= this->prices[num-1]) 
	{
		this->cash -= prices[num-1];
		return true;
	}
	else 
	{
		cout << "Not enough cash" << endl;
		return false;
	}
}

void Automata::cook(unsigned int num) 
{
	cout << "Cooking" << endl;
	this->state = WAIT;
	cout << "Ready" << endl;
	
}
int Automata::getCash() 
{
	cout << "Get cash" <<endl;
	return this->cash;
}


