//
// Created by Alexander on 25.02.2019.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <iostream>
#include <string>
using namespace std;
class Automata {
private:
    int cash;
    enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
    string menu[5]={"milk","tea","coffee","espresso","juice"};
    int prices [5]={10, 12, 15, 20, 25};
    STATES state;

    void printMenu(){};
    void pintState(){};

public:
    void on(){};
    void off(){};
    void coin(){};



};

#endif //TASK1_AUTOMATA_H
