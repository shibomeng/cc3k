//
//  potion.cpp
//  cc3k
//
//  Created by Libin Xue on 2017-07-20.
//  Copyright © 2017 Libin Xue. All rights reserved.
//

#include "potion.h"
#include <iostream>
using namespace std;

void patk::useMe(character &c) {
    c.usePotion(effect, ItemType::atk);
}

void php::useMe(character &c) {
    c.usePotion(effect, ItemType::hp);
}

void pdef::useMe(character &c) {
    c.usePotion(effect, ItemType::def);
}

void patk::print() {
    cout << "P";
}

void php::print() {
    cout << "P";
}

void pdef::print() {
    cout << "P";
}

patk::patk(int value, bool canUse): item{value, canUse} {}
php::php(int value, bool canUse): item{value, canUse} {}
pdef::pdef(int value, bool canUse): item{value, canUse} {}

ItemType patk::myType(){
    return ItemType::atk;
}
ItemType php::myType(){
    return ItemType::hp;
}
ItemType pdef::myType(){
    return ItemType::def;
}

int patk::getValue(){
    return effect;
}

int php::getValue(){
    return effect;
}

int pdef::getValue(){
    return effect;
}
