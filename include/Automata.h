//
// Created by Alexander on 25.02.2019.
//
#pragma once

#include <iostream>
#include <string>

using namespace std;
const int N = 4;
enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK, Wrong_Operation };
class Automata {
private:
    int cash,choice_n;
    string menu[4] = { "Tea", "Coffee with milk", "Cappuccino", "Espresso" };
    int prices[4] = { 15, 20, 30, 25 };
    STATES state;
    bool check();






public:
    Automata();
    STATES on();
    STATES off();
    STATES coin(int payment);
    STATES cook();
    STATES cancel();
    STATES finish();
    STATES choice(int choice_number);
    int getCash();
    void money_refund();
    STATES printState();
    void printMenu();


};