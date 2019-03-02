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



    void finish();



public:
    Automata();
    STATES on();
    STATES off();
    bool check();
    STATES cook();
    int printCash();
    STATES choice(int choice_number);
    void PrintState();
    void printMenu();
    STATES coin(int payment);

};