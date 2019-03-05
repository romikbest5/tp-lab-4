#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, test1){
  Automata vendor;
  STATES offstate=OFF;
  EXPECT_EQ(offstate, vendor.printState());
  EXPECT_EQ(0, vendor.coin(0));
}

TEST(lab4,test2) {
  Automata vendor;
  STATES turn_on_state = WAIT;
  vendor.on();
  EXPECT_EQ(turn_on_state, vendor.printState());
}

TEST(lab4, test3){
  Automata vendor;
  STATES offstate=OFF;
  vendor.on();
  vendor.off();
  EXPECT_EQ(offstate, vendor.printState());
}

TEST(lab4, test4){
  Automata vendor;
  vendor.on();
  unsigned int money = 50;
  vendor.coin(money);
  EXPECT_EQ(money, vendor.cancel());
}

TEST(lab4, test5) {
  Automata vendor;
  vendor.on();
  unsigned int money=50;
  vendor.coin(money);
  EXPECT_EQ(money, vendor.finish());
}

TEST(lab4, test6) {
  Automata.vendor;
  vendor.on();
  unsigned int money=120;
  vendor.coin(20);
  EXPECT_EQ(money, vendor.coin(100));
}
