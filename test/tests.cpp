#include "gtest/gtest.h"
#include "automata.h"
#include <string>

using namespace std;


TEST(lab4,scene1)
{
    Automata nc;
    string h = nc.on();
    EXPECT_EQ("THE MACHINE HAS TURNED ON",h);

    nc.coin(10);
    int c = nc.getcash();
    EXPECT_EQ(10,c);

    nc.coin(30);
    EXPECT_EQ(ACCEPT, nc.getstate());

    string ans = nc.choice(2);
    EXPECT_EQ("ENJOY YOUR DRINK",ans);
}



