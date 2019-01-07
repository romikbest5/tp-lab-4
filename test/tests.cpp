#include "gtest/gtest.h"
#include "Automata.h"

const char menu[6][20] = { "ESPRESSO","DUO ESPRESSO","AMERICANO","LATTE","CAPPUCCINO", "HOT CHOCOLATE" }; 
double price[6] = { 90.0,120.0,150.0,210.0,210.0,180.0 };
const char cur_state[5][7] = { "off","wait","accept","check","cook" };
// task1
TEST(lab4,task1_1)
{
	Automata vender;
    unsigned int state_off=0;
    EXPECT_EQ(state_off,vender.printState);
}
TEST(lab4,task1_2)
{
	Automata vender;
	vender.on();
    unsigned int state_wait=1;
    EXPECT_EQ(state_wait,vender.printState);
}

// task2
TEST(lab4,task2_1)
{
	double change=199.5;
	Automata vender;
	vender.on();
	vender.coin(change);
	EXPECT_DOUBLE_EQ(change,vender.cancel());
}
TEST(lab4,task2_2)
{
    Automata vender;
    unsigned int state_off=0;
	vender.coin(199.5);
    EXPECT_EQ(state_off,vender.printState);
}
TEST(lab1,task2_3)
{
    double cash=100;
	Automata vender;
	vender.on();
	vender.coin(cash);
	EXPECT_DOUBLE_EQ(cash,vender.cancel());
}
TEST(lab1,task2_4)
{
    double cash=100;
	Automata vender;
	vender.on();
	vender.coin(cash);
	vender.choice(0);
	double change=cash-price[0];
	EXPECT_DOUBLE_EQ(change,vender.finish());
}
