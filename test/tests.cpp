#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, task_1) {
    Automata automata1;
    automata1.on();

    STATES state = automata1.getState();
    STATES cond = IDLE;
    EXPECT_EQ(cond, state);
}

TEST(lab4, task_2) {
    Automata automata1;
    automata1.on();
    automata1.printMenu();
    automata1.coin(50);
    automata1.choice(3);

    unsigned int cash = automata.getCash();
    EXPECT_EQ(15, cash);
}

TEST(lab4, task_3) {
    Automata automata;
    automata.on();

    unsigned int cash = automata.getCash();
    EXPECT_EQ(0, cash);
}

TEST(lab4, task_4) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.choice(4);

    unsigned int cash = automata.getCash(0);
    EXPECT_EQ(10, cash);
}
