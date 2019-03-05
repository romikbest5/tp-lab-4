#pragma once
#include <iostream>
#include <string>
using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
struct menuitem {
  unsigned int price;
  string name;
};

class Automata{
private:
  unsigned int cash;
  menuitem menu[5]=
  {
    {30, "espresso"},
    {35, "americano"},
    {50, "capuccino"},
    {45, "hot chocolate"},
    {30, "tea"},
  };
  STATES state;
public:
  Automata();
  void on();
  void off();
  void coin(unsigned int);
  void printMenu();
  STATES   printState();
  void choice(unsigned int);
  void check(unsigned int);
  unsigned int cancel();
  void cook(unsigned int);
  unsigned int finish();
  void interface();
};
