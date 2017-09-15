
#include "troll.h"

troll::troll(): player(120, 25, 15){}

int troll::attack(character &object) {
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

int troll::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }else if(hp>120){
        hp=120;
    }
    return damage;
}

Info troll::get_info(){
    Info tmp{hp, atk, def};
    return tmp;
}

troll::~troll(){
    
}

characterType troll::myType(){
    return characterType::troll;
}

void troll::usePotion(int value, ItemType s){
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
        if(hp>120){
            hp=120;
        }else if(hp<0){
            hp=0;
        }
    }
}

