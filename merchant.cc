#include "merchant.h"
#include <iostream>
#include <cstdlib>

merchant::merchant(): enemy(30,70,5){}

int merchant::attack(character &object) {
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

int merchant::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info merchant::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

merchant::~merchant() {
    
}

characterType merchant::myType(){
    return characterType::merchant;
}

void merchant::print(){
    std::cout<<'M';
}

int merchant::gold_drop() {
    gold=4;
    return gold;
}

std::string merchant::name(){
    return "M";
}
