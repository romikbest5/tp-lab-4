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
    int cash;
    string menu[4] = { "tea", "coffee with milk", "cappuccino", "espresso" };
    int prices[4] = { 15, 20, 30, 25 };
    STATES state;

    void printMenu();
    void cook();
    void finish();
    void PrintState();


public:
    Automata();
    STATES on();
    STATES off();
    int printCash();
    STATES coin(int payment);

};