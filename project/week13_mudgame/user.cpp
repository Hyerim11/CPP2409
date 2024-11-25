#include "user.h"
// 생성자
User::User() {
    hp = 20;
    itemCnt = 0;
    user_x = 0;
    user_y = 0;
}

// 출력연산자 중복 정의
ostream& operator<<(ostream& os, const User& u) {
    os << "현재 HP는 " << u.hp << "이고, 먹은 아이템은 총 " << u.itemCnt << "개 입니다." << endl;
    return os;
}


//////Magician

// hp 증가 함수
void Magician::IncreaseHP(int inc_hp) override { hp += inc_hp; }

// hp 감소 함수
void Magician::DecreaseHP(int dec_hp) override { hp -= dec_hp; }

// hp 반환
int Magician::GetHP() override { return hp; }

// item 증가 함수
void Magician::IncreaseItemCnt(int inc_item) override { itemCnt += inc_item; }

// item 먹은 횟수 반환
int Magician::GetItemCnt() override { return itemCnt; }

void Magician::DoAttack() override {
    cout << "마법 사용" << endl;
}

// 유저의 좌표값
void Magician::SetXY(int x, int y) override {
    user_x = x;
    user_y = y;
}
int Magician::GetX() override { return user_x; }
int Magician::GetY() override { return user_y; }

//////Warrior

// hp 증가 함수
void Warrior::IncreaseHP(int inc_hp) override { hp += inc_hp; }

// hp 감소 함수
void Warrior::DecreaseHP(int dec_hp) override { hp -= dec_hp; }

// hp 반환
int Warrior::GetHP() override { return hp; }

// item 증가 함수
void Warrior::IncreaseItemCnt(int inc_item) override { itemCnt += inc_item; }

// item 먹은 횟수 반환
int Warrior::GetItemCnt() override { return itemCnt; }

void Warrior::DoAttack() override {
    cout << "베기 사용" << endl;
}

// 유저의 좌표값
void Warrior::SetXY(int x, int y) override {
    user_x = x;
    user_y = y;
}
int Warrior::GetX() override { return user_x; }
int Warrior::GetY() override { return user_y; }
