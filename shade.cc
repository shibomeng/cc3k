#include "shade.h"
#include <iostream>

using namespace std;

shade::shade(): player(125,25,25){}

int shade::attack(character &object) {
    int damage = 0;
    Info defended = object.get_info();
    float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
    damage = ceiling(damage_float);
    int doge=object.defend(damage);
    if(doge>0){
        return damage;
    }else{
        return -1*damage;
    }
}

int shade::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info shade::get_info(){
    Info tmp{hp, atk, def};
    return tmp;
}

shade::~shade(){
    
}

characterType shade::myType(){
    return characterType::shade;
}

void shade::usePotion(int value, ItemType s){
    if(s==ItemType::atk){
        atk+=value;
        if(atk<0){
            atk=0;
        }
    }else if(s==ItemType::def){
        def+=value;
        if(def<0){
            def=0;
        }
    }else if(s==ItemType::hp){
        hp+=value;
        if(hp<0){
            hp=0;
        }
    }
}

