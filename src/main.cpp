//
// Created by Илья on 07.01.2019.
//

#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Automata.h"

int main(int argc, char* argv[]){
    //testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();
    double a = 1, b = 10, c = 100;
    Automata machine;
    machine.printState();   //OFF
    std::cout<<"[*click ON*]"<<std::endl;
    machine.on();           //WAIT
    machine.printMenu();
    machine.printState();
    std::cout<<"[*click + 1 coin*]"<<std::endl;
    machine.coin(a);
    machine.printState();               //ACCEPT
    std::cout<<"cash: "<<machine.getCash()<<std::endl;
    std::cout<<"[*click 2nd drink (milk)*] : "<<machine.choice(1) + 1<<std::endl;
    machine.printState();
    std::cout<<"check cash (false): "<<machine.check()<<std::endl;
    machine.cancel();
    std::cout<<"[*click cancel (and getSurplus)*]"<<std::endl;
    machine.printState();

    std::cout<<"cash: "<<machine.getCash()<<std::endl;
    std::cout<<"[*click + 100 coin*] :"<<machine.coin(c)<<std::endl;
        std::cout<<"cash: "<<machine.getCash()<<std::endl;

    std::cout<<"[*click 1st drink (cofee)*] :"<<machine.choice(0)+1<<std::endl;
    std::cout<<"check cash (true): "<<machine.check()<<std::endl;
    std::cout<<"[*click cook*]"<<std::endl;
    machine.cook();
    std::cout<<"[*finish and getSurplus*]"<<std::endl;
    std::cout<<machine.finish()<<std::endl;
    std::cout<<"cash: "<<machine.getCash()<<std::endl;

    return 0;
}