//
//  item.cpp
//  cc3k
//
//  Created by Libin Xue on 2017-07-20.
//  Copyright © 2017 Libin Xue. All rights reserved.
//

#include "item.h"

item::item(int effect, bool canUse): effect{effect}, canUse{canUse} {}

item::~item() { }

bool & item::getcanUse(){
    return canUse;
}
