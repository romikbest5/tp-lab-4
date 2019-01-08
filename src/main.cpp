#include "Automata.h"

int main() {
    Automata automata1;
    automata1.on();
    automata1.printMenu();
    automata1.coin(50);
    automata1.choice(3);
    automata1.choice(4);
    automata1.off();
    return 0;
}