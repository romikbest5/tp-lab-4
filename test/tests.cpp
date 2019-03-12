#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4,task1)
{
	STATES res;
	Automata drink;
	res = drink.getState();
	EXPECT_EQ(STATES::OFF, res);
}

TEST(lab4,task2)
{
	STATES res;
	Automata drink;
	drink.on();
	res = drink.getState();
	EXPECT_EQ(STATES::WAIT, res);
}

TEST(lab4,task3)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(-1);
	res = drink.getState();
	EXPECT_EQ(STATES::WAIT, res);
}

TEST(lab4,task4)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(1);
	res = drink.getState();
	EXPECT_EQ(STATES::ACCEPT, res);
}

TEST(lab4,task5)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(1);
	drink.choice(-1);
	res = drink.getState();
	EXPECT_EQ(STATES::ACCEPT, res);
}

TEST(lab4,task6)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(1);
	drink.choice(0);
	res = drink.getState();
	EXPECT_EQ(STATES::CHECK, res);
}

TEST(lab4,task7)
{
	bool res;
    Automata drink;
	drink.on();
	drink.coin(40);
	drink.choice(1);
	res = drink.check(1);
	EXPECT_TRUE(res);
    //EXPECT_EQ(true, res);
}

TEST(lab4,task8)
{
	bool res;
	Automata drink;
	drink.on();
	drink.coin(29);
	drink.choice(3);
	res = drink.check(3);
	EXPECT_FALSE(res);
    //EXPECT_EQ(false, res);
}

TEST(lab4,task9)
{
	bool res;
	Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook(2);
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(3);
		}
	}
	res = drink.check(2);
	EXPECT_TRUE(res);
    //EXPECT_EQ(true, res);
}

TEST(lab4,task10)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook(2);
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(3);
		}
		drink.cook(2);
	}
	res = drink.getState();
    EXPECT_EQ(STATES::COOK, res);
}

TEST(lab4,task11)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook(2);
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(3);
		}
		drink.cook(2);
	}
	drink.finish();
	res = drink.getState();
    EXPECT_EQ(STATES::OFF, res);
}

TEST(lab4,task12)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook(2);
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(10);
		}
		drink.cook(2);
	}
	drink.finish();
	res = drink.getState();
    EXPECT_EQ(STATES::WAIT, res);
}

TEST(lab4,task13)
{
	STATES res;
	Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook(2);
	else {
		drink.contined(0);
	}
	drink.finish();
	res = drink.getState();
    EXPECT_EQ(STATES::WAIT, res);
}