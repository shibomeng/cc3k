#ifndef human_h
#define human_h
#include "enemy.h"

class human: public enemy{
public:
    human();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~human();
    void print() override;
    characterType myType() override;
    int gold_drop() override;
    std::string name() override;
};
#endif /* human_hpp */

