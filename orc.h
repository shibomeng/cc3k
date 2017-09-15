#ifndef orcs_h
#define orcs_h

#include "enemy.h"

class orc: public enemy{
    // int hp;
    // int atk;
    // int def;
public:
    orc();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    void print() override;
    // int drop_gold();
    characterType myType() override;
    ~orc();
    int gold_drop() override;
    std::string name() override;
};

#endif /* orcs_hpp */
