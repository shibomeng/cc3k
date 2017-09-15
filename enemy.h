#ifndef enemy_h
#define enemy_h
#include "character.h"


class enemy: public character {
public:
    // Enemy(int gold);
    enemy(int hp, int atk, int def);
    // virtual int drop_gold();
    virtual ~enemy();
    void addGold(int value) override;
    void initialize_data() override;
    void usePotion(int value, ItemType) override;
    virtual bool isdead() override;
};

#endif /* enemy_hpp */
