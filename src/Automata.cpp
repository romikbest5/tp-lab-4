//
// Created by Alexander on 25.02.2019.
//
#include "Automata.h"
#include <string>


using namespace std;

STATES Automata::on() {
    state = WAIT;
    cout << "Machine is working\n";
    return state;
}

STATES Automata::coin(int payment) {
    cash += payment ;
    if (state == WAIT){
        state = ACCEPT;
    }
    else if ((state != ACCEPT)&&(state != CHECK)){
        cout << "The state of the machine must be ACCEPT, WAIT or CHECK. "
                "Please try again!";
        state = Wrong_Operation;
    }
    return state;

}

void Automata::printMenu() {
    cout << "The Menu\n";
    for (int product = 0;)
}

int Automata::printCash(){
    return cash;
}




Automata::Automata() {
    cash = 0;
    state = OFF;
}