

#include "halfling.h"
#include <iostream>
#include <cstdlib>

halfling::halfling(): enemy(100,15,20){}

int halfling::attack(character &object) {
    int isattack = rand() % 2;
    if (isattack == 0) {
        return 0;
    }
    int damage = 0;
    Info defended = object.get_info();
    float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
    damage = ceiling(damage_float);
    object.defend(damage);
    return damage;
}

int halfling::defend(int &damage) {
    int isdefend = rand() % 2;
    if (isdefend == 1) {
        damage = 0;
        return 0;
    }
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info halfling::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

halfling::~halfling() {
    
}

characterType halfling::myType(){
    return characterType::halfling;
}

void halfling::print(){
    std::cout<<'L';
}

int halfling::gold_drop() {
    gold = rand() % 2 + 1;
    return gold;
}

std::string halfling::name(){
    return "L";
}
