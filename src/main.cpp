#include "Automata.cpp"

int main(){

    Automata * automata = new Automata();

    automata -> printState();

    cout << "==== SHOULD BE IGNORED" << NL;
    automata -> coin(10);
    automata -> cancel();
    automata -> cook ();
    cout << "===============================" << NL;

    automata -> on();
    automata -> printMenu();

    cout << "==== SHOULD BE IGNORED" << NL;
    automata -> cancel();
    automata -> cook ();
    cout << "===============================" << NL;

    automata -> coin (100);
    automata -> choice ("product1");
    automata -> choice (2);

    automata -> cook ();

    return 0;

}