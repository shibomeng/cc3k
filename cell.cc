
#include "cell.h"
#include <iostream>
using namespace std;

//cell class
cell::cell():hasitem{false}, haschara{false}, mycharacter{nullptr}, myitem{nullptr}{}

bool &cell::gethasitem(){
    return hasitem;
}
shared_ptr<character> cell::getcharacter(){
    return mycharacter;
}
void cell::setcharacter(shared_ptr<character> character){
    mycharacter=character;
}

bool &cell::gethaschara(){
    return haschara;
}

shared_ptr<item> cell::getitem(){
    return myitem;
}

void cell::setitem(shared_ptr<item> item){
    myitem=item;
}

cell::~cell(){}

//wall class
void wall::print(){
    if(isVertical){
        cout<<'|';
    }else{
        cout<<'-';
    }
}

cellType wall::mytype()const{
    return cellType::wall;
}

wall::wall(bool isVertical): cell{},isVertical{isVertical} {}

//door class
void door::print(){
    if(haschara){
        mycharacter->print();
    }else{
        cout<<'+';
    }
}

cellType door::mytype()const{
    return cellType::door;
}

//stair class
void stair::print(){
    cout<<'\\';
}

cellType stair::mytype()const{
    return cellType::stair;
}

//passage class
void passage::print(){
    if(haschara){
        mycharacter->print();
    }else{
        cout<<'#';
    }
}

cellType passage::mytype()const{
    return cellType::passage;
}

//tile class
void tile::print(){
    if(haschara){
        mycharacter->print();
    }else if(hasitem){
        myitem->print();
    }else{
        cout<<'.';
    }
}

cellType tile::mytype()const{
    return cellType::tile;
}

//whiteSpace class
void  whiteSpace::print(){
    cout<<' ';
}

cellType whiteSpace::mytype()const{
    return cellType::whiteSpace;
}
