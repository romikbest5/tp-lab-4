#include "Automata.h"

Automata::Automata() {
  cash=0;
  state=OFF;
}

void Automata::on() {
  cout << "turning on...\n";
  state=WAIT;
  printState();
  printMenu();
}

void Automata::off() {
  cout << "turning off...\n";
  state=OFF;
  printState();
}

void Automata::coin(unsigned int addcoin) {
  if (state==WAIT) {
    state=ACCEPT;
    printState();
    cash+=addcoin;
    cout << "now your credit is: " << cash << "rub.\n";
  }
  else if (state==ACCEPT) {
    cash+=addcoin;
    cout << "now your credit is: " << cash << "rub.\n";
  }
  else if (state==OFF) {
    cout << "machine is not working, turn on first!\n";
  }
}

void Automata::printMenu() {
  cout << "Menu:\n\n";
  for (int i = 0; i < 5; i++) {
    cout << i+1 << ": " << menu[i].name << " - " << menu[i].price << "rub.\n";
  }
}

STATES Automata::printState() {
  string curstate;
  if (state==OFF) curstate = "off";
  else if (state == WAIT) curstate = "waiting";
  else if (state == ACCEPT) curstate = "accepting cash";
  else if (state == CHECK) curstate = "checking credit";
  else if (state == COOK) curstate = "cooking a drink";
  cout << "machine is now " << curstate << "...\n";
  return state;
}

void Automata::choice(unsigned int chosen) {
  chosen-=1;
  if (state==ACCEPT) {
    check(chosen);
  }
  else if (state==OFF) cout << "turn of first!\n";
  else if (state == WAIT) cout << "add coins first!\n";
}

void Automata::check(unsigned int chosen) {
  state=CHECK;
  printState();
  if (cash < menu[chosen].price) {
    cout << "not enough cash, add more coins!\n";
    state=ACCEPT;
    printState();
  }
  else cook(chosen);
}

unsigned int Automata::cancel() {
  if (state==ACCEPT) {
    cout << "returning money: " << cash << "rub.\n";
    unsigned int change = cash;
    cash=0;
    state=WAIT;
    printState();
    printMenu();
    return change;
  }
  else cout << "boop\n";
  return 0;
}

void Automata::cook(unsigned int chosen) {
  state=COOK;
  printState();
  cash-=menu[chosen].price;
  cout << "|         |\n";
  cout << "|...      |\n";
  cout << "|......   |\n";
  cout << "|.........|\n";
  cout << "Your " << menu[chosen].name << " is ready!\n";
  finish();
}

unsigned int Automata::finish() {
  cout << "Thanks for purchasing!\n";
  unsigned int change = 0;
  if (cash > 0) {
    cout << "Your change is " << cash << " rub.\n";
    change = cash;
    cash=0;
  }
  state=WAIT;
  printState();
  printMenu();
  return change;
}
