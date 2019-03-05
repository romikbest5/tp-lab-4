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
TEST(lab4,choice_1)
{
    Automata machine;
	machine.on();
	machine.coin(10);
	machine.coin(14);
	EXPECT_EQ(24, machine.cancel());
}


