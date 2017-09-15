
#ifndef floor_h
#define floor_h

#include <vector>
#include "cell.h"
#include <fstream>
#include <utility>
#include "chamber.h"
#include <memory>
#include <string>
class Floor{
    std::vector<std::pair<int, int>> v;
    std::vector<characterType> enemyTable;
    std::vector<ItemType> potionTable;
    std::vector<std::vector<std::unique_ptr<cell>>> map;
    std::vector<std::pair<int, int>> enemyPos;
    std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> dragPos;
    std::vector<std::pair<int, int>> treasure;
    std::pair<int, int> playerPos;
    std::vector<std::unique_ptr<chamber>> myroom;
    std::pair<int, int> getcoord();
    std::ifstream &file;
    int floorNum;
    bool hostile;
    void dragatk();
    std::shared_ptr<character> selectEnemy();
    std::shared_ptr<item> selectPotion();
    std::shared_ptr<item> selectgold();
    // condition field:
    bool if_stop_enemy;
    std::string myaction;
public:
    void addaction(std::string &s);
    void printAction();
    void resetAction();
    void print();
    Floor(std::ifstream &file,std::shared_ptr<character>race);
    void makeEnemy();
    void enemyMove();
    void makePlayer(std::shared_ptr<character> myrace);
    void makeStair();
    void playerMove(int x, int y);
    void atk(int x, int y);
    void makePotion();
    void makeGold();
    void usePotion(int x, int y);
    bool readmap(std::shared_ptr<character> race);
    void nextfloor();
    bool iswon();
    int getFloor();
    // condition field:
    void is_stop_enemy();
};

bool iselement(std::vector<std::pair<int, int>> &array, std::pair<int,int> &element);
#endif
