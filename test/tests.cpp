#include "gtest/gtest.h"
#include "../include/Automata.h"

// test0
TEST(Test,test0)
{
    EXPECT_EQ("", "");
}
// Automata on off
TEST(Automata_on_off,test1)
{
    Automata machine;
    machine.on();
    EXPECT_EQ(WAIT, machine.printState());
}

TEST(Automata_on_off,test2)
{
    Automata machine;
    machine.on();
    machine.printMenu();
    machine.off();
    EXPECT_EQ(OFF, machine.printState());
}

//Automata coin() check()

TEST(Automata_coin_check,test3)
{
    double a = 99.99, b = 46.01;
    Automata machine;
    machine.on();
    machine.coin(a);
    machine.coin(b);
    EXPECT_EQ(machine.getCash(), a+b);
    ASSERT_EQ(machine.printState(),ACCEPT);
    machine.choice(0);
    ASSERT_EQ(machine.printState(),CHECK);
    EXPECT_EQ(machine.check(), true);
    machine.cancel();
    ASSERT_EQ(machine.printState(), WAIT);
    machine.off();
    ASSERT_EQ(machine.printState(), OFF);
}

TEST(Automata_coin_check,test4)
{
    double a = 1, b = 39;
    Automata machine;
    machine.on();
    machine.coin(a);
    machine.choice(0);
    EXPECT_EQ(machine.check(), false);
    machine.coin(b);
    EXPECT_EQ(machine.check(), true);
}

//Automata cook() finish()

TEST(Automata_cook_finish,test5)
{
    double a = 1, b = 10, c = 100;
    Automata machine;
    machine.on();
    machine.coin(a);
    machine.choice(1);
    machine.cancel();
    ASSERT_EQ(machine.printState(), WAIT);
    EXPECT_EQ(machine.getCash(), 0);

    machine.coin(a);
    machine.coin(c);
    machine.choice(0);
    machine.cook();
    machine.finish();
    ASSERT_EQ(machine.printState(), WAIT);
    EXPECT_EQ(machine.getCash(), 0);
}
