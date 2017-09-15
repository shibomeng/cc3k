
#include "dragon.h"
#include <iostream>
#include <cstdlib>

dragon::dragon(std::shared_ptr<item>treasure): enemy(250,20,20),treasure{treasure}{}

int dragon::attack(character &object) {
    // srand((unsigned) time(NULL));
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

int dragon::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info dragon::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

dragon::~dragon() {
    
}

characterType dragon::myType(){
    return characterType::dragon;
}

void dragon::print(){
    std::cout<<'D';
}

int dragon::gold_drop(){
    gold=0;
    return gold;
}

bool dragon::isdead() {
    if (hp == 0) {
        treasure->getcanUse()=true;
        return true;
    } return false;
}

std::string dragon::name(){
    return "D";
}
