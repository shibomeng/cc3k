//
//  item.hpp
//  cc3k
//
//  Created by Libin Xue on 2017-07-20.
//  Copyright © 2017 Libin Xue. All rights reserved.
//

#ifndef item_h
#define item_h

#include "character.h"
#include "ItemType.h"

class item{
protected:
    int effect;
    bool canUse;
public:
    item(int effect, bool canUse);
    ~item();
    virtual void useMe(character &c)=0;
    virtual void print()=0;
    virtual ItemType myType()=0;
    bool & getcanUse();
    virtual int getValue()=0;
};
#endif 
