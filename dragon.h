
#ifndef dragon_hpp
#define dragon_hpp

#include "enemy.h"
#include "item.h"
#include <memory>

class dragon: public enemy{
    std::shared_ptr<item> treasure;
public:
    dragon(std::shared_ptr<item> treasure);
    int attack(character &object) override;
    int defend(int &damage) override;
    Info get_info() override;
    ~dragon();
    characterType myType() override;
    void print() override;
    int gold_drop() override;
    bool isdead() override;
    std::string name() override;
};

#endif /* dragon_hpp */
