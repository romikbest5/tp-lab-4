#include <Automata.h>

using namespace std;

/*===== [����������� ������] =====*/
Automata::Automata()
{
	state = OFF;
	cash = 0;

	string tmp_menu[] =
	{
		"Espresso",
		"Double Espresso",
		"Americano",
		"Coffee with Milk",
		"Coffee with Chocolate",
		"Cappuccino",
		"Latte",
		"Mocachino"
	};
	int tmp_prices[] = { 25, 35, 40, 35, 40, 35, 40, 40 };

	for (int i = 0; i < MAX_AMOUNT; i++)
	{
		prices[i] = tmp_prices[i];
		menu[i] = tmp_menu[i];
	}
};
/*===== [�����: �������� �������] =====*/
bool Automata::on()
{
	if (state == OFF)
	{
		cout << "[...]The Automata turns on, please wait..." << endl;
		for (int i = 0; i < 1000000000; i++);
		cout << "\t[ Y ]The Automata is ON." << endl;
		state = WAIT;
		cout << endl << printState() << endl << endl;
		return true;
	}
	return false;
}
/*===== [�����: ��������� �������] =====*/
bool Automata::off()
{
	if (state != OFF)
	{
		if (state == ACCEPT || state == CHECK || state == COOK) cout << "[ ! ]The Automata was turned OFF abnormally!" << endl;
		else cout << "\t[ X ]The Automata is OFF" << endl;
		cout << "==========================================" << endl << endl;
		state = OFF;
		return true;
	}
	return false;
}
/*===== [�����: ������� �����] =====*/
int Automata::coin(int sum)
{
	state = ACCEPT;
	cout << endl << printState() << endl << endl;
	if (sum >= 0 && sum <= 100)
	{
		cash += sum;
		cout << "[ $ ]You have already inserted cash in amount of: " << cash << endl;
	}
	else cout << "[ X ]You can insert a maximum of 100 coins. Insert coins again:" << endl;
	return cash;
}
/*===== [�����: ����� ���� �� �����] =====*/
void Automata::printMenu()
{
	cout << "Choose an item from the menu-list below:" << endl;
	string tab = "\t\t| ";
	for (int i = 0; i < MAX_AMOUNT; i++)
	{
		if (i == 1 || i == 3) tab = "\t| ";
		else if (i == 4) tab = "| ";
		else tab = "\t\t| ";
		cout << '[' << i + 1 << ']' << menu[i] << tab << prices[i] << " coins" << endl;
	}
	cout << endl;
}
/*===== [�����: ������� ������� ��������� �� �����] =====*/
string Automata::printState()
{
	string curr_state;
	switch (state)
	{
		case(OFF)	: { curr_state = "OFF"; break; }
		case(WAIT)	: { curr_state = "...Waiting for the coins..."; break; }
		case(ACCEPT): { curr_state = "...Inserting money..."; break; }
		case(CHECK)	: { curr_state = "...Checking for the cash..."; break; }
		case(COOK)	: { curr_state = "...Cooking..."; break; }
	}
	return curr_state;
}
/*===== [�����: ����� �������] =====*/
string Automata::choice(int menu_id)
{
	if (menu_id >= 1 && menu_id <= MAX_AMOUNT)
	{
		choosen_drink = (menu_id - 1);
		cout << "[ Y ]You choosed: " << menu[choosen_drink] << endl;
		state = CHECK;
		cout << endl << printState() << endl << endl;
		checked_status = check(choosen_drink);
		return menu[choosen_drink];
	}
	else
	{
		cout << "[ X ]Your chosen item was not found!" << endl;
		cout << "Select an item from the menu-list below or cancel:" << endl;
		printMenu();
	}
}
/*===== [�����: �������� ����������� �����] =====*/
int Automata::check(int menu_id)
{
	if (state == CHECK)
	{
		if (cash < prices[menu_id])
		{
			cout << "[ X ]You've inserted not enough money for the " << menu[menu_id] << " to be chosen!" << endl;
			cout << "Insert the missing money in amount of " << (prices[menu_id] - cash) << " coins or cancel the operation!" << endl;
			return 0; //������������ �����
		}
		cout << "Checked! Preparing to cook..." << endl;
		cout << "[ * ]You still can cancel the operation. The machine will return your cash back." << endl;
		return 1; //��� ������
	}
	return -1;//������ �������� ���������
}
/*===== [�����: ������ ��������] =====*/
int Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		cout << "[ X ]You canceled the operation." << endl;
		cout << "Take your " << cash << " coins back!" << endl;
		cash = 0; //���������� ����������� ������
		state = WAIT; //��������� � ��������� ��������
		cout << endl << printState() << endl << endl;
		return cash;
	}
	return -1;//����� ������
}
/*===== [�����: ������������� �������] =====*/
int Automata::cook()
{
	if (state == CHECK && checked_status == 1)
	{
		state = COOK;
		cout << endl << printState() << endl << endl;
		for (int i = 0; i < 2000000000; i++);
		return finish();
	}
	else cout << "[ X ]The machine has not checked inserted cash yet!" << endl;
	return 0;
}
/*===== [�����: ���������� ������������] =====*/
int Automata::finish()
{
	if (state == COOK)
	{
		state = WAIT;
		cout << "[ Y ]Your " << menu[choosen_drink] << " drink is ready!" << endl;
		int change = (cash - prices[choosen_drink]);
		cash = 0;
		if (change > 0)
		{
			cout << "[ $ ]And here is your change: " << change << " coins" << endl;
			return change;
		}
		change = 0;
	}
	else cout << "[ X ]Nothing to finish!" << endl;
	return 0;
}