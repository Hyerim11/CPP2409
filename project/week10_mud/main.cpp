#include <iostream>
#include <string>

#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User& user);
bool moveUser(int map[][mapX], int& user_x, int& user_y, User& user, string user_input);

// 메인  함수
int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2}};

    // 유저의 위치를 저장할 변수
    int user_x = 0;  // 가로 번호
    int user_y = 0;  // 세로 번호

    // 유저의 체력을 저장할 변수
    // int user_hp = 20;
    User user1;

    // 게임 시작
    while (1) {  // 사용자에게 계속 입력받기 위해 무한 루프

        // 사용자의 입력을 저장할 변수
        string user_input = "";
        cout << "현재 HP: " << user1.GetHP() << " 명령어를 입력하세요 (up,down,left,right,map,quit): ";
        cin >> user_input;
        // cout << "입력된 명령어: " << user_input << endl; // 입력한 명령어가 잘 입력되는지 확인

        // 이동하는 경우
        if (user_input == "up" || user_input == "down" || user_input == "left" || user_input == "right") {
            bool moved = moveUser(map, user_x, user_y, user1, user_input);  // 유저 이동
            // 유저가 이동한 경우에만 유저의 위치에 있는것을 확인
            if (moved == true) {
                checkState(map, user_x, user_y, user1);  // 유저의 위치 확인
            }
        }
        // 지도를 보여주는 경우
        else if (user_input == "map") {
            // TODO: 지도 보여주기 함수 호출
            displayMap(map, user_x, user_y);
        }
        // 종료
        else if (user_input == "quit") {
            cout << "게임을 종료합니다.";
            break;
        }
        // 잘못된 입력
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // HP가 0이 되었을 경우 실패를 출력하고 게임을 종료
        if (user1.GetHP() <= 0) {
            cout << "HP가 0이하가 되었습니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 목적지에 도달했는지 체크
        bool finish = checkGoal(map, user_x, user_y);
        if (finish == true) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";  // 양 옆 1칸 공백
            } else {
                int posState = map[i][j];
                switch (posState) {
                    case 0:
                        cout << "      |";  // 6칸 공백
                        break;
                    case 1:
                        cout << "아이템|";
                        break;
                    case 2:
                        cout << "  적  |";  // 양 옆 2칸 공백
                        break;
                    case 3:
                        cout << " 포션 |";  // 양 옆 1칸 공백
                        break;
                    case 4:
                        cout << "목적지|";
                        break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    bool checkFlag = false;
    if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
        checkFlag = true;
    }
    return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    // 목적지 도착하면
    if (map[user_y][user_x] == 4) {
        return true;
    }
    return false;
}

// 아이템, 적, 포션을 만났을 경우 메세지를 출력하는 함수
void checkState(int map[][mapX], int user_x, int user_y, User& user) {
    switch (map[user_y][user_x]) {
            // 아이템
        case 1:
            cout << "아이템을 만났습니다." << endl;
            break;
            // 적
        case 2:
            cout << "적을 만났습니다." << endl;
            cout << "HP가 2 줄어듭니다." << endl;
            user.DecreaseHP(2);
            break;
            // 포션
        case 3:
            cout << "포션을 얻었습니다." << endl;
            cout << "HP가 2 증가합니다." << endl;
            user.IncreaseHP(2);
            break;

        default:
            break;
    }
}

// 유저의 위치를 변경시키는 함수
bool moveUser(int map[][mapX], int& user_x, int& user_y, User& user, string user_input) {
    int temp_x = user_x;
    int temp_y = user_y;

    if (user_input == "up") {
        user_y -= 1;
    } else if (user_input == "down") {
        user_y += 1;
    } else if (user_input == "left") {
        user_x -= 1;
    } else if (user_input == "right") {
        user_x += 1;
    }

    if (checkXY(user_x, mapX, user_y, mapY) == false) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        user_x = temp_x;
        user_y = temp_y;
        return false;
    } else {
        user.DecreaseHP(1);
        cout << user_input << " 방향으로 이동합니다." << endl;
        displayMap(map, user_x, user_y);
        return true;
    }
}
