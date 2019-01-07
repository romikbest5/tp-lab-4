#include "Automata.h"
#include <iostream>
#include <string>
#include "prob.h"
using namespace std;

void f1(){
	Automata aut1;
	aut1.on();
	aut1.printState();
	aut1.coin(90);
	aut1.printMenu();
	aut1.choice(2);
	aut1.change();
	aut1.off();
}

void f2(){
	Automata aut2;
	aut2.printState();
	aut2.printMenu();
	aut2.coin(90);
	aut2.choice(2);
	aut2.change();
	aut2.off();
	aut2.on();
}

void f3() {
	int c = 0;
	Automata aut3;
	aut3.on();
	aut3.printMenu();
	cout << "Give money: ";
	cin >> c;
	aut3.coin(c);
	aut3.printState();
	cin >> c;
	aut3.coin(c);
	aut3.choice(4);
	cin >> c;
	aut3.coin(c);
	aut3.choice(4);
	aut3.choice(2);
	aut3.choice(1);
	aut3.change();
}

void f4() {
	Automata aut4;
	aut4.on();
	aut4.coin(50);
	aut4.off();
}

int main() {
	f1();
	//system("cls");
	system("pause");
}