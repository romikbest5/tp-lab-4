#include "gtest/gtest.h"
#include "automata.h"


TEST(lab4,scene1)
{
    Automata nc;
    nc.on();

    
    nc.coin(10);
    int c = nc.getcash();
    EXPECT_EQ(10,c);
}



