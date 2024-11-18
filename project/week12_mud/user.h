#include <iostream>
using namespace std;

class User {
   private:
    int hp;
    int itemCnt;

   public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();
    void IncreaseItemCnt(int inc_item);
    int GetItemCnt();
    friend ostream& operator<<(ostream& os, const User& u);
};
