#include <iostream>
using namespace std;

class User {
   protected:
    int hp;
    int itemCnt;
    int user_x;
    int user_y;

   public:
    User();

    friend ostream& operator<<(ostream& os, const User& u);

    virtual void IncreaseHP(int inc_hp) = 0;
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual int GetHP() = 0;

    virtual void IncreaseItemCnt(int inc_item) = 0;
    virtual int GetItemCnt() = 0;

    virtual void DoAttack();
    virtual void SetXY(int x, int y) = 0;
    virtual int GetX() = 0;
    virtual int GetY() = 0;
};

class Magician : public User {
   public:
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();

    void IncreaseItemCnt(int inc_item);
    int GetItemCnt();

    void DoAttack();

    void SetXY(int x, int y);
    int GetX();
    int GetY();
};

class Warrior : public User {
   public:
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();

    void IncreaseItemCnt(int inc_item);
    int GetItemCnt();

    void DoAttack();

    void SetXY(int x, int y);
    int GetX();
    int GetY();
};