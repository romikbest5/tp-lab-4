#include "gtest/gtest.h"
#include "Automato.h"


TEST(lab4,test)
{
    Automato Coffe;
    EXPECT_EQ("off",Coffe.getState());
    
    Coffe.on();
    EXPECT_EQ("wait",Coffe.getState());
    
    /*menu
    1)Nescafe - 25p
    2)Neste - 31p
    3)Nuri - 18p
    */
        
    Coffe.coin(10);
    EXPECT_EQ("accept",Coffe.getState());
    
    Coffe.coin(10);
    EXPECT_EQ("accept",Coffe.getState());
    EXPECT_EQ(20,Coffe.getCash());
    
    Coffe.choice(2);
    //not enought cash
    EXPECT_EQ("accept",Coffe.getState());
    
    Coffe.choice(3);
    EXPECT_EQ("wait",Coffe.getState());
    //change 2p
    EXPECT_EQ(0,Coffe.getCash());
}
