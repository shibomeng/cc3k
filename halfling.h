
#ifndef halfling_h
#define halfling_h

#include "enemy.h"

class halfling: public enemy{
    // int hp;
    // int atk;
    // int def;
public:
    halfling();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    // int drop_gold();
    ~halfling();
    characterType myType() override;
    void print() override;
    int gold_drop() override;
    std::string name() override;
};

#endif /* halfling_hpp */
