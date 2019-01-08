#include "gtest/gtest.h"
#include "Automata.cpp"

TEST(lab4, test1)
{
    Automata * automata = new Automata();
    automata -> choice(1);
    int i = (automata -> getSatate() == OFF);
    EXPECT_EQ(1, i);
}

TEST(lab4, test2)
{
    Automata * automata = new Automata();
    automata -> on();
    int i = (automata -> getSatate() == WAIT);
    EXPECT_EQ(1, i);
}
