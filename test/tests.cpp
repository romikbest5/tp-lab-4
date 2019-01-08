#include "gtest/gtest.h"
#include "Automata.cpp"

TEST(lab4, test1)
{
    Automata * automata = new Automata();
    automata -> choice(1);
    int i = (automata -> getState() == OFF);
    EXPECT_EQ(1, i);
}

TEST(lab4, test2)
{
    Automata * automata = new Automata();
    automata -> on();
    int i = (automata -> getState() == WAIT);
    EXPECT_EQ(1, i);
}

TEST(lab4, test3)
{
    Automata * automata = new Automata();
    automata -> on();
    automata -> coin(100);
    automata -> choice(5);
    automata -> cook();
    int i = (automata -> getProfit() != 0);
    EXPECT_EQ(1, i);
}

TEST(lab4, test4)
{
    Automata * automata = new Automata();
    automata -> on();
    automata -> coin(100);
    automata -> choice(5);
    automata -> cancel();
    int i = (automata -> getProfit() == 0);
    EXPECT_EQ(1, i);
}

TEST(lab4, test5)
{
    Automata * automata = new Automata();
    automata -> on();
    automata -> coin(100);
    automata -> choice(5);
    automata -> cancel();
    automata -> off();
    int i = (automata -> getState() == OFF);
    EXPECT_EQ(1, i);
}
