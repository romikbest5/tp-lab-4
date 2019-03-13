#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <string>

#define N 5


enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK, ERROR};

class Automata {

private:

    int cash;
    int position;
    int prices[N] = {30, 12, 45, 60, 100};
    STATES state;
    std::string menu[N] = {"tea", "water", "coffee", "juice", "hot chocolate"};

public:

    Automata();
    STATES on();
    STATES off();
    STATES coin(int);
    int getCash();
    int returnMoney();
    void printMenu();
    void printState();
    STATES choice(int);
    bool check();
    STATES cancel();
    STATES  cook();
    STATES restart();
    std::string finish();

};


#endif //TASK1_AUTOMATA_H
