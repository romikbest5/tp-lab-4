#include "Automata.h"

Automata::Automata() {
    this->state = OFF;
    this->cash = 0;
}

void Automata::on() {
    if (state == OFF) {
        this->state = IDLE;
        std::cout << "Hello!" << std::endl;
    }
}

void Automata::off() {
    if (this->state == IDLE) {
        this->state = OFF;
        std::cout << "Goodbye!" << std::endl;
    }
}

void Automata::cancel() {
    if (this->state != OFF) {
        this->state = IDLE;
    }
}

//adds cash to automata
void Automata::coin(unsigned int money) {
    if (this->state == IDLE && this->cash < UINT_MAX - money)  {
        this->cash += money;
        std::cout << std::to_string(this->cash) + " cash available" << std::endl;
    }
}

//here user chooses drink
void Automata::choice(unsigned int number) {
    if (this->state == IDLE || this->state == ACCEPT) {
        this->state = CHECK;
        bool enough = check(number);
        if (enough) {
            this->state = COOK;
            cook(number);
        } else {
            std::cout << "Not enough cash" << std::endl;
            cancel();
        }
    }
}

bool Automata::check(unsigned int number) {
    if (number <= this->drinks.size()) {
        return this->cash >= this->prices[number-1];
    } else {
        return false;
    }
}

void Automata::cook(unsigned int number) {
    this->cash -= this->prices[number-1];
    this->state = IDLE;
    std::cout << "Enjoy your " + this->drinks[number-1] + "!" << std::endl;
}

void Automata::printMenu() {
    for (size_t i=0; i< drinks.size(); i++) {
        std::cout << std::to_string(i+1) + ". " + this->drinks[i] + " : " + std::to_string(this->prices[i]) << std::endl;
    }
}

unsigned int Automata::getCash() {
    return this->cash;
}

STATES Automata::getState() {
    return this->state;
}
