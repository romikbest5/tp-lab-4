#include "gtest/gtest.h"
#include "../include/Automata.h"

TEST(lab4, task1_1)
{
	//Автомат включился и вернул true
	Automata machine;
	
	bool expected = true;
	bool result = machine.on();
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_2)
{
	//Автомат выключен и текущее состояние OFF
	Automata machine;
	machine.on();
	machine.off();

	string expected = "OFF";
	string result = machine.printState();
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_3)
{
	//Автомат вернул значение: сколько монет было вставлено
	Automata machine;
	machine.on();

	int expected = 40;
	int result = machine.coin(40);
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_4)
{
	//При вставке монет текущее состояние монет "...Inserting money..."
	Automata machine;
	machine.on();
	machine.coin(50);

	string expected = "...Inserting money...";
	string result = machine.printState();
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_5)
{
	//Inserting money
	Automata machine;
	machine.on();
	machine.coin(10);

	string expected = "Americano";
	string result = machine.choice(3);
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_6)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	
	int expected = -1;
	int result = machine.check(2);
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_7)
{
	Automata machine;
	machine.on();
	machine.coin(10);
	machine.choice(3);

	int expected = 0;
	int result = machine.check(2);
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_8)
{
	Automata machine;
	machine.on();
	machine.coin(40);
	machine.choice(3);

	int expected = 1;
	int result = machine.check(2);
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_9)
{
	Automata machine;
	machine.on();
	machine.coin(30);
	machine.choice(3);
	machine.coin(20);
	machine.choice(3);

	int expected = 10;
	int result = machine.cook();
	EXPECT_EQ(expected, result);
}

TEST(lab4, task1_10)
{
	Automata machine;
	machine.on();
	machine.coin(40);
	machine.choice(3);

	int expected = 0;
	int result = machine.cook();
	EXPECT_EQ(expected, result);
}