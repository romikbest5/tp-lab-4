//
// Created by Alexander on 25.02.2019.
//
#pragma once

#include <iostream>
#include <string>
#include "STATES.h"

using namespace std;
const int N = 4;
class Automata {
private:
    int cash,choice_n;
    string menu[4] = { "Tea", "Coffee with milk", "Cappuccino", "Espresso" };
    int prices[4] = { 15, 20, 30, 25 };
    STATES state;







public:
    Automata();
    STATES on();
    STATES off();
    STATES coin(int payment);
    STATES cook();
    STATES cancel();
    STATES finish();
    STATES choice(int choice_number);
    int printCash();
    bool check();
    void money_refund();
    void printState();
    void printMenu();


};