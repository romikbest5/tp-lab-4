#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <map>
#include <vector>
#include <iostream>
#include <climits>

enum STATES {OFF, IDLE, ACCEPT, CHECK, COOK};

class Automata{
private:
    STATES state;
    unsigned int cash;
    std::vector<std::string> drinks {"Hot water", "Black tea", "Latte", "Cappucino"};
    std::vector<unsigned int> prices {10, 15, 35, 30};
public:
    //Constructor
    Automata();
    //Getters
    STATES getState();
    unsigned int getCash();
    //Methods
    void on();
    void off();
    void coin(unsigned int);
    void cancel();
    bool check(unsigned int);
    void choice(unsigned int);
    void cook(unsigned int);
    void printMenu();
};

#endif //TASK1_AUTOMATA_H
