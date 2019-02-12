#ifndef _AUTOMATA_H
#define _AUTOMATA_H
#pragma once
#include <array>
#include <string>
typedef enum{
	OFF, //0
	WAIT, //1
	ACCEPT, //2
	CHECK, //3
	COOK //4
}STATES;

class Automata{
private:
	int cash;
	int cash_tmp=0;
	string menu[7]={ "Caffe espresso", "Caffe lungo", "Cappussino", "Cap-coik", "Latte", "Cicollato", "Cicollato forte" } ;
	int prices[7]= { 28, 30, 30, 35, 30, 40, 42 } ;
	int choice_int;
	STATES state;
public:
	Automata();
	void on();
	void off();
	void coin(int money); 
	void printMenu();
	STATES printState();
	void choice(int ch);
	void check(); 
	int getChange();
	void cancel();
	void cook(); 
	void finish();
};
#endif
