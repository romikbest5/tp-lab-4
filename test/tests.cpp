#include "gtest/gtest.h"
#include "Automata.h"
#include <string>


//task1 ON/OFF
TEST(lab4,task1_1)
{
	Automata cof;
	string exp = "Automata is ON";
	EXPECT_EQ(exp, cof.on());
}

TEST(lab4,task1_2)
{
	Automata cof;
	string exp = "Automata is OFF";
	cof.on();
	EXPECT_EQ(exp, cof.off());
}

TEST(lab4,task1_3)
{
	Automata cof;
	string exp = "ERROR";
	cof.on();
	EXPECT_EQ(exp, cof.on());
}
//task2 coin/cancel
TEST(lab4,task2_1)
{
	Automata cof;
	cof.on();
	cof.coin(30);
	cof.coin(40);
	cof.coin(5);
	EXPECT_EQ("ERROR", cof.off());
}
TEST(lab4,task2_2)
{
	Automata cof;
	int exp = 75;
	cof.coin(30);
	cof.coin(40);
	cof.coin(5);
	aut.cancel(); 
	EXPECT_EQ(exp, cof.cancel());
}
//task2 choice/change/cook/finish
TEST(lab4,task3_1)
{
	Automata cof;
	cof.on();
	cof.coin(30);
	cof.coin(40);
	EXPECT_EQ("Espresso", cof.choice(3));
	EXPECT_EQ(50, cof.finish());
}


