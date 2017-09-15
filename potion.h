
#ifndef potion_h
#define potion_h
#include "item.h"

class patk: public item {
public:
    patk(int value, bool canUse);
    void print() override;
    void useMe(character &c) override;
    ItemType myType() override;
    int getValue() override;
};

class php: public item{
public:
    php(int value, bool canUse);
    void print() override;
    void useMe(character &c) override;
    ItemType myType() override;
    int getValue() override;
};

class pdef: public item{
public:
    pdef(int value, bool canUse);
    void print() override;
    void useMe(character &c) override;
    ItemType myType() override;
    int getValue() override;
};

#endif
