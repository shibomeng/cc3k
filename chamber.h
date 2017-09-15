#ifndef chamber_h
#define chamber_h

struct chamber{
    bool hasPlayer;
public:
    chamber();
    virtual int myx()=0;
    virtual int myy(int x)=0;
    bool &getHasPlayer();
    
};

struct room1 : public chamber{
public:
    room1();
    int myx() override;
    int myy(int x) override;
};

struct room2 : public chamber{
public:
    room2();
    int myx() override;
    int myy(int x) override;
};

struct room3 : public chamber{
public:
    room3();
    int myx() override;
    int myy(int x) override;
};

struct room4 : public chamber{
public:
    room4();
    int myx() override;
    int myy(int x) override;
};

struct room5 : public chamber{
public:
    room5();
    int myx() override;
    int myy(int x) override;
};


#endif
