#include "gtest/gtest.h"
#include "Automata.h"
#include <string>

using namespace std;
// task1
// ordinary work
TEST(lab4,test1)
{
   Automata m;
   STATES state = m.on();
   EXPECT_EQ(WAIT,state);
   state = m.coin(15);
   EXPECT_EQ(15, m.getCash());
   EXPECT_EQ(ACCEPT, state);
   EXPECT_EQ(CHECK, m.choice(1));
   EXPECT_EQ(COOK, m.cook());
   string ans = "Get your drink";
   EXPECT_EQ(ans, m.finish());
   EXPECT_EQ(OFF, m.off());

}
// Turn off not working machine
TEST(lab1,test2)
{
   Automata m;
   EXPECT_EQ(ERROR, m.off());
}

//not enough money
TEST(lab4,test4)
{
Automata m;
m.on();
m.coin(10);
m.choice(2);
EXPECT_EQ(false, m.check());
m.off();
}

//wrong number of drinks
TEST(lab4,test5)
{
Automata m;
m.on();
m.coin(50);
EXPECT_EQ(ERROR,m.choice(16));
m.off();
}
// Count cash after finish
TEST(lab4,test6)
{
Automata m;
m.on();
m.coin(12);
int c = m.getCash();
EXPECT_EQ(12,c);
m.choice(2);
EXPECT_EQ(true,m.check());
EXPECT_EQ(COOK, m.cook());
EXPECT_EQ("Get your drink", m.finish());
EXPECT_EQ(0, m.getCash());
}

// Try to cook without checking
TEST(lab4, test7)
{
   Automata m;
   m.on();
   m.coin(15);
   m.choice(1);
   EXPECT_EQ(ERROR, m.cook());
   EXPECT_EQ(WAIT, m.restart());
   EXPECT_EQ(15, m.returnMoney());
}