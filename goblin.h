

#ifndef goblin_h
#define goblin_h
#include "player.h"

class goblin: public player{
    // int hp;
    // int atk;
    // int def;
public:
    goblin();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~goblin();
    characterType myType() override;
    void usePotion(int value, ItemType s) override;
};


#endif /* goblin_hpp */
