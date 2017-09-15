#include "player.h"
#include <iostream>

player::player(int hp, int atk, int def):character(hp,atk,def){}

player::~player(){}

void player::print(){
    std::cout<<"@";
}

void player::addGold(int value){
    if(value>0){
        gold+=value;
    }
}

void player::initialize_data(){
    atk=peratk;
    def=perdef;
}

int player::gold_drop(){return gold;}

bool player::isdead() {
    if (hp == 0) {
        return true;
    } return false;
}

std::string player::name(){
    return "@";
}
