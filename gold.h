//
//  gold.hpp
//  cc3k
//
//  Created by Libin Xue on 2017-07-20.
//  Copyright © 2017 Libin Xue. All rights reserved.
//

#ifndef gold_h
#define gold_h
#include "item.h"

class gold : public item{
public:
    void useMe(character &c) override;
    void print() override;
    ItemType myType() override;
    gold(int g, bool canUse);
    int getValue() override;
};

#endif
