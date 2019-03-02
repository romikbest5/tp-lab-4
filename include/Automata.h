//
// Created by Alexander on 25.02.2019.
//
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Automata {
private:
    int cash;
    string menu[4] = { "tea", "coffee with milk", "cappuccino", "espresso" };
    int prices[4] = { 15, 20, 30, 25 };
    enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
    STATES state;

    void printMenu();
    void cook();
    void finish();
    void PrintState();


public:
    Automata();
    void on();
    void off();

};