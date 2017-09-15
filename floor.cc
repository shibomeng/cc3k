#include "floor.h"
#include <iostream>
#include <cstdlib>
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "potion.h"
#include "gold.h"
#include "dragon.h"

using namespace std;

void Floor::print(){
    for(int i=0; i<25; i++){
        for(int j=0; j<79; j++){
            map[i][j]->print();
        }
        cout<<endl;
    }
}

Floor::Floor(ifstream &file, shared_ptr<character> race):file{file},floorNum{1},hostile{false}{
    map.resize(25);
    myroom.resize(5);
    myroom[0] = unique_ptr<chamber>{new room1{}};
    myroom[1] = unique_ptr<chamber>{new room2{}};
    myroom[2] = unique_ptr<chamber>{new room3{}};
    myroom[3] = unique_ptr<chamber>{new room4{}};
    myroom[4] = unique_ptr<chamber>{new room5{}};
    v.resize(8);
    v[0]={0,-1};
    v[1]={-1,-1};
    v[2]={-1,0};
    v[3]={-1,1};
    v[4]={0,1};
    v[5]={1,-1};
    v[6]={1,0};
    v[7]={1,1};
    //setting up enemy possibility
    enemyTable.resize(18);
    enemyTable[0]=enemyTable[1]=enemyTable[2]=enemyTable[3]=characterType::human;
    enemyTable[4]=enemyTable[5]=enemyTable[6]=characterType::dwarf;
    enemyTable[7]=enemyTable[8]=enemyTable[9]=enemyTable[10]=enemyTable[11]=characterType::halfling;
    enemyTable[12]=enemyTable[13]=characterType::elf;
    enemyTable[14]=enemyTable[15]=characterType::orc;
    enemyTable[16]=enemyTable[17]=characterType::merchant;
    //setting up potion possibility
    potionTable.resize(3);
    potionTable[0]=ItemType::atk;
    potionTable[1]=ItemType::def;
    potionTable[2]=ItemType::hp;
    if(readmap(race)){
        this->makePlayer(race);
        this->makeStair();
        this->makePotion();
        this->makeGold();
        this->makeEnemy();
    }
}

bool Floor::readmap(shared_ptr<character> race){
    bool isEmpty=true;
    vector<pair<int, int>> myDragPos;
    vector<pair<int, int>> usedtre;
    string s;
    for(int i=0; i<25; i++){
        getline(file, s);
        map[i].resize(79);
        for(int j=0; j<79; j++){
            if(s[j]!='-' && s[j]!='|' && s[j]!='#' && s[j]!='.' && s[j]!='+' && s[j]!=' '){
                isEmpty=false;
            }
            if(s[j]=='-'){
                map[i][j]=unique_ptr<cell>{new wall{false}};
            }else if(s[j]=='|'){
                map[i][j]=unique_ptr<cell>{new wall{true}};
            }else if(s[j]=='#'){
                map[i][j]=unique_ptr<cell>{new passage{}};
            }else if(s[j]=='.'){
                map[i][j]=unique_ptr<cell>{new tile{}};
            }else if(s[j]=='+'){
                map[i][j]=unique_ptr<cell>{new door{}};
            }else if(s[j]==' '){
                map[i][j]=unique_ptr<cell>{new whiteSpace{}};
            }else if(s[j]=='P'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(selectPotion());
            }else if(s[j]=='\\'){
                map[i][j]=unique_ptr<cell>{new stair{}};
            }else if(s[j]=='@'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(race);
                playerPos=pair<int, int>{i,j};
            }else if(s[j]=='G'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(selectgold());
            }else if(s[j]=='O'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(shared_ptr<character>{new orc{}});
                enemyPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='L'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(shared_ptr<character>{new halfling{}});
                enemyPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='E'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(shared_ptr<character>{new elf{}});
                enemyPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='M'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(shared_ptr<character>{new merchant{}});
                enemyPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='W'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(shared_ptr<character>{new dwarf{}});
                enemyPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='H'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethaschara()=true;
                map[i][j]->setcharacter(shared_ptr<character>{new human{}});
                enemyPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='D'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                myDragPos.emplace_back(pair<int, int>{i,j});
            }else if(s[j]=='0'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new php{10,true}});
            }else if(s[j]=='1'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new patk{5,true}});
            }else if(s[j]=='2'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new pdef{5,true}});
            }else if(s[j]=='3'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new php{-10,true}});
            }else if(s[j]=='4'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new patk{-5,true}});
            }else if(s[j]=='5'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new pdef{-5,true}});
            }else if(s[j]=='6'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new gold{2,true}});
            }else if(s[j]=='7'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new gold{1,true}});
            }else if(s[j]=='8'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new gold{4,true}});
            }else if(s[j]=='9'){
                map[i][j]=unique_ptr<cell>{new tile{}};
                map[i][j]->gethasitem()=true;
                map[i][j]->setitem(shared_ptr<item>{new gold{6,false}});
            }
        }
    }
    for(int i=0; i<myDragPos.size();i++){
        bool isfind=false;
        pair<int, int> mydragPos{myDragPos[i].first,myDragPos[i].second};
        cell &drag = *(map[myDragPos[i].first][myDragPos[i].second]);
        vector<pair<int, int>> posstre;
        for(int j=0; j<8; j++){
            pair<int, int> myelement{myDragPos[i].first+v[j].first,myDragPos[i].second+v[j].second};
            cell &tre = *(map[myelement.first][myelement.second]);
            if(tre.gethasitem()&&(tre.getitem())->myType()==ItemType::gold&&!iselement(usedtre,myelement)){
                if(!(tre.getitem())->getcanUse()){
                    drag.gethaschara()=true;
                    drag.setcharacter(shared_ptr<character>(new dragon{tre.getitem()}));
                    usedtre.emplace_back(myelement);
                    isfind=true;
                    dragPos.emplace_back(mydragPos,myelement);
                    break;
                }else{
                    posstre.emplace_back(myelement);
                }
            }
        }
        if(!isfind){
            pair<int,int> mytrePos{posstre[0].first,posstre[0].second};
            cell &newtre=*(map[posstre[0].first][posstre[0].second]);
            newtre.setitem(shared_ptr<item>{new gold{6,false}});
            drag.gethaschara()=true;
            drag.setcharacter(shared_ptr<character>{new dragon{newtre.getitem()}});
            dragPos.emplace_back(mydragPos,mytrePos);
            usedtre.emplace_back(mytrePos);
        }
    }
    return isEmpty;
}

void Floor::makePlayer(shared_ptr<character> myrace){
    int mypos = rand() % 5;
    myroom[mypos]->getHasPlayer()=true;
    while(true){
        int x = myroom[mypos]->myx();
        int y = myroom[mypos]->myy(x);
        if(!map[x][y]->gethaschara() && !map[x][y]->gethasitem()
           && map[x][y]->mytype()==cellType::tile){
            map[x][y]->gethaschara()=true;
            map[x][y]->setcharacter(myrace);
            pair<int, int> temp {x,y};
            playerPos=temp;
            break;
        }
    }
}

void Floor::makeStair(){
    while(true){
        int mypos = rand() % 5;
        if(!myroom[mypos]->getHasPlayer()){
            int x = myroom[mypos]->myx();
            int y = myroom[mypos]->myy(x);
            if(!map[x][y]->gethaschara() && !map[x][y]->gethasitem()
               && map[x][y]->mytype()==cellType::tile){
                map[x][y]=unique_ptr<cell>{new stair{}};
                break;
            }
        }
    }
}

shared_ptr<character> Floor::selectEnemy(){
    int type = rand() % 18;
    if(enemyTable[type]==characterType::human){
        return shared_ptr<character>{new human{}};
    }else if(enemyTable[type]==characterType::dwarf){
        return shared_ptr<character>{new dwarf{}};
    }else if(enemyTable[type]==characterType::halfling){
        return shared_ptr<character>{new halfling{}};
    }else if(enemyTable[type]==characterType::elf){
        return shared_ptr<character>{new elf{}};
    }else if(enemyTable[type]==characterType::orc){
        return shared_ptr<character>{new orc{}};
    }else{
        return shared_ptr<character>{new merchant{}};
    }

}

void Floor::makeEnemy(){
    enemyPos.resize(20);
    for(int i=0; i<20; i++){
        while(true){
            pair<int,int> coord = getcoord();
            int x = coord.first;
            int y = coord.second;
            if(!map[x][y]->gethaschara() &&
               !map[x][y]->gethasitem() &&
               map[x][y]->mytype()==cellType::tile){
                map[x][y]->gethaschara()=true;
                map[x][y]->setcharacter(selectEnemy());
                pair<int, int> temp {x,y};
                enemyPos[i]=temp;
                break;
            }
        }
    }
}

bool isPlayer(character& myc){
    characterType temp = myc.myType();
    if(temp==characterType::shade||temp==characterType::drow||temp==characterType::vampire
       ||temp==characterType::troll||temp==characterType::goblin){
        return true;
    }else{
        return false;
    }
}

void Floor::enemyMove(){
    bool isatk;
    int num = enemyPos.size();
    for(int i=0; i<num; i++){
        vector<pair<int, int>> myv;
        isatk=false;
        for(int j=0; j<8; j++){
            cell & curr = *(map[enemyPos[i].first][enemyPos[i].second]);
            cell & newPos = *(map[enemyPos[i].first+v[j].first][enemyPos[i].second+v[j].second]);
            if(newPos.mytype()==cellType::tile){
                if(!newPos.gethaschara() && !newPos.gethasitem()){
                    myv.emplace_back(v[j]);
                }else if(newPos.gethaschara() && isPlayer(*(newPos.getcharacter()))){
                    if((curr.getcharacter())->myType()!=characterType::merchant||
                       ((curr.getcharacter())->myType()==characterType::merchant&&hostile)){
                        int damage = (curr.getcharacter())->attack(*(newPos.getcharacter()));
                        if(damage<0||damage==0){
                            Info temp=(curr.getcharacter())->get_info();
                            string action="Player dodges "+(curr.getcharacter())->name()+
                            "("+to_string(temp.get_hp())+")'s attack. ";
                            addaction(action);
                        }else{
                            Info temp=(curr.getcharacter())->get_info();
                            string action=(curr.getcharacter())->name()+"("+to_string(temp.get_hp())+")"+" deals "+
                            to_string(damage)+" to player. ";
                            addaction(action);
                        }
                        isatk=true;
                        break;
                    }
                }
            }
        }
        if(!isatk&&myv.size()>0 && (! if_stop_enemy )){
            int temp=rand() % myv.size();
            cell &curr = *(map[enemyPos[i].first][enemyPos[i].second]);
            cell &newPos = *(map[enemyPos[i].first+myv[temp].first][enemyPos[i].second+myv[temp].second]);
            newPos.gethaschara()=true;
            newPos.setcharacter(curr.getcharacter());
            curr.setcharacter(nullptr);
            curr.gethaschara()=false;
            enemyPos[i].first+=myv[temp].first;
            enemyPos[i].second+=myv[temp].second;
        }
    }
    dragatk();
}

pair<int, int> Floor::getcoord(){
    pair<int,int> temp;
    int roomnum=rand() % 5;
    int x = myroom[roomnum]->myx();
    int y = myroom[roomnum]->myy(x);
    temp={x,y};
    return temp;
}

shared_ptr<item> Floor::selectPotion(){
    int num = rand() % 3;
    int sign = rand() % 2;
    if(potionTable[num] == ItemType::hp){
        if(sign==0){
            return shared_ptr<item>{new php{10,true}};
        }else{

            return shared_ptr<item>{new php{-10,true}};
        }
    }else if(potionTable[num] == ItemType::atk){
        if(sign==0){
            return shared_ptr<item>{new patk{5,true}};
        }else{
            return shared_ptr<item>{new patk{-5,true}};
        }
    }else{
        if(sign==0){
            return shared_ptr<item>{new pdef{5,true}};
        }else{
            return shared_ptr<item>{new pdef{-5,true}};
        }
    }

}

void Floor::makePotion(){
    for(int i=0; i<10; i++){
        while(true){
            pair<int,int> temp = this->getcoord();
            cell & pos = *(map[temp.first][temp.second]);
            if(!pos.gethaschara()&&!pos.gethasitem()){
                pos.gethasitem()=true;
                pos.setitem(selectPotion());
                break;
            }
        }
    }
}

shared_ptr<item> Floor::selectgold(){
    vector<int> table;
    table.resize(7);
    for(int i=0; i<7; i++){
        if(i<5){
            table[i]=2;
        }else{
            table[i]=1;
        }
    }
    int g=rand()%7;
    return shared_ptr<item>{new gold{table[g],true}};
}

void Floor::makeGold(){
    vector<int> table;
    table.resize(8);
    bool find=false;
    for(int i=0; i<8; i++){
        if(i<5){
            table[i]=2;
        }else if(i==5){
            table[i]=6;
        }else{
            table[i]=1;
        }
    }
    for(int i=0; i<10;i++){
        int g=rand()%8;
        find=false;
        while(true){
            pair<int,int> temp = this->getcoord();
            cell & pos = *(map[temp.first][temp.second]);
            if(!pos.gethaschara()&&!pos.gethasitem()){
                if(table[g]!=6){
                    pos.gethasitem()=true;
                    pos.setitem(shared_ptr<item>{new gold{table[g],true}});
                    break;
                }else{
                    for(int j=0; j<8; j++){
                        cell &drag = *(map[temp.first+v[j].first][temp.second+v[j].second]);
                        if(!drag.gethaschara()&&!drag.gethasitem()&&drag.mytype()==cellType::tile){
                            pos.gethasitem()=true;
                            pos.setitem(shared_ptr<item>{new gold{table[g],false}});
                            drag.gethaschara()=true;
                            drag.setcharacter(shared_ptr<character>{new dragon{pos.getitem()}});
                            find=true;
                            pair<int, int> dragcoord{temp.first+v[j].first,temp.second+v[j].second};
                            pair<int, int> trecoord{temp.first, temp.second};
                            pair<pair<int,int>, pair<int,int>> both{dragcoord,trecoord};
                            dragPos.emplace_back(both);
                            break;
                        }
                    }
                    if(find)break;
                }
            }
        }
    }
}

void Floor::playerMove(int x, int y){
    cell &newPos = *(map[playerPos.first+x][playerPos.second+y]);
    cell &curr = *(map[playerPos.first][playerPos.second]);
    if(newPos.mytype()!=cellType::wall&&newPos.mytype()!=cellType::whiteSpace){
        if(newPos.mytype()==cellType::stair){
            nextfloor();
        }else if(!newPos.gethaschara()&&!newPos.gethasitem()){
        newPos.gethaschara()=true;
        newPos.setcharacter(curr.getcharacter());
        curr.setcharacter(nullptr);
        curr.gethaschara()=false;
        playerPos.first+=x;
        playerPos.second+=y;
        }else if(newPos.gethasitem()&&(newPos.getitem())->myType()==ItemType::gold){
            if((newPos.getitem())->getcanUse()){
                string action = "Player pick up "+to_string((newPos.getitem())->getValue())+" gold. ";
                addaction(action);
                (newPos.getitem())->useMe(*(map[playerPos.first][playerPos.second]->getcharacter()));
                newPos.setitem(nullptr);
                newPos.gethasitem()=false;
                newPos.gethaschara()=true;
                newPos.setcharacter(curr.getcharacter());
                curr.setcharacter(nullptr);
                curr.gethaschara()=false;
                playerPos.first+=x;
                playerPos.second+=y;
            }
        }
    }else if(newPos.mytype()==cellType::wall){
        string action = "And hits a wall. ";
        addaction(action);
    }
    int potionCount=0;
    for(int i=0; i<8; i++){
        cell &foundpotion = *(map[playerPos.first+v[i].first][playerPos.second+v[i].second]);
        if(foundpotion.gethasitem()){
            ItemType IT = (foundpotion.getitem())->myType();
            if(IT==ItemType::atk||IT==ItemType::def||IT==ItemType::hp){
                potionCount+=1;
            }
        }
    }
    if(potionCount>0){
        string myaction = "Player sees "+to_string(potionCount)+" unkonwn potion. ";
        addaction(myaction);
    }
}

void Floor::atk(int x,int y){
    int newx =playerPos.first+x;
    int newy= playerPos.second+y;
    cell &newPos = *(map[newx][newy]);
    cell &curr = *(map[playerPos.first][playerPos.second]);
    if(newPos.gethaschara()){
        if((newPos.getcharacter())->myType()==characterType::merchant){
            hostile=true;
        }
        int damage= curr.getcharacter()->attack(*newPos.getcharacter());
        if(damage<0||damage==0){
            Info temp = (newPos.getcharacter())->get_info();
            string action = (newPos.getcharacter())->name()+"("+to_string(temp.get_hp())+")"+ " dodges player attack. ";
            addaction(action);
        }else{
            Info temp = (newPos.getcharacter())->get_info();
            string action = "Player deals "+to_string(damage)+" to "+(newPos.getcharacter())->name()+"("+to_string(temp.get_hp())+"). ";
            addaction(action);
        }
        if((newPos.getcharacter())->isdead()){
            if((newPos.getcharacter())->myType()==characterType::human||
               (newPos.getcharacter())->myType()==characterType::merchant){
                string action2 = "Player killed "+(newPos.getcharacter())->name()+","+
                (newPos.getcharacter())->name()+" drops some gold. ";
                addaction(action2);
                newPos.setitem(shared_ptr<item>{new gold{(newPos.getcharacter())->gold_drop(),true}});
                newPos.gethasitem()=true;
                newPos.gethaschara()=false;
                newPos.setcharacter(nullptr);
                int temp=enemyPos.size();
                for(int i=0; i<=temp; i++){
                    if(enemyPos[i].first==newx&&enemyPos[i].second==newy){
                        enemyPos.erase(enemyPos.begin()+i);
                    }
                }
            }else if((newPos.getcharacter())->myType()==characterType::dragon){
                string action2 = "Player killed "+(newPos.getcharacter())->name()+",treasure unlocked. ";
                addaction(action2);
                int numdrag = dragPos.size();
                newPos.gethaschara()=false;
                newPos.setcharacter(nullptr);
                for(int i=0; i<=numdrag; i++){
                    if(dragPos[i].first.first==newx&&dragPos[i].first.second==newy){
                        dragPos.erase(dragPos.begin()+i);
                    }
                }
            }else{
                string action2 = "Player killed "+(newPos.getcharacter())->name()+",and found "+
                to_string((newPos.getcharacter())->gold_drop())+" gold. ";
                addaction(action2);
                (curr.getcharacter())->addGold((newPos.getcharacter())->gold_drop());
                int temp=enemyPos.size();
                newPos.gethaschara()=false;
                newPos.setcharacter(nullptr);
                for(int i=0; i<=temp; i++){
                    if(enemyPos[i].first==newx&&enemyPos[i].second==newy){
                        enemyPos.erase(enemyPos.begin()+i);
                    }
                }
            }
        }
    }
}

void Floor::usePotion(int x, int y){
    cell &newPos = *(map[playerPos.first+x][playerPos.second+y]);
    cell &curr = *(map[playerPos.first][playerPos.second]);
    if(newPos.gethasitem()){
        ItemType s = (newPos.getitem())->myType();
        if(s==ItemType::atk){
            if((newPos.getitem())->getValue()==5){
                string action = "Player used BA potion. ";
                addaction(action);
            }else if((newPos.getitem())->getValue()==-5){
                string action = "Player used WA potion. ";
                addaction(action);
            }
        }else if(s==ItemType::def){
            if((newPos.getitem())->getValue()==5){
                string action = "Player used BD potion. ";
                addaction(action);
            }else if((newPos.getitem())->getValue()==-5){
                string action = "Player used WD potion. ";
                addaction(action);
            }
        }else if(s==ItemType::hp){
            if((newPos.getitem())->getValue()==10){
                string action = "Player used RH potion. ";
                addaction(action);
            }else if((newPos.getitem())->getValue()==-10){
                string action = "Player used PH potion. ";
                addaction(action);
            }
        }
        if(s==ItemType::atk||s==ItemType::def||s==ItemType::hp){
            newPos.getitem()->useMe(*(curr.getcharacter()));
            newPos.gethasitem()=false;
            newPos.setitem(nullptr);
        }
    }
}

void Floor::nextfloor(){
    floorNum+=1;
    string s;
    shared_ptr<character> race = map[playerPos.first][playerPos.second]->getcharacter();
    race->initialize_data();
    dragPos.clear();
    enemyPos.clear();
    for(int i=0; i<5; i++){
        myroom[i]->getHasPlayer()=false;
    }
    if(readmap(race)){
        enemyPos.resize(20);
        this->makePlayer(race);
        this->makeStair();
        this->makePotion();
        this->makeGold();
        this->makeEnemy();
    }
}

bool Floor::iswon(){
    if(floorNum==5){
        return true;
    }else{
        return false;
    }
}

void Floor::dragatk(){
    for(int i=0; i<dragPos.size(); i++){
        for(int j=0; j<8; j++){
            cell & curr = *(map[dragPos[i].first.first][dragPos[i].first.second]);
            cell & newPos = *(map[dragPos[i].first.first+v[j].first][dragPos[i].first.second+v[j].second]);
            //cell & treasure = *(map[dragPos[i].second.first][dragPos[i].second.second]);
            cell & newtrea = *(map[dragPos[i].second.first+v[j].first][dragPos[i].second.second+v[j].second]);
            if(newPos.gethaschara()&&isPlayer(*(newPos.getcharacter()))){
                int damage = curr.getcharacter()->attack(*(newPos.getcharacter()));
                string action;
                Info myD= (curr.getcharacter())->get_info();
                if(damage<1){
                    action="Player dodges "+(curr.getcharacter())->name()+"("+to_string(myD.get_hp())+")'s attack.";
                }else{
                    action=(curr.getcharacter())->name()+"("+to_string(myD.get_hp())+") deals "+to_string(damage)+"to Player.";
                }
                addaction(action);
                break;
            }else if(newtrea.gethaschara()&&isPlayer(*(newtrea.getcharacter()))){
                int damage = curr.getcharacter()->attack(*(newtrea.getcharacter()));
                string action;
                Info myD= (curr.getcharacter())->get_info();
                if(damage<1){
                    action="Player dodges "+(curr.getcharacter())->name()+"("+to_string(myD.get_hp())+")'s attack.";
                }else{
                    action=(curr.getcharacter())->name()+"("+to_string(myD.get_hp())+") deals "+to_string(damage)+"to Player.";
                }
                addaction(action);
                break;
            }
            
        }
    }
}



// condition field:

void Floor::is_stop_enemy() {
    if (if_stop_enemy) {
        if_stop_enemy = false;
    } else {
        if_stop_enemy = true;
    }
}

bool iselement(vector<pair<int, int>> &array, pair<int,int> &element){
    int size = array.size();
    for(int i=0; i<size; i++){
        if(array[i].first==element.first&&
           array[i].second==element.second){
            return true;
        }
    }
    return false;
}

int Floor::getFloor(){
    return floorNum;
}

void Floor::addaction(string &s){
    myaction+=s;
}

void Floor::printAction(){
    cout<<"Action:"<<myaction<<endl;
}

void Floor::resetAction(){
    myaction=" ";
}

