#include "gtest/gtest.h"
#include "automata.h"

//turning on
TEST(automata,automata_on1){
	Automata nes;
	EXPECT_EQ(1,nes.on);
}
TEST(automata,automata_print_states1){
	Automata nes;
	nes.on();
	EXPECT_EQ("WAIT",printStates());
}
//switch to cooking after turning on
TEST(automata,automata_print_states2){
	Automata nes;
	nes.on();
	nes.cook();
	EXPECT_EQ("WAIT",printStates());
}
//lack of money
TEST(automata,automata_check){
	Automata nes;
	nes.on;
	nes.coin(2);
	nes.choise(1);
	EXPECT_FALSE(nes.check());
}
//change after finish
TEST(automata,automata_give_change1){
	Automata nes;
	nes.on;
	nes.coin(50);
	nes.choise(1);
	nes.check();
	nes.cook();
	nes.finish();
	EXPECT_EQ(5,nes.giveChange());
}
//change after turning on
TEST(automata,automata_give_change2){
	Automata nes;
	nes.on;
	EXPECT_EQ(0,nes.giveChange());
}
//change after cancel
TEST(automata,automata_give_change3){
	Automata nes;
	nes.on;
	nes.coin(50);
	nes.choise(1);
	nes.check();
	nes.cancel();
	EXPECT_EQ(50,nes.giveChange());
}
//status after lack of money
TEST(automata,automata_cancel1){
	Automata nes;
	nes.on;
	nes.coin(2);
	nes.choise(1);
	nes.check();
	EXPECT_EQ("WAIT",printStates());
}
//switch to cancel after cooking
TEST(automata,automata_cancel2){
	Automata nes;
	nes.on;
	nes.coin(2);
	nes.choise(1);
	nes.check();
	nes.cook()
	EXPECT_EQ("COOK",cancel());
}
//switch to cooking after turning on 2
TEST(automata,automata_cook){
	Automata nes;
	nes.on;
	EXPECT_EQ(1,nes.cook());
}
//turning off after inserting money
TEST(automata,automata_off){
	Automata nes;
	nes.on;
	nes.coin(50);
	EXPECT_EQ(2,nes.off());
}


	