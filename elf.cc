#include "elf.h"
#include <cstdlib>
#include <iostream>

elf::elf(): enemy(140,30,10){}

int elf::attack(character &object) {
    int damage = 0;
    // srand((unsigned) time(NULL));
    int atknum;
    if(object.myType()==characterType::drow){
        atknum=1;
    }else{
        atknum=2;
    }
    for (int i = 0; i < atknum; i++) {// Elf's skill
        int isattack = rand() % 2;
        if (isattack == 0) {
            return damage;
        }
        Info defended = object.get_info();
        float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
        damage += ceiling(damage_float);
        object.defend(damage);
    }
    return damage;
}

int elf::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info elf::get_info() {
    Info tmp{hp, atk, def};
    return tmp;
}

elf::~elf() {
    
}

void elf::print(){
    std::cout<<'E';
}

characterType elf::myType(){
    return characterType::elf;
}

int elf::gold_drop() {
    gold = rand() % 2 + 1;
    return gold;
}

std::string elf::name(){
    return "E";
}
