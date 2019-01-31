#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4,task1)
{
	Automata drink;
	EXPECT_EQ(STATES::OFF,drink.getState());
}

TEST(lab4,task2)
{
	Automata drink;
	drink.on();
	EXPECT_EQ(STATES::WAIT,drink.getState());
}

TEST(lab4,task3)
{
	Automata drink;
	drink.on();
	drink.coin(-1);
	EXPECT_EQ(STATES::WAIT,drink.getState());
}

TEST(lab4,task4)
{
	Automata drink;
	drink.on();
	drink.coin(1);
	EXPECT_EQ(STATES::ACCEPT,drink.getState());
}

TEST(lab4,task5)
{
	Automata drink;
	drink.on();
	drink.coin(1);
	drink.choice(-1);
	EXPECT_EQ(STATES::ACCEPT,drink.getState());
}

TEST(lab4,task6)
{
	Automata drink;
	drink.on();
	drink.coin(1);
	drink.choice(0);
	EXPECT_EQ(STATES::CHECK,drink.getState());
}

TEST(lab4,task7)
{
    Automata drink;
	drink.on();
	drink.coin(40);
	drink.choice(1);
    EXPECT_EQ(true, drink.check(1));
}

TEST(lab4,task8)
{
	Automata drink;
	drink.on();
	drink.coin(29);
	drink.choice(3);
    EXPECT_EQ(false, drink.check(3));
}

TEST(lab4,task9)
{
	Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook();
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(3);
		}
	}
    EXPECT_EQ(true, drink.check(2));
}

TEST(lab4,task10)
{
		Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook();
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(3);
		}
	}
    EXPECT_EQ(STATES::COOK, drink.getState());
}

TEST(lab4,task11)
{
		Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook();
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(3);
		}
	}
	drink.finish();
    EXPECT_EQ(STATES::OFF, drink.getState());
}

TEST(lab4,task12)
{
		Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook();
	else {
		drink.contined(1);
		while (!drink.check(2)) {
			drink.coin(10);
		}
	}
	drink.finish();
    EXPECT_EQ(STATES::WAIT, drink.getState());
}

TEST(lab4,task13)
{
		Automata drink;
	drink.on();
	drink.coin(44);
	drink.choice(2);
	if (drink.check(2))
		drink.cook();
	else {
		drink.contined(0);
	}
	drink.finish();
    EXPECT_EQ(STATES::WAIT, drink.getState());
}