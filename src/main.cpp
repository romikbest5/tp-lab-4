#include "Automata.h"

int main(){
  Automata wending;
  wending.on();
  wending.coin(10);
  wending.cancel();
  wending.coin(20);
  wending.choice(1);
  wending.coin(40);
  wending.choice(1);
  wending.off();
  return 0;
}
