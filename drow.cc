//
//  drow.cpp
//  cc3k
//
//  Created by Li Jing on 2017-07-15.
//  Copyright © 2017 Li Jing. All rights reserved.
//

# include "drow.h"


drow::drow(): player(150,25,15){}

int drow::attack(character &object) {
    int damage = 0;
    Info defended = object.get_info();
    float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
    damage = ceiling(damage_float);
    int doge = object.defend(damage);
    if(doge>0){
        return damage;
    }else{
        return -1*damage;
    }

}

int drow::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info drow::get_info(){
    Info tmp{hp, atk, def};
    return tmp;
}
drow::~drow(){
    
}

characterType drow::myType(){
    return characterType::drow;
}

void drow::usePotion(int value, ItemType s){
    if(s==ItemType::atk){
        atk+= 1.5*value;
        if(atk<0){
            atk=0;
        }
    }else if(s==ItemType::def){
        def+= 1.5*value;
        if(def<0){
            def=0;
        }
    }else if(s==ItemType::hp){
        hp+= 1.5*value;
        if(hp>150){
            hp=150;
        }else if(hp<0){
            hp=0;
        }
    }
}










