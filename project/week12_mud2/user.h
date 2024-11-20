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
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();
    void IncreaseItemCnt(int inc_item);
    int GetItemCnt();
    friend ostream& operator<<(ostream& os, const User& u);
    void DoAttack();
    void SetXY(int x, int y);
    int GetX();
    int GetY();
};

class Magician : public User {
   public:
    void DoAttack();
};

class Warrior : public User {
   public:
    void DoAttack();
};