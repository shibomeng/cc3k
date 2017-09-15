#include "character.h"
#include <iostream>

character::character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}, peratk{atk}, perdef{def}, gold{0} {}

character::~character() {
    
}

int ceiling(float num) {
    int integer = num;
    if ((integer - num) != 0) {
        return integer + 1;
    } return integer;
}
