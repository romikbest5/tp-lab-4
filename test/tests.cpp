#include "gtest/gtest.h"
#include "Automata.h"

Automata nescaffe;
STATES p;
	
// task1
TEST(Lab4, test1) 
{
	nescaffe.on();
	p = nescaffe.printState();
	//1 - WAIT
    EXPECT_EQ(1,p);
}
TEST(Lab4, test2) 
{
	nescaffe.on();
	nescaffe.coin(10);
	nescaffe.choice(2);
	p = nescaffe.printState();
	//2 - ACCEPT
	EXPECT_EQ(2,p);
}
TEST(Lab4, test3) 
{
	nescaffe.on();
	nescaffe.coin(10);
	nescaffe.choice(2);
	nescaffe.coin(50);
    EXPECT_EQ(30, nescaffe.getChange());
}
TEST(Lab4, test4) 
{
	nescaffe.on();
    nescaffe.coin(20);
	nescaffe.choice(1);
	nescaffe.cancel();
	p=nescaffe.printState();
    EXPECT_EQ(1,p);
}
TEST(Lab4, test5) 
{
	nescaffe.on();
    nescaffe.coin(35);
	nescaffe.choice(7);
	nescaffe.choice(4);
	p=nescaffe.printState();
    EXPECT_EQ(1,p);
}
TEST(Lab4, test6) 
{
	nescaffe.on();
	nescaffe.off();
	p=nescaffe.printState();
	//0 - OFF
    EXPECT_EQ(0,p);
}

