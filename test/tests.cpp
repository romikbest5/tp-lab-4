#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, task1_1)
{
	Automata automata1;
	automata1.on();
	AState state = automata1.getState();
	AState cond = aWait;
	EXPECT_EQ(cond, state);
}
TEST(lab4, task_2) {
	Automata automata1;
	automata1.on();
	automata1.printState();
	automata1.coin(100);
	automata1.choice(3);
	EXPECT_EQ(90, coins);
}
TEST(lab4, task_3) {
	Automata automata;
	automata.on();

	EXPECT_EQ(0, coins);
}
TEST(lab4, task_4) {
	Automata automata;
	automata.on();
	automata.coin(1);
	automata.choice(2);
	EXPECT_EQ(1, coins);
}
