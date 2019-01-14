#include <iostream>
#include "Automato.h"

int main()
{
    
    Automato Coffe;
    Coffe.on();
    Coffe.coin(10);
    Coffe.choice(3);
    Coffe.menu();
    Coffe.coin(5);
    Coffe.coin(3);
    Coffe.choice(3);
}
