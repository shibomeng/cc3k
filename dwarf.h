#ifndef dwarl_h
#define dwarl_h
#include "enemy.h"

class dwarf: public enemy{
public:
    dwarf();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    // int drop_gold();
    ~dwarf();
    void print() override;
    characterType myType() override;
    int gold_drop() override;
    std::string name() override;
};


#endif /* dwarl_hpp */
