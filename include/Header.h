#include <vector>
#include <iostream>
using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata 
{
private:
	STATES state;
	unsigned int cash;
	vector<string> menu{ "Americano", "Latte", "Cappucino", "Tea" };
	vector<unsigned int> prices{ 30, 40, 25, 20 };
public:
	Automata();
	void on(); // включение автомата
	void off(); // выключение автомата
	void coin(unsigned int); // занесение денег на счёт пользователем
	void cancel(); // отмена сеанса обслуживания пользователем
	bool check(unsigned int); //проверка наличия необходимой суммы
	void choice(unsigned int); //выбор напитка пользователем
	void cook(unsigned int); //имитация процесса приготовления напитка
	int getCash();
};
