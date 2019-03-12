//
// Created by Константин Чернышев on 04.01.19.
//

#include <task.h>

const std::vector<std::string> Automata::menu{"Coffe", "Tea", "Water", "Limoncello"};
const std::vector<int> Automata::prices{20, 10, 3, 42};


Automata::Automata() {
    state = States::OFF;
    cash = 0;
}


void Automata::on() {
    if (state == States::OFF)
        state = States::WAIT;
}


void Automata::off() {
    if (state == States::WAIT)
        state = States::OFF;
}

void Automata::coin(int delta) {
    if (state == States::WAIT || state == States::ACCEPT) {
        if (delta >= 0) {
            cash += delta;

            std::cout << "Cash:  " << cash << std::endl;
        }
    }
}

bool Automata::choice(int num) {
    if (state == States::ACCEPT || state == States::WAIT) {
        state = States::CHECK;
        if (check(num)) {
            state = States::COOK;
            return cook(num);
        } else {
            cancel();
        }
    }

    return false;
}

void Automata::cancel() {
    if (state != States::OFF)
        state = States::WAIT;
}

bool Automata::check(int num) {
    if (cash >= Automata::prices[num]) {
        cash -= Automata::prices[num];
        return true;
    }
    std::cout << "A lack of Cash!" << std::endl;
    return false;
}

void Automata::printProgress (double percentage)
{
    int val = (int) (percentage);
    int lpad = (int) (percentage / 100 * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush (stdout);
}



bool Automata::cook(int num) {
    std::cout << "Cooking: " << Automata::menu[num] << std::endl;
    for (int i = 0; i <= 100; i += 2) {
        Automata::printProgress(i);
        usleep(100000);
    }

    Automata::finish();


    std::cout << std::endl << "Done: " << Automata::menu[num] << std::endl;

    return true;
}

void Automata::finish() {
    state = States::WAIT;
}


// Debug

States Automata::getState() {
    return this->state;
}

int Automata::getCash() {
    return this->cash;
}

bool Automata::getDrink(int num) {
    return choice(num);
}
