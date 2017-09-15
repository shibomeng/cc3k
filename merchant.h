

#ifndef merchant_h
#define merchant_h

#include "enemy.h"

class merchant: public enemy{
    // int hp;
    // int atk;
    // int def;
public:
    merchant();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    // int drop_gold();
    ~merchant();
    characterType myType() override;
    void print() override;
    int gold_drop() override;
    std::string name() override;
};

#endif /* merchant_hpp */
