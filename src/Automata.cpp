#include <iostream>
#include <algorithm>
#include "Automata.h"

static string NL = "\n";

enum BANKNOTES{

    M1 = 1, M2 = 2, M5 = 5, M10 = 10, M25 = 25, M50 = 50,
    M100 = 100, M200 = 200, M500 = 500, M1000 = 1000,
    M2000 = 2000, M5000 = 5000

};

Automata::Automata(const string &path = R"(..\content\menu.txt)", ostream *message = nullptr)
        : choiceCash(0), cash(0), profit(0), state(OFF){

    setMenu(path);

    if (message == nullptr)
        this->message = &(cout);
    else
        this->message = message;

    *(this->message) << "# Automata created" << NL;

}

void Automata::setMenu(const string &path = R"(..\content\menu.txt)"){

    try {

        ifstream readerOfMenu;
        readerOfMenu.open(path);

        string position;

        while (getline(readerOfMenu, position)) {

            auto pos = position.find('-');
            menu.push_back(position.substr(0, pos - 1));
            prices[menu.back()] = stoi(position.substr(pos + 1));

        }

        readerOfMenu.close();

    }catch (exception e){
        state = ERROR;
        (*message) << ERROR;
    }

}

void Automata::ignore (){
    (*message) << "# Ignored" << NL;
}

void Automata::reset(){

    cash = 0;
    choiceCash = 0;
    choices.clear();
    menu.clear();
    prices.clear();
    setMenu();

    state = WAIT;

    (*message) << "# Reset" << NL;

    printState();

}

STATES Automata::getState(){
    return state;
}

void Automata::on(){

    if (state == OFF)
        state = WAIT;
    else
        ignore();

    printState();

}

void Automata::off(){

    if (state == WAIT)
        state = OFF;
    else
        ignore();

    printState();

}

void Automata::coin(money d){

    if ((state == WAIT || state == ACCEPT) && d > 0){
        cash += d;
        (*message) << "Received " << d << NL;
        state = ACCEPT;
    }else
        ignore();

    printState();

}

void Automata::printMenu(){

    if (state != OFF) {
        (*message) << "=== Menu" << NL;
        for (const auto &i : menu)
            (*message) << i << " - " << prices[i] << NL;
        (*message) << "============================" << NL;
    }

}

void Automata::printState(){
    (*message) << "# Current state is " << states[state] << NL;
}

bool Automata::choice (int g){
    return choice (g < (int)menu.size() ? menu[g] : "-1");
}

bool Automata::choice (string e){

    if (state == ACCEPT || state == CHECK){

        bool re = false;

        if (prices[e] != 0){
            (*message) << "Your choice is " << e << " - " << prices[e] << NL;
            re = true;
        }

        if (re) {
            state = CHECK;
            re = check (e);
            if (re) {
                choices.push_back(e);
                choiceCash += prices[e];
            }
        }else
            (*message) << "No such goods" << NL;

        printState();

        return re;

    }

    ignore();
    printState();

    return false;

}

bool Automata::check(const string &e){

    if (state == CHECK){
        int price = prices[e];
        if (price <= cash - choiceCash)
            return true;
        else{
            (*message) << "Don't enough cash" << NL;
            state = ACCEPT;
            return false;
        }
    }

    ignore();

    return false;

}

void Automata::cancel(){

    if (state == ACCEPT || state == CHECK || state == FINISH){
        state = WAIT;
        (*message) << "Get back your cash = " << cash << NL;
        reset();
        return;
    }

    ignore();
    printState();

}

void Automata::cook(){

    if (state == CHECK){
        state = COOK;
        cash -= choiceCash;
        profit += choiceCash;
        for (const string &i : choices)
            (*message) << "You buy " << i << NL;
        finish();
        return;
    }

    ignore();
    printState();

}

void Automata::finish(){

    if (state == COOK){
        state = FINISH;
        cancel();
        return;
    }

    ignore();
    printState();

}

money Automata::getProfit(){
    return profit;
}
