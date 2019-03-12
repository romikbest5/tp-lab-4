#include <task.h>


int main() {

    Automata automata1;
    Automata automata2;
    Automata automata;

    automata.on();
    automata.off();
    automata.on();

    automata.coin(1);
    automata.coin(1);

    automata.choice(0);


    return 0;
}