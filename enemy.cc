#include "enemy.h"


// Enemy::Enemy(int gold): gold{gold}, Character(){}
enemy::enemy(int hp, int atk, int def): character(hp, atk, def){}

enemy::~enemy(){}

void enemy::addGold(int value){}
void enemy::initialize_data(){}
void enemy::usePotion(int value, ItemType){}

bool enemy::isdead(){
    if(hp==0){
        return true;
    }else{
        return false;
    }
}
