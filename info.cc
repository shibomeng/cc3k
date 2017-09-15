//
//  info.cpp
//  cc3k
//
//  Created by Li Jing on 2017-07-15.
//  Copyright © 2017 Li Jing. All rights reserved.
//

#include "info.h"
#include "iostream"

Info::Info(int hp, int atk, int def): hp{hp}, atk{atk}, def{def} {}

int Info::get_hp(){
    return hp;
}

int Info::get_atk(){
    return atk;
}

int Info::get_def(){
    return def;
}

Info::~Info() {
    
}

void Info::print(){
    std::cout<<"hp: "<<hp<<std::endl;
    std::cout<<"atk: "<<atk<<std::endl;
    std::cout<<"def: "<<def<<std::endl;
}
