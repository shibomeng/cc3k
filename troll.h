#ifndef troll_h
#define troll_h
#include "player.h"

class troll: public player{
    // int hp;
    // int atk;
    // int def;
public:
    troll();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~troll();
    characterType myType() override;
    void usePotion(int value, ItemType s) override;
};


#endif /* troll_hpp */
