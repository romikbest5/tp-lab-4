//
// Created by Alexander on 25.02.2019.
//
#include "Automata.h"
#include <string>


using namespace std;

STATES Automata::on() {
    state = WAIT;
    cout << "Machine is working"<<endl;
    return state ;
}
STATES Automata::off() {
   if (state == WAIT) {
       state = OFF;
       cout<<"The machine is off"<<endl;
       return state ;
   } else {
       cout << "The state of the machine must be WAIT"<<endl;
       return state = Wrong_Operation;
   }
}



void Automata::printState() {
    switch (state)
    {
        case(OFF):
            cout<<"The machine is OFF"<<endl;
            break;
        case (WAIT):
            cout<<"Waiting..."<<endl;
            break;
        case (ACCEPT):
            cout<<"Insert money "<<endl;
            break;
        case (CHECK):
            cout<<"Cash cheking, wait a minute please"<<endl;
            break;
        case (COOK):
            cout<<"The product is cooking"<<endl;
            break;
        case (Wrong_Operation):
            cout<<"Error!"<<endl;
            break;


    }
}
STATES Automata::coin(int payment) {
    cash += payment ;
    if (state == WAIT){
        state = ACCEPT;
    }
    else if ((state != ACCEPT)&&(state != CHECK)){
        cout << "The state of the machine must be ACCEPT, WAIT or CHECK. "
                "Please try again!"<<endl;
        return state = Wrong_Operation;
    }
    cout<<"The current balance: " << printCash() <<endl;
    return state;

}

void Automata::printMenu() {
    cout << "The Menu\n";
    for (int product = 0; product < N; ++product){
        cout << product+1 <<"."<< menu[product] << " - " << prices[product] <<endl;
    }

}

STATES Automata::choice(int choice_number) {
    if (state == ACCEPT)
        state = CHECK;
    else {
        cout << "The state of the machine must be ACCEPT"<<endl;
         return state = Wrong_Operation;
    }
    choice_n = choice_number;
    cout << "Your choice is: " << menu[choice_number] << " the price of the product is: "<< prices[choice_number]<<endl;
    return state;
}

bool Automata::check() {
    return (cash >= prices[choice_n]);
}


STATES Automata::cook() {

    if (state != CHECK) {
        cout << "The state of the machine must be CHECK"<<endl;
        return state = Wrong_Operation;
    } else {
        state = COOK;
    }
    if (check()){
        cash -= prices[choice_n];
    } else {
        cout << "Not enough money on balance. Please replenish it"<<endl;
        return state;
    }

    cout << menu[choice_n] << " is cooking"<<endl;
    return state;
}

void Automata::money_refund() {
    cout << "Take your money: "<< cash<<endl;
    cash = 0;
}



STATES Automata::cancel(){
    if ((state != ACCEPT) &&(state != CHECK)) {
        cout << "The state of the machine must be CHECK or ACCEPT";
        return state = Wrong_Operation;
    } else if (cash == 0) {
        state = WAIT;
        return state;
    } else {
        money_refund();
        state = WAIT;
        return state;
    }
}

STATES Automata::finish() {
    if (state != COOK){
        cout << "The state of the machine must be COOK";
        return state = Wrong_Operation;
    }
    if (cash != 0)
        money_refund();

    state = WAIT;
    return state;
}


int Automata::printCash(){
    return cash;
}




Automata::Automata() {
    cash = 0;
    state = OFF;
}