//
//  goblin.cpp
//  cc3k
//
//  Created by Li Jing on 2017-07-15.
//  Copyright © 2017 Li Jing. All rights reserved.
//

#include "goblin.h"

goblin::goblin(): player(110,15,20){}

int goblin::attack(character &object) {
    int damage = 0;
    Info defended = object.get_info();
    float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
    damage = ceiling(damage_float);
    int doge = object.defend(damage);
    
    // Goblin skill:
    Info ob = object.get_info();
    if (ob.get_hp() == 0) {
        gold += 5;
    }
    if(doge>0){
        return damage;
    }else{
        return -1*damage;
    }

}

int goblin::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info goblin::get_info(){
    Info tmp{hp, atk, def};
    return tmp;
}
goblin::~goblin(){
    
}

characterType goblin::myType(){
    return characterType::goblin;
}

void goblin::usePotion(int value, ItemType s){
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
        if(hp>110){
            hp=110;
        }else if(hp<0){
            hp=0;
        }
    }
}


