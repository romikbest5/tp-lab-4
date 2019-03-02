//
// Created by Alexander on 25.02.2019.
//

#include "Automata.h"
#include <iostream>
using namespace std;
int main(){
    Automata a;
    a.on();
    a.printMenu();
    a.coin(30);
    a.choice(3);
    a.cook();
    a.finish();
    a.off();
    a.printState();


}

