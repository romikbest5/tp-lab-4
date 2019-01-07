#include "gtest/gtest.h"
#include "Automata.h"
#include <string>


TEST(automata, function_on){
	Automata aut;
	string expect = "Hello!";
	EXPECT_EQ(expect, aut.on());
}

TEST(automata, function_off) {
	Automata aut;
	EXPECT_EQ("0", aut.off());
	aut.on();
	EXPECT_EQ("Goodbye!", aut.off());
	aut.on();
	aut.coin(50);
	EXPECT_EQ("You cannot turn off the automata right now", aut.off());
}

TEST(automata, function_coin) {
	Automata aut;
	aut.on();
	EXPECT_EQ(10, aut.coin(10));
	EXPECT_EQ(20, aut.coin(10));
}

TEST(automata, function_printState) {
	Automata aut;
	EXPECT_EQ("0", aut.printState());
	aut.on();
	EXPECT_EQ("WAIT", aut.printState());
	aut.coin(90);
	EXPECT_EQ("ACCEPT", aut.printState());
	aut.choice(4);
	EXPECT_EQ("CHECK", aut.printState());
	aut.choice(2);
	EXPECT_EQ("CHECK", aut.printState());	
}

TEST(automata, function_choice) {
	Automata aut;
	EXPECT_EQ("0", aut.choice(4));
	aut.on();
	aut.coin(10);
	EXPECT_EQ("Give more money or make another choice", aut.choice(4));
	aut.coin(80);
	EXPECT_EQ("Ok", aut.choice(3));
}

TEST(automata, function_change) {
	Automata aut;
	EXPECT_EQ(0, aut.change());
	aut.on();
	aut.coin(90);
	EXPECT_EQ(90, aut.change());
	aut.coin(90);
	aut.choice(1);
	EXPECT_EQ(20, aut.change());
}