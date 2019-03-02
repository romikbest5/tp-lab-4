//
// Created by Alexander on 25.02.2019.
//
#include "Automata.h"
#include <string>

using namespace std;

void Automata::on() {
    state = WAIT;
    cout << "Machine is working\n";
}




Automata::Automata() {
    cash = 0;
    state = OFF;
}