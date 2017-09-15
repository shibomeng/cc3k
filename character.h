#ifndef character_h
#define character_h
#include <string>
#include "characterType.h"
#include "info.h"
#include "ItemType.h"

class character {
protected:
    int hp;
    int atk;
    int def;
    int peratk;
    int perdef;
    int gold;
public:
    character (int hp, int atk, int def);
    virtual ~character();
    virtual int attack(character &object) = 0;
    virtual int defend(int &damage) = 0;// dont try to call this method!!!
    virtual bool isdead()=0;
    virtual Info get_info() = 0;//return a Info class which contains some information about this character.
    virtual void print() = 0;
    virtual characterType myType()=0;
    virtual void usePotion(int value, ItemType s)=0;
    virtual void addGold(int value)=0;
    virtual void initialize_data() = 0;
    virtual int gold_drop()=0;
    virtual std::string name()=0;
};;

int ceiling(float num);// ceiling which is a math method


#endif
