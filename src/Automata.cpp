#include "Automata.h"

#include <iostream>

using namespace std;


Automata::Automata(ostream* message) : cash(0), position(-1), state(OFF) // Default message value = nullptr
{
    if (message == nullptr)
        this->message = &cout;
    else
        this->message = message;
}

STATES Automata::Automata::on()
{
    if (state == OFF)
        state = WAIT;
    return state;
}

STATES Automata::off()
{
    if (state == WAIT)
        state = OFF;
    else
    {
        (*message) << "Automata should be in WAIT condition\n";
        state = ERROR;
    }
    return state;
}
STATES Automata::coin(int sum)
{
   if (state == WAIT || state == ACCEPT || state == CHECK)
   {
       state = ACCEPT;
       cash += sum;
   }
   else
   {
       (*message) << "In order to add money, keep Automata in WAITING, ACCEPTING or CHECKING condition\n";
       state = ERROR;
   }
    return state;
}

int Automata::getCash()
{
    return cash;
}

int Automata::returnMoney()
{
    (*message) << "Please, take your money: " << cash << " rub\n";
    int num(cash);
    state = WAIT;
    cash = 0;
    return num;

}
void Automata::printMenu()
{
    (*message) << "Menu:\n";
    for (int i(0); i < N; i++)
        (*message) << i << ". " << menu[i] << " | " << prices[i] << '\n';
}

void Automata::printState()
{
    (*message) << "Your current state is: ";
    switch(state)
    {
        case OFF:
            (*message) << "OFF\n";
            break;
        case WAIT:
            (*message) << "WAITING\n";
            break;
        case ACCEPT:
            (*message) << "ACCEPTING\n";
            break;
        case CHECK:
            (*message) << "CHECKING\n";
            break;
        case COOK:
            (*message) << "COOKING\n";
            break;
        default:
            (*message) << "STATE error\n";
            break;
    }
}

STATES Automata::choice(int option)
{
    if (state == ACCEPT)
        state = CHECK;
    else
    {
        (*message) << "Automata is not in ACCEPT condition\n";
        return state = ERROR;
    }
    position = option;
    if (position < N)
        (*message) << "Your choice: " << menu[position] << " | " << prices[position] << '\n';
    else
    {
        state = ERROR;
        (*message) << "Incorrect number\n";
    }
    return state;
}

bool Automata::check()
{
    if (state == CHECK)
        return (cash >= prices[position]);
    else
        (*message) << "Automata should be in CHECKING state\n";
    return false;
}

STATES Automata::cancel()
{
    if ((state == CHECK) || (state == ACCEPT))
    {
        state = WAIT;
        if (cash != 0)
            returnMoney();

    }
    else
    {
        (*message) << "Automata should be in CHECKING or ACCEPTING state\n";
        state = ERROR;
    }
    return state;
}

STATES Automata:: cook()
{
    if ((state == ACCEPT) || (state == CHECK))
    {
        if (check())
        {
            cash -= prices[position];
            state = COOK;
            (*message) << "COOKING.\n";
            (*message) << "COOKING...\n";
            (*message) << "COOKING.....\n";
            (*message) << "COOKING.......\n";
        }
        else
            (*message) << "Sorry, you do not have enough cash\n";
    } else
    {
        (*message) << "Automata should be in ACCEPTING or CHECKING stage\n";
        state = ERROR;
    }

    return state;
}
STATES Automata::restart()
{
    if (state == ERROR)
    {
        if (cash != 0)
            returnMoney();
        state = WAIT;
    }
    else
        (*message) << "Your machine is working properly\n";
    return state;
}
std::string Automata::finish()
{
    string ans = "Get your drink";
    if (state == COOK)
    {
        state = WAIT;
        returnMoney();
    }
    else
    {
        ans = "Automata should be in COOKING state";
        (*message) << ans << '\n';
        return ans;
    }
    (*message) << ans << '\n';
    return ans;

}

