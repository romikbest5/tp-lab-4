#pragma once
//#include <iostream>
#include <string>
using namespace std;

#ifndef _AUTOMATA_H_
#define _AUTOMATA_H_

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;              //для хранения текущей суммы
	string menu[4] = { "Cappuccino", "Latte     ", "Espresso  ", "Americano " };       //массив строк названий напитков
	int prices[4] = { 70, 80, 90, 100 };        //массив цен напитков(соответствует массиву menu)
	STATES state = OFF;    //текущее состояние автомата
	void cook(int);
	string finish();

public:
	Automata();
	string on();             //включение автомата 
	string off();            //выключение автомата
	int coin(int);           //занесение денег на счет пользователем 
	void printMenu();      //отображение меню с напитками и ценами для пользователя
	string printState();     //отображение текущего состояния для пользователя
	string choice(int);         //выбор напитка пользователем;
	//void check(int);          //проверка наличия необходимой суммы;
	//void cancel();         //отмена сеанса обслуживания пользователем;
	int change();        //сдача
};

#endif