#include "gtest/gtest.h"
#include "Automata.h"
#include <string>

TEST(lab4,coin)
{
    Automata machine;
	machine.on();
	
	EXPECT_EQ(15, machine.coin(15));
	EXPECT_EQ(30, machine.coin(15));
	
}

TEST(lab4,choice)
{
    Automata machine;
	machine.on();
	EXPECT_EQ("This position is not found", machine.choice(9));
	machine.coin(10);
	EXPECT_EQ("The balance is 0... Deposit the money.", machine.choise(6));
	machine.coin(10);
	EXPECT_EQ(6, machine.choise(6));
}

TEST(lab4,check_1)
{
    Automata machine;
	machine.on();
	machine.coin(25);
	bool expected = true;
	bool result = machine.check(5);
	EXPECT_EQ(expected, result);
}
TEST(lab4,check_2)
{
    Automata machine;
	machine.on();
	machine.coin(20);
	bool expected = false;
	bool result = machine.check(5);
	EXPECT_EQ(expected, result);
}
TEST(lab4,choice)
{
    Automata machine;
	machine.on();
	machine.coin(10);
	machine.coin(14);
	EXPECT_EQ(24, machine.cancel());
}


