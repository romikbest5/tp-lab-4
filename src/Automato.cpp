#include "Automato.h"

const string drinks[3] {"Nescafe","Neste","Nuri"};
const int price[3] {25,31,18};
const int size_of_menu=3;

Automato::Automato()
{
    state="off";
    cash=0;
}

void Automato::on()
{
    if (state=="off")
    {
        state="wait";
    }
}

void Automato::off()
{
    state="off";
}

void Automato::menu()
{
    for (int i=0;i<size_of_menu;i++)
    {
        cout<<i+1<<")"<<drinks[i]<<" - "<<price[i]<<"p"<<endl;
    }
}

void Automato::coin(int money)
{
    if (state=="wait")
    {
        state="accept";
    }
    if (state=="accept")
    {
        cash+=money;
    }
}

void Automato::cancel()
{
    if (state=="accept")
    {
        cash=0;
        state="wait";
    }
}

void Automato::choice(int position)
{
    if (state=="accept")
    {
        position--;
        if (position > 0 && position < size_of_menu)
        {
            state="check";
            if (cash >= price[position])
            {
                cash-=price[position];
                cash=0; //change
                this->cook(position);
            }
            else
            {
				state="accept";
            }
        }
    }
}

void Automato::cook(int position)
{
    state="cook";
    //cooked
    this->finish();
}

void Automato::finish()
{
    state="wait";
}

