
#ifndef cell_h
#define cell_h
#include "character.h"
#include "cellType.h"
#include "item.h"
#include <memory>
class cell{
protected:
    bool hasitem;
    bool haschara;
    std::shared_ptr<character> mycharacter;
    std::shared_ptr<item> myitem;
public:
    cell();
    virtual void print()=0;
    bool &gethasitem();
    bool &gethaschara();
    std::shared_ptr<item>getitem();
    std::shared_ptr<character> getcharacter();
    void setcharacter(std::shared_ptr<character>);
    void setitem(std::shared_ptr<item>);
    virtual cellType mytype()const=0;
    virtual ~cell();
};

class wall : public cell{
    bool isVertical;
public:
    void print() override;
    wall(bool isVertical);
    cellType mytype() const override;
};

class tile : public cell{
public:
    void print() override;
    cellType mytype() const override;
};

class door : public cell{
public:
    void print() override;
    cellType mytype() const override;
};

class passage : public cell{
public:
    void print() override;
    cellType mytype() const override;
};

class stair : public cell{
public:
    void print() override;
    cellType mytype() const override;
};

class whiteSpace : public cell{
public:
    void print() override;
    cellType mytype() const override;
};
#endif
