
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <ctime>
#include "floor.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"

using namespace std;

// game_system:

// print some introduction before start the game;
void introduce_cc3k () {
    ifstream file {"introduction.txt"};
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    } cout << ">> Choose your character to get start: ";
}

// is***():
bool isMove_Command(string command) {
    if (command == "no" || command == "so" || command == "ea" ||
        command == "we" || command == "ne" || command == "nw" ||
        command == "se" || command == "sw") {
        return true;
    } return false;
}

bool isUsePotion_Command(string command) {
    if (command == "u no" || command == "u so" || command == "u ea" ||
        command == "u we" || command == "u ne" || command == "u nw" ||
        command == "u se" || command == "u sw") {
        return true;
    } return false;
}
bool isAttack_Command(string command) {
    if (command == "a no" || command == "a so" || command == "a ea" ||
        command == "a we" || command == "a ne" || command == "a nw" ||
        command == "a se" || command == "a sw") {
        return true;
    } return false;
}



// pc_***():
void pc_move(string command, shared_ptr<Floor> myfloor) {
    // void pc_move(string command, floor* myfloor) {
    if(command=="no"){
        string action = "Player moves north.";
        myfloor->addaction(action);
        myfloor->playerMove(-1, 0);
    }else if(command=="so"){
        string action = "Player moves south.";
        myfloor->addaction(action);
        myfloor->playerMove(1, 0);
    }else if(command=="ea"){
        string action = "Player moves east.";
        myfloor->addaction(action);
        myfloor->playerMove(0, 1);
    }else if(command=="we"){
        string action = "Player moves west.";
        myfloor->addaction(action);
        myfloor->playerMove(0, -1);
    }else if(command=="ne"){
        string action = "Player moves north east.";
        myfloor->addaction(action);
        myfloor->playerMove(1, 1);
    }else if(command=="nw"){
        string action = "Player moves north west.";
        myfloor->addaction(action);
        myfloor->playerMove(1, -1);
    }else if(command=="se"){
        string action = "Player moves south east.";
        myfloor->addaction(action);
        myfloor->playerMove(-1, 1);
    }else if(command=="sw"){
        string action = "Player moves south west.";
        myfloor->addaction(action);
        myfloor->playerMove(-1, -1);
    }
}

void pc_UsePotion(string command, shared_ptr<Floor> myfloor) {
    // void pc_UsePotion(string command, floor* myfloor) {
    if(command=="u no"){
        myfloor->usePotion(-1, 0);
    }else if(command=="u so"){
        myfloor->usePotion(1, 0);
    }else if(command=="u ea"){
        myfloor->usePotion(0, 1);
    }else if(command=="u we"){
        myfloor->usePotion(0, -1);
    }else if(command=="u ne"){
        myfloor->usePotion(-1, 1);
    }else if(command=="u nw"){
        myfloor->usePotion(-1, -1);
    }else if(command=="u se"){
        myfloor->usePotion(1, 1);
    }else if(command=="u sw"){
        myfloor->usePotion(1, -1);
    }
}

void pc_Attack(string command, shared_ptr<Floor> myfloor) {
    // void pc_Attack(string command, floor* myfloor) {
    if(command=="a no"){
        myfloor->atk(-1, 0);
    }else if(command=="a so"){
        myfloor->atk(1, 0);
    }else if(command=="a ea"){
        myfloor->atk(0, 1);
    }else if(command=="a we"){
        myfloor->atk(0, -1);
    }else if(command=="a ne"){
        myfloor->atk(-1, 1);
    }else if(command=="a nw"){
        myfloor->atk(-1, -1);
    }else if(command=="a se"){
        myfloor->atk(1, 1);
    }else if(command=="a sw"){
        myfloor->atk(1, -1);
    }
}

void summary(vector<int> scores, string pc_race, shared_ptr<character> PC, int& num_scores) {
    ifstream file {"summary.txt"};
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    } int score = PC->gold_drop();
    // cout << "score: " << score << " !!!!!" <<endl;
    // sort(scores.begin(), scores.end());
    if (pc_race == "s") {score *= 1.5;}
    if (scores[0] < score) {
        scores[0] = score;
    } sort(scores.begin(), scores.end());
    for (int i = 4; i >= 0; i--) {
        cout << "|         " <<  (5 - i) <<". ";
        cout << std::setfill('0') << std::setw(5) << scores[i];
        cout << "                                                            |" << endl;
    }
    /////////////////////////////////////////
    ifstream file2 {"summary2.txt"};
    while (getline(file2, line)) {
        cout << line << endl;
    }
}

void end_to_new_game(shared_ptr<Floor> myfloor, shared_ptr<character> PC, bool& game_start) {
    // void end_to_new_game(floor* myfloor, shared_ptr<character> PC, bool& game_start) {
    // summary(scores, pc_race);
    string command;
    while (getline(cin, command)) {
        if (command == "r") {
            // cout << "chose a race to get start: " << endl;
            myfloor->print();//print floor
            PC->get_info().print();//print info
            cout<< "gold: "<<PC->gold_drop()<<endl;//print gold
            game_start = false;
            cout << "chose a race to get start: " << endl;
            break;
        }
    }
}


bool isLost(shared_ptr<character> PC) {
    int hp = PC->get_info().get_hp();
    if (hp == 0) {
        return true;
    } return false;
}

void summary_lost(vector<int> scores, string pc_race, shared_ptr<character> PC, int& num_scores) {
    ifstream file {"summarylost.txt"};
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    } int score = PC->gold_drop();
    // cout << "score: " << score << " !!!!!" <<endl;
    // sort(scores.begin(), scores.end());
    if (pc_race == "s") {score *= 1.5;}
    if (scores[0] < score) {
        scores[0] = score;
    } sort(scores.begin(), scores.end());
    for (int i = 4; i >= 0; i--) {
        cout << "|         " <<  (5 - i) <<". ";
        cout << std::setfill('0') << std::setw(5) << scores[i];
        cout << "                                                            |" << endl;
    }
    /////////////////////////////////////////
    ifstream file2 {"summary2.txt"};
    while (getline(file2, line)) {
        cout << line << endl;
    }
}


//////////////////////////////////////////////////////////////////////////////


int main (int argc, const char * argv[]){
    string raceStr;
    //////////// game_system useful variable:////////////////
    srand((unsigned)time(NULL));
    string command;
    shared_ptr<character> PC;
    // character* PC = nullptr;
    bool game_start = false;
    
    shared_ptr<Floor> myfloor;

    string pc_race;
    vector<int> scores; // need to delete?
    scores.resize(5);
    int num_scores = 0;
    
    for (int  i = 0; i < 5; i++) {
        scores[i] = 0;
    }
    
    // variable for floor;
    
    ifstream default_map {argv[1]};
    ifstream own_map {"empty_map.txt"};

    introduce_cc3k();
    
    
    /////////// game start:
    while (getline(cin, command)) {
        if (! game_start) {// just choose a race when it's a new game;
            // player_choose_race(PC, command);
            if(command == "s"){
                PC = shared_ptr<character>{new shade{}};
                raceStr="Shade";
                pc_race = command;
            }else if(command == "d"){
                PC = shared_ptr<character>{new drow{}};
                raceStr="Drow";
                pc_race = command;
                
            }else if(command == "v"){
                PC = shared_ptr<character>{new vampire{}};
                raceStr="Vampire";
                pc_race = command;
                
            }else if(command == "g"){
                PC = shared_ptr<character>{new goblin{}};
                raceStr="Goblin";
                pc_race = command;
                
            }else if(command == "t"){
                PC = shared_ptr<character>{new troll{}};
                raceStr="Troll";
                pc_race = command;
                
            } else {
                continue;
            }
            game_start = true;
            
            // prepare the game
            if (argc > 1) {
                myfloor = shared_ptr<Floor>{new Floor {default_map, PC}};
                // myfloor = new floor{default_map, PC};
                string action {"Player character has spawned."};
                myfloor->addaction(action);
            } else {
                myfloor = shared_ptr<Floor>{new Floor {own_map, PC}};
                // myfloor = new floor{own_map, PC};
                string action {"Player character has spawned."};
                myfloor->addaction(action);
            }
            
        } else if (command == "r" && game_start) {
            cout << "chose a race to get start: " << endl;
            myfloor->print();//print floor
            PC->get_info().print();//print info
            cout<<PC->gold_drop()<<endl;//print gold
            myfloor->printAction();
            myfloor->resetAction();
            // print action
            game_start = false;
            
        } else if (command == "q" && game_start) {
            myfloor->print();//print floor
            break;
        } else if (isMove_Command(command) && game_start) {// move //
            pc_move(command, myfloor);
            
            // troll skill:
            int troll_skill = -5;
            if (pc_race == "t") {
                PC->defend(troll_skill);
            }
            // enemy_move:
            myfloor->enemyMove();
            
            if (isLost(PC)) {// LOST!!!
                summary_lost(scores, pc_race, PC, num_scores);
                end_to_new_game(myfloor, PC, game_start);
            } else if (myfloor->iswon()) {// summary here //
                summary(scores, pc_race, PC, num_scores);
                end_to_new_game(myfloor, PC, game_start);
            }
        } else if (isAttack_Command(command) && game_start) {// attack //
            
            
            // attack:
            pc_Attack(command, myfloor);
            // troll skill:
            int troll_skill = -5;
            if (pc_race == "t") {
                PC->defend(troll_skill);
            }
            // enemy_move:
            myfloor->enemyMove();
            
            if (isLost(PC)) {// LOST!!!
                summary_lost(scores, pc_race, PC, num_scores);
                end_to_new_game(myfloor, PC, game_start);
            }
            
        } else if (isUsePotion_Command(command) && game_start) {// usePotion //
            
            // use_potion:
            pc_UsePotion(command, myfloor);
            // troll skill:
            int troll_skill = -5;
            if (pc_race == "t") {
                PC->defend(troll_skill);
            }
            // enemy_move:
            myfloor->enemyMove();
            
            if (isLost(PC)) {// LOST!!!
                summary_lost(scores, pc_race, PC, num_scores);
                end_to_new_game(myfloor, PC, game_start);
            }
            
        } else if (command == "f" && game_start) {
            myfloor->is_stop_enemy();
        } // else: command will be ingoreed;
        if (game_start) {
            myfloor->print();//print floor
            cout<<"Race: "<<raceStr<<" "<<"gold: "<<PC->gold_drop()<<" Floor:"<<myfloor->getFloor()<< endl;
            PC->get_info().print();//print info
            myfloor->printAction();
            myfloor->resetAction();
        }
    }
}
/*
 
 #include <vector>
 #include <algorithm>
 #include <iostream>
 
 
 using namespace std;
 
 
 int main() {
 int nums[] = {1, 3, 62, 32, 45, 0};
 vector<int> mynums (nums, nums + 6);
 sort (mynums.begin(), mynums.end());
 for (int i = 0; i < 6; i++) {
 cout << mynums[i] << " ";
 } cout << endl;
 
 }
 
 
 */












