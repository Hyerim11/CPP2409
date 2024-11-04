#include "user.h"
// 생성자
User::User() {
    hp = 20;
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