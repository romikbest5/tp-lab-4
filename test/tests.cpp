#include "gtest/gtest.h"
#include "Automata.h"

TEST(Automata_on,test1)
{
    Automata a;
    a.on();
    EXPECT_EQ(WAIT, a.printState());
}


TEST(Automata_off, test2)
{
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(OFF, a.printState());
}

TEST(Automata_coin, test3)
{
    Automata a;
    a.on();
    a.printMenu();
    a.coin(25);
    a.coin(50);
    EXPECT_EQ(75, a.printCash());
}

TEST(Automata_choice, test4)
{
    Automata a;
    a.on();
    a.printMenu();
    a.coin(35);
    a.choice(3);
    EXPECT_EQ(CHECK, a.printState());
}

TEST(Automata_choice, test5)
{
    Automata a;
    a.on();
    a.printMenu();
    a.coin(35);
    a.choice(5);
    EXPECT_EQ(Wrong_Operation, a.printState());
}

TEST(Automata_cook_and_finish,test5)
{
    Automata a;
    a.on();
    a.coin(30);
    a.choice(1);
    a.cancel();
    ASSERT_EQ(a.printState(), WAIT);
    EXPECT_EQ(a.getCash(), 0);

    a.coin(40);
    a.coin(10);
    a.choice(3);
    a.cook();
    EXPECT_EQ(COOK, a.printState());
    a.finish();
    ASSERT_EQ(a.printState(), WAIT);
    EXPECT_EQ(a.getCash(), 20);
}

