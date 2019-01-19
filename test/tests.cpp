#include "gtest/gtest.h"\
#include "Automata.h"
#include <string>

Automata a;

TEST(Lab4, test1) {
	string str = a.on();
  EXPECT_EQ(str, "ON");
}


TEST(Lab4, test2) {
	a.on();
	string str = a.off();
	EXPECT_EQ(str, "OFF");
}

TEST(Lab4, test3) {
	a.on();
	a.coin(20);
	a.coin(4);
	a.coin(3);
	int k = a.getCash();
	EXPECT_EQ(k, 27);
}

TEST(Lab4, test4) {
	a.on();
	a.coin(20);
	a.coin(4);
	a.coin(3);
	a.cancel();
	int k = a.getCash();
	EXPECT_EQ(k, 0);
}

TEST(Lab4, test5_change) {
	a.coin(50);
	a.choice(3);
	int k = a.getCash();
	EXPECT_EQ(k, 20);
}

TEST(Lab4, test6) {
	a.coin(23);
	a.choice(3);
	int k = a.getCash();
	EXPECT_EQ(k, 23);
}

TEST(Lab4, test7) {
	a.coin(23);
	a.choice(3);
	a.coin(10);
	int k = a.getCash();
	EXPECT_EQ(k, 3);
}
