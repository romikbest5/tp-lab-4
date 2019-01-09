#include "gtest/gtest.h"
#include "../include/Automata.h"

// test0
TEST(Test,test0)
{
    EXPECT_EQ("", "");
}
// Automata on off
TEST(Automata_on_off,test1)
{
    Automata machine;
    machine.on();
    EXPECT_EQ(WAIT, machine.printState());
}

TEST(Automata_on_off,test2)
{
    Automata machine;
    machine.on();
    machine.printMenu();
    machine.off();
    EXPECT_EQ(OFF, machine.printState());
}

//Automata coin() check()

TEST(Automata_coin_check,test3)
{
    double a = 99.99, b = 46.01;
    Automata machine;
    machine.on();
    machine.coin(a);
    machine.coin(b);
    EXPECT_EQ(machine.getCash(), a+b);
    ASSERT_EQ(machine.printState(),ACCEPT);
    machine.choice(0);
    ASSERT_EQ(machine.printState(),CHECK);
    EXPECT_EQ(machine.check(), true);
    machine.cancel();
    ASSERT_EQ(machine.printState(), WAIT);
    machine.off();
    ASSERT_EQ(machine.printState(), OFF);
}

TEST(Automata_coin_check,test4)
{
    double a = 1, b = 39;
    Automata machine;
    machine.on();
    machine.coin(a);
    machine.choice(0);
    EXPECT_EQ(machine.check(), false);
    machine.coin(b);
    EXPECT_EQ(machine.check(), true);
}

//Automata cook() finish()

TEST(Automata_cook_finish,test5)
{
    double a = 1, b = 10, c = 100;
    Automata machine;
    machine.on();
    machine.coin(a);
    machine.choice(1);
    machine.cancel();
    ASSERT_EQ(machine.printState(), WAIT);
    EXPECT_EQ(machine.getCash(), 0);

    machine.coin(a);
    machine.coin(c);
    machine.choice(0);
    machine.cook();
    machine.finish();
    ASSERT_EQ(machine.printState(), WAIT);
    EXPECT_EQ(machine.getCash(), 0);
}
=======
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

// task1
TEST(lab1,task1_1)
{
    unsigned long res=findValue(1,20);
    EXPECT_EQ(232792560,res);
}
TEST(lab1,task1_2)
{
    unsigned long res=findValue(1,10);
    EXPECT_EQ(2520,res);
}

// task2
TEST(lab1,task2_1)
{
   EXPECT_EQ(true,checkPrime(2));
}
TEST(lab1,task2_2)
{
   EXPECT_EQ(true,checkPrime(3));
}
TEST(lab1,task2_3)
{
   EXPECT_EQ(false,checkPrime(12));
}
TEST(lab1,task2_4)
{
   unsigned long long res=nPrime(6);
   EXPECT_EQ(13,res);
}
TEST(lab1,task2_5)
{
   unsigned long long res=nPrime(500);
   EXPECT_EQ(3571,res);
}
TEST(lab1,task2_6)
{
   unsigned long long res=nextPrime(1031);
   EXPECT_EQ(1033,res);
}
TEST(lab1,task2_7)
{
   unsigned long long res=nextPrime(3559);
   EXPECT_EQ(3571,res);
}
TEST(lab1,task2_8)
{
   unsigned long long res=nextPrime(2);
   EXPECT_EQ(3,res);
}

// task3
TEST(lab1,task3_1)
{
   unsigned long long res=sumPrime(2000000);
   unsigned long long expected=142913828922;
   EXPECT_EQ(expected,res);
}
TEST(lab1,task3_2)
{
   unsigned long long res=sumPrime(10);
   unsigned long long expected=17;
   EXPECT_EQ(expected,res);
}

// task4
TEST(lab1,task4_1)
{
   char *x="123456789";
   char *y="000000001";
   char *expected="123456790";
   char *z=sum(x,y);
   EXPECT_STREQ(expected,z);
}
TEST(lab1,task4_2)
{
   char *x="99999999999999999999";
   char *y="1";
   char *expected="100000000000000000000";
   char *z=sum(x,y);
   EXPECT_STREQ(expected,z);
}

//task5
TEST(lab1,task5)
{
   char *buf="123,456,789";
   int N=0;
   char **result=nullptr;
   split(&result, &N, buf, ',');
   
   EXPECT_EQ(3,N);
   EXPECT_NE(nullptr,result);
   EXPECT_STREQ("123",result[0]);
   EXPECT_STREQ("456",result[1]);
   EXPECT_STREQ("789",result[2]);
}
>>>>>>> 1595a2007b6787a98ac8eb64bdfdfe02df168fb7
