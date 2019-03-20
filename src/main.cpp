#include "Automata.h"

#include <iostream>

using namespace std;

int main()
{
    Automata machine;
    machine.printState();
    cout << "Turning ON" << endl;
    machine.on();
    machine.printState();
    cout << "Try to cancel nothing: " << endl;
    machine.cancel();
    machine.printState();
    cout << "Restart" << endl;
    machine.restart();
    machine.printState();
    cout << "Add 5 coins" << endl;
    machine.coin(5);
    machine.printState();
    cout << "Cash: " << machine.getCash() << endl;
    machine.printMenu();
    cout << "Try to get coffee (45 rub):" << endl;
    machine.choice(2);
    machine.printState();
    cout << boolalpha << "Fail checking: " <<  machine.check() << endl;
    machine.printState();
    cout << "Try to cook it: " << endl;
    machine.cook();
    machine.printState();
    cout << "Add enough coins" << endl;
    machine.coin(100);
    machine.printState();
    cout << "Try to get coffee (45 rub):" << endl;
    machine.choice(2);
    machine.printState();
    cout << "Cash: " << machine.getCash() << endl;
    cout << boolalpha << "True checking: " <<  machine.check() << endl;
    machine.printState();
    cout << "Cooking: " << endl;
    machine.cook();
    machine.printState();
    cout << "Finish working: " << endl;
    machine.finish();
    machine.printState();
    cout << "Off the machine" << endl;
    machine.off();
    machine.printState();
    return 0;
}

