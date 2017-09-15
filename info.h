#ifndef info_h
#define info_h

class Info {
    int hp;
    int atk;
    int def;
public:
    Info(int hp, int atk, int def);
    int get_hp();
    int get_atk();
    int get_def();
    ~Info();
    void print();
};

#endif /* info_hpp */
