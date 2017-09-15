
#ifndef shade_h
#define shade_h
#include "player.h"

class shade: public player{

public:
    shade();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~shade();
    characterType myType() override;
    void usePotion(int value, ItemType s) override;
};
#endif
