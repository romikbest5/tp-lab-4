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
    cout<<"The current balance: " << printCash() << "\n";
    return state;

}

void Automata::printMenu() {
    cout << "The Menu\n";
    for (int product = 0; product <= N; ++product){
        cout << product+1 <<"."<< menu[product] << " - " << prices[product] << "\n";
    }

}

STATES Automata::choice(int choice_number) {
    if (state == ACCEPT)
        state = CHECK;
    else {
        cout << "The state of the machine must be ACCEPT";
         return state = Wrong_Operation;
    }
    choice_n = choice_number;
    cout << "Your choice is: " << menu[choice_number] << " the price of the product is: "<< prices[choice_number];
    return state;
}

bool Automata::check() {
    if (state != CHECK){
        cout << "The state of the machine must be CHECK";
        return false;
    }
    return (cash >= prices[choice_n]);
}


STATES Automata::cook() {
    if (state == CHECK)
        state = COOK;
    else {
        cout << "The state of the machine must be COOK";
        return state = Wrong_Operation;
    }
    cout << menu[choice_n] << "id preparing";
    return state;
}


int Automata::printCash(){
    return cash;
}




Automata::Automata() {
    cash = 0;
    state = OFF;
}