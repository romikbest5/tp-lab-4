//
// Created by Константин Чернышев on 04.01.19.
//

#ifndef TASK_TASK_H
#define TASK_TASK_H

#include <vector>
#include <iostream>

#include <cstdlib>
#include <unistd.h>
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60


enum States {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
private:
    int cash;
    static const std::vector<std::string> menu;
    static const std::vector<int> prices;
    States state;

    bool check(int num); // - проверка наличия необходимой суммы;
    bool cook(int num); // - имитация процесса приготовления напитка;
    void finish(); // - завершение обслуживания пользователя.
    void printProgress(double percentage);

public:
    Automata();
    void on(); // - включение автомата;
    void off(); // - выключение автомата;
    void coin(int delta); // - занесение денег на счёт пользователем;
    void printMenu(); // - отображение меню с напитками и ценами для пользователя;
    void printState(); // - отображение текущего состояния для пользователя;
    bool choice(int num); // - выбор напитка пользователем;

    void cancel(); // - отмена сеанса обслуживания пользователем;

    //Debug
    int getCash();
    States getState();
    bool getDrink(int num);
};



#endif //TASK_TASK_H
