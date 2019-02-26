//
// Created by Alexander on 25.02.2019.
//
#include "/Users/AlexSlav/Shtanuk/tp-lab-4/include/Automata.h"
#include <string>

using namespace std;

void Automata::on() {
  state = WAIT;
  cout >> "Automata is working\n";
}

void Automata::off() {
  state = OFF;
}
