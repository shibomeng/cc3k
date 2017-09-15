//
//  gold.cpp
//  cc3k
//
//  Created by Libin Xue on 2017-07-20.
//  Copyright © 2017 Libin Xue. All rights reserved.
//

#include "gold.h"
#include <iostream>
using namespace std;

void gold::useMe(character &c) {
    c.addGold(effect);
}

void gold::print() {
    cout << "G";
}

ItemType gold::myType(){
    return ItemType::gold;
}

gold::gold(int g, bool canUse): item(g, canUse){}

int gold::getValue(){
    return effect;
}
