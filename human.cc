#include "human.h"
#include <cstdlib>
#include <iostream>

using namespace std;

human::human(): enemy(140, 20, 20){}

int human::attack(character &object) {
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

int human::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info human::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

human::~human() {
    
}

void human::print(){
    cout<<'H';
}

characterType human::myType(){
    return characterType::human;
}

int human::gold_drop(){
    gold=4;
    return gold;
}

std::string human::name(){
    return "H";
}

