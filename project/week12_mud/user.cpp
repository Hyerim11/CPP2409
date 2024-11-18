#include "user.h"
// 생성자
User::User() {
    hp = 20;
    itemCnt = 0;
}

// hp 증가 함수
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// hp 감소 함수
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// hp 반환
int User::GetHP() {
    return hp;
}

// item 증가 함수
void User::IncreaseItemCnt(int inc_item) {
    itemCnt += inc_item;
}

// item 먹은 횟수 반환
int User::GetItemCnt() {
    return itemCnt;
}

// 출력연산자 중복 정의
ostream& operator<<(ostream& os, const User& u) {
    os << "현재 HP는 " << u.hp << "이고, 먹은 아이템은 총 " << u.itemCnt << "개 입니다." << endl;
    return os;
}