#include "gtest/gtest.h"
#include "../include/Automata.h"
  TEST(lab4, task_1) 
{
	Automata a;
	a.on();
	 int c = a.getCash();
	EXPECT_EQ(0, c);
}

TEST(lab4, task_2) 
{
	Automata a;
	a.on();
	a.coin(50);
	 int c = a.getCash();
	EXPECT_EQ(50, c);
}

TEST(lab4, task_3) 
{
	Automata a;
	a.on();
	a.coin(20);
	automata.choice(2);

	 int c = a.getCash();
	EXPECT_EQ(0, c);
}

TEST(lab4, task_4) 
{
	Automata a;
	a.on();
	a.coin(75);
	a.choice(2);
	a.choice(2);

	 int c = a.getCash();
	EXPECT_EQ(35, c);
}

