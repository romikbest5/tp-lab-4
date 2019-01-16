#ifndef CLASS_AUTOMATA_h
#define CLASS_AUTOMATA_h
#pragma once

#define MAX_AMOUNT 8

#include <string>
#include <iostream>

using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };//Состояния процессов автомата
class Automata
{
private:
	/*===== [Переменные] =====*/
	STATES state;				//текущее состояние автомата
	int cash;					//сумма денег в автомате
	string menu[MAX_AMOUNT];	//массив строк названий напитков
	int prices[MAX_AMOUNT];		//массив цен напитков

	int choosen_drink;			//ID выбранного напитка пользователем
	short int checked_status;	//Состояние проверки (0 - Недостаточно денег; 1 - Успех; -1 - Ошибка текущего состояния)

public:
	/*===== [Методы] =====*/
	Automata();//конструктор
	bool on();				//включение автомата
	bool off();				//выключение автомата
	int coin(int);			//занесение денег на счёт пользователем
	void printMenu();		//отображение меню с напитками и ценами для пользователя
	string printState();	//отображение текущего состояния для пользователя
	string choice(int);		//выбор напитка пользователем
	int check(int);			//проверка наличия необходимой суммы
	int cancel();			//отмена сеанса обслуживания пользователем
	int cook();			//имитация процесса приготовления напитка
	int finish();			//завершение обслуживания пользователя.
};

#endif