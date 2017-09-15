#include "vampire.h"


vampire::vampire(): player(50,25,25){}

int vampire::attack(character &object) {
    int damage = 0;
    Info defended = object.get_info();
    float damage_float = (100.00000 / (100.00000 + defended.get_def())) * atk;
    damage = ceiling(damage_float);
    int doge=object.defend(damage);
    // vampire's skill;
    if (object.myType() == characterType::dwarf) {
        hp -= 5;
    } else {
        hp += 5;
    }
    if (hp < 0) {// avoid hp to less than 0;
        hp = 0;
    }
    if(doge>0){
        return damage;
    }else{
        return -1*damage;
    }

}

int vampire::defend(int &damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    return damage;
}

Info vampire::get_info(){
    Info tmp{hp, atk, def};
    return tmp;
}
vampire::~vampire(){
    
}

characterType vampire::myType(){
    return characterType::vampire;
}

void vampire::usePotion(int value, ItemType s){
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

