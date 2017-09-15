//
//  drow.hpp
//  cc3k
//
//  Created by Li Jing on 2017-07-15.
//  Copyright © 2017 Li Jing. All rights reserved.
//

#ifndef drow_h
#define drow_h

#include "player.h"

class drow: public player{
    // int hp;
    // int atk;
    // int def;
public:
    drow();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~drow();
    characterType myType() override;
    void usePotion(int value, ItemType s) override;
};

#endif /* drow_hpp */
