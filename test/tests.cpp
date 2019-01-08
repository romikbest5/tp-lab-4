#include "gtest/gtest.h"
#include "Automata.cpp"

TEST(lab4, test1)
{
    Automata * automata = new Automata();
    automata -> choice();
    EXPECT_EQ(automata -> getSatate(), OFF);
}

TEST(lab4, test2)
{
    Automata * automata = new Automata();
    automata -> on();
    EXPECT_EQ(automata -> getSatate(), WAIT);
}
