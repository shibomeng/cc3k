#include "orc.h"
#include <iostream>
#include <cstdlib>

orc::orc(): enemy(180, 30, 25){}

int orc::attack(character &object) {
    int isattack = rand() % 2;
    if (isattack == 0) {
        return 0;
    }
    int damage = 0;
    Info defended = object.get_info();
    float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
    damage = ceiling(damage_float);
    if (object.myType() == characterType::goblin) {
        damage *= 1.5;
    }
    object.defend(damage);
    return damage;
}

int orc::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info orc::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

orc::~orc() {
    
}

void orc::print(){
    std::cout<<'O';
}

characterType orc::myType(){
    return characterType::orc;
}

int orc::gold_drop() {
    gold = rand() % 2 + 1;
    return gold;
}

std::string orc::name(){
    return "O";
}

