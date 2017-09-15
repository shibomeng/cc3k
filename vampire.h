#ifndef vampire_h
#define vampire_h

#include "player.h"

class vampire: public player{
    // int hp;
    // int atk;
    // int def;
public:
    vampire();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~vampire();
    characterType myType() override;
    void usePotion(int value, ItemType s) override;
};

#endif /* vampire_hpp */
