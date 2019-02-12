#ifndef _AUTOMATA_H
#define _AUTOMATA_H_
#pragma once

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
	array <string, 7> menu{ { "Caffe espresso", "Caffe lungo", "Cappussino", "Cap-coik", "Latte", "Cicollato", "Cicollato forte" } };
	array <int, 7> prices{ { 28, 30, 30, 35, 30, 40, 42 } };
	int choice_int;
	STATES state;
public:
	Automata(){	
	}
	void Automata::on();
	void Automata::off();
	void Automata::coin(int money); 
	void Automata::printMenu();
	STATES Automata::printState();
	void choice(int ch);
	void Automata::check(); 
	int Automata::getChange();
	void cancel();
	void cook(); 
	void Automata::finish();
};
#endif