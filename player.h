
#ifndef player_h
#define player_h
#include "character.h"

class player: public character {
public:
    player(int hp, int atk, int def);
    virtual ~player();
    void print() override;
    void addGold(int value) override;
    void initialize_data() override;
    int gold_drop() override;
    bool isdead() override;
    std::string name() override;

};

#endif /* player_hpp */
