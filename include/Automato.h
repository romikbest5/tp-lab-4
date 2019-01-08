#ifndef AUTOMATO_H
#define AUTOMATO_H
using namespace std;
#include<string>
#include<iostream>

class Automato
{
    public:
        string getState(){return state;};
        int getCash(){return cash;};
        Automato();
        void on();
        void off();
        void menu();
        void coin(int);
        void cancel();
        void choice(int);

    protected:

    private:
        string state;
        int cash;

        void cook(int);
        void finish();
};

#endif // AUTOMATO_H
