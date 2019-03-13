#include "Automata.h"

#include <iostream>

using namespace std;


Automata::Automata()
{
    state = OFF;
    cash = 0;
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
        cout << "Automata should be in WAIT condition" << endl;
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
       cout << "In order to add money, keep Automata in WAITING, ACCEPTING or CHECKING condition" << endl;
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
    cout << "Please, take your money: " << cash << " rub" << endl;
    int num(cash);
    state = WAIT;
    cash = 0;
    return num;

}
void Automata::printMenu()
{
    cout << "Menu: " << endl;
    for (int i(0); i < N; i++)
        cout << i << ". " << menu[i] << " | " << prices[i] << endl;
}

void Automata::printState()
{
    cout << "Your current state is: ";
    switch(state)
    {
        case OFF:
            cout << "OFF" << endl;
            break;
        case WAIT:
            cout << "WAITING" << endl;
            break;
        case ACCEPT:
            cout << "ACCEPTING" << endl;
            break;
        case CHECK:
            cout << "CHECKING" << endl;
            break;
        case COOK:
            cout << "COOKING" << endl;
            break;
        default:
            cout << "STATE error" << endl;
            break;
    }
}

STATES Automata::choice(int option)
{
    if (state == ACCEPT)
        state = CHECK;
    else
    {
        cout << "Automata is not in ACCEPT condition" << endl;
        return state = ERROR;
    }
    position = option;
    if (position < N)
        cout << "Your choice: " << menu[position] << " | " << prices[position] << endl;
    else
    {
        state = ERROR;
        cout << "Incorrect number" << endl;
    }
    return state;
}

bool Automata::check()
{
    if (state == CHECK)
        return (cash >= prices[position]);
    else
        cout << "Automata should be in CHECKING state" << endl;
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
        cout << "Automata should be in CHECKING or ACCEPTING state" << endl;
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
            cout << "COOKING." << endl;
            cout << "COOKING..." << endl;
            cout << "COOKING....." << endl;
            cout << "COOKING......." << endl;
        }
        else
            cout << "Sorry, you do not have enough cash" << endl;
    } else
    {
        cout << "Automata should be in ACCEPTING or CHECKING stage" << endl;
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
        cout << "Your machine is working properly" << endl;
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
        cout << ans << endl;
        return ans;
    }
    cout << ans << endl;
    return ans;

}

