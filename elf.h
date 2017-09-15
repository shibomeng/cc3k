
#ifndef elf_h
#define elf_h

#include "enemy.h"

class elf: public enemy{
public:
    elf();
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    // int drop_gold();
    void print() override;
    ~elf();
    characterType myType() override;
    int gold_drop() override;
    std::string name() override;
};

#endif /* elf_hpp */
