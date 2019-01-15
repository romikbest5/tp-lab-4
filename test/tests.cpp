/*#include "gtest/gtest.h"
#include "Header.h"

TEST(lab4, task_1) 
{
	Automata automata;
	automata.on();
	unsigned int cash = automata.getCash();
	EXPECT_EQ(0, cash);
}

TEST(lab4, task_2) 
{
	Automata automata;
	automata.on();
	automata.coin(50);
	automata.choice(3);
	automata.choice(3);

	unsigned int cash = automata.getCash();
	EXPECT_EQ(0, cash);
}

TEST(lab4, task_3) 
{
	Automata automata;
	automata.on();
	automata.coin(25);
	automata.choice(1);

	unsigned int cash = automata.getCash();
	EXPECT_EQ(25, cash);
}

TEST(lab4, task_4) 
{
	Automata automata;
	automata.on();
	automata.coin(100);
	automata.choice(3);
	automata.choice(2);
	automata.choice(2);

	unsigned int cash = automata.getCash();
	EXPECT_EQ(35, cash);
}*/