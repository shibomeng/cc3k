#include "dwarf.h"
#include <iostream>
#include <cstdlib>

using namespace std;

dwarf::dwarf(): enemy(100,20,30){}

int dwarf::attack(character &object) {
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

int dwarf::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info dwarf::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

dwarf::~dwarf() {
    
}

void dwarf::print(){
    cout<<'W';
}

characterType dwarf::myType(){
    return characterType::dwarf;
}

int dwarf::gold_drop() {
    gold = rand() % 2 + 1;
    return gold;
}

std::string dwarf::name(){
    return "W";
}
