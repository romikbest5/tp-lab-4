//
// Created by Илья on 07.01.2019.
//

#include "../include/Automata.h"

Automata::Automata() {
    state = OFF;
}

STATES Automata::on(){
    cash = 0;
    state = WAIT;
    return state;
}

STATES Automata::off() {
    if (state==WAIT)
        state = OFF;
    else {
        std::cout << "Is a not WAIT station" << std::endl;
        return state = error;
    }
    return state;
}

STATES Automata::coin(double money) {
    cash = cash + money;
    if (state == WAIT)
        state = ACCEPT;
    else if ((state != ACCEPT)&&(state != CHECK)) {
        std::cout << "Is a not ACCEPT, CHECK or WAIT station" << std::endl;
        return state = error;
    }
    return state;
}

void Automata::printMenu() {
    std::cout<<"|======[MENU]======|"<<std::endl;
    for (int i = 0; i < N; i++)
        std::cout<<"|  "<<i+1<<": "<<menu[i]<<"    "<<prices[i]<<" |"<<std::endl;
    std::cout<<"|======[MENU]======|"<<std::endl;
}

STATES Automata::printState() {
    if (state == OFF)
        std::cout<<"OFF"<<std::endl;
    else if (state == WAIT)
        std::cout << "WAIT"<<std::endl;
    else if (state == ACCEPT)
        std::cout << "ACCEPT"<<std::endl;
    else if (state == CHECK)
        std::cout << "CHECK"<<std::endl;
    else if (state == COOK)
        std::cout << "COOK"<<std::endl;
    else
        std::cout << "ERROR!"<<std::endl;

    return state;
}

double Automata::getCash() {
    std::cout<<cash<<std::endl;
    return cash;
}

double Automata::getSurplus() {
    double c = cash;
    cash = 0;
    std::cout << "Surplus: "<< c << std::endl;
    return c;
}

STATES Automata::cancel(){
    if ((state == ACCEPT)||(state == CHECK)) {
        state = WAIT;
        if (cash != 0) {
            getSurplus();
        }
    }
    else {
        std::cout << "Is a not ACCEPT or CHECK station" << std::endl;
        return state = error;
    }
    return state;
}

STATES Automata::choice(int i) {
    if (state == ACCEPT)
        state = CHECK;
    else{
        std::cout<<"Is a not ACCEPT station"<<std::endl;
        return state = error;
    }
    position = i;
    std::cout<<"[ Your choose: "<<menu[position]<<" "<<prices[position]<<" ]"<<std::endl;

    return state;
}

bool Automata::check() {
    if (state != CHECK) {
        std::cout << "Is a not CHECK station" << std::endl;
        return false;
    }
    return (cash >= prices[position]);
}

STATES Automata::cook() {
    if (state != CHECK) {
        std::cout << "Is a not CHECK station" << std::endl;
        return state = error;
    }
    if (check()){
        cash = cash - prices[position];
        state = COOK;
    }
    else
        std::cout<<"Insufficient funds, Deposit your account"<<std::endl;
    return state;
}

std::string Automata::finish(){
    if (state != COOK){
        std::cout << "Is a not COOK station" << std::endl;
        return "error";
    }
    state = WAIT;
    getSurplus();
    return "Get you surplus and drink.";
}