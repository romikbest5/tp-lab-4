#include "gtest/gtest.h"
#include "automata.h"

//turning on
TEST(lab4,automata_on){
	Automata nes;
	EXPECT_EQ(STATES::WAIT,nes.on());
}
//switch to cooking after turning on
TEST(lab4,automata_cook){
	Automata nes;
	nes.on();
	EXPECT_EQ(STATES::WAIT,nes.cook());
}
//lack of money
TEST(lab4,automata_check){
	Automata nes;
	nes.on();
	nes.coin(2);
	nes.choise(1);
	EXPECT_FALSE(nes.check());
}
//change after finish
TEST(lab4,automata_give_change1){
	Automata nes;
	nes.on();
	nes.coin(50);
	nes.choise(1);
	nes.check();
	nes.cook();
	nes.finish();
	EXPECT_EQ(5,nes.giveChange());
}
//change after turning on
TEST(lab4,automata_give_change2){
	Automata nes;
	nes.on();
	EXPECT_EQ(0,nes.giveChange());
}
//change after cancel
TEST(lab4,automata_give_change3){
	Automata nes;
	nes.on();
	nes.coin(50);
	nes.choise(1);
	nes.check();
	nes.cancel();
	EXPECT_EQ(50,nes.giveChange());
}
//status after lack of money
TEST(lab4,automata_cancel1){
	Automata nes;
	nes.on();
	nes.coin(2);
	nes.choise(1);
	EXPECT_EQ(STATES::WAIT,nes.check());
}
//switch to cancel after cooking
TEST(lab4,automata_cancel2){
	Automata nes;
	nes.on();
	nes.coin(2);
	nes.choise(1);
	nes.check();
	nes.cook();
	EXPECT_EQ(STATES::COOK,cancel());
}
//switch to cooking after turning on 2
//TEST(lab4,automata_cook){
//	Automata nes;
//	nes.on();
//	EXPECT_EQ(STATES::WAIT,nes.cook());
//}
//turning off after inserting money
TEST(lab4,automata_off){
	Automata nes;
	nes.on();
	nes.coin(50);
	EXPECT_EQ(STATES::ACCEPT,nes.off());
}


	
