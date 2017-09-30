#include "chamber.h"
#include <cstdlib>

chamber::chamber():hasPlayer{false}{}

room1::room1():chamber(){}
room2::room2():chamber(){}
room3::room3():chamber(){}
room4::room4():chamber(){}
room5::room5():chamber(){}

bool &chamber::getHasPlayer(){
    return hasPlayer;
}

int room1::myx(){
    return (rand() % 4 + 3);
}

int room1::myy(int){
    return (rand() % 26 + 3);
}

int room2::myx(){
    return (rand() % 7 + 15);
}

int room2::myy(int){
    return (rand() % 21 + 4);
}

int room3::myx(){
    return (rand() % 3 + 10);
}

int room3::myy(int){
    return (rand() % 12 + 38);
}

int room4::myx(){
    return (rand() % 10 + 3);
}

int room4::myy(int x){
    if(x==3||x==4){
        return (rand() % 23 + 39);
    }else if(x==5){
        return (rand() % 31 + 39);
    }else if(x==6){
        return (rand() % 34 + 39);
    }else{
        return (rand() % 15 + 61);
    }
}

int room5::myx(){
    return (rand() % 6 + 16);
}

int room5::myy(int x){
    if(x==16||x==17||x==18){
        return (rand() % 11 + 65);
    }else{
        return (rand() % 39 + 37);
    }
}
