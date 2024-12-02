/*
예외 처리 한 부분 
직업의 입력이 잘못된 경우(63, 65)
사용자의 입력이 잘못된 경우 (109, 129)
사용자의 입력으로 맵 밖으로 나갔을 경우 (230)
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(vector<vector<int>> map, User& user);
bool CheckGoal(vector<vector<int>> map, User& user);
void CheckState(vector<vector<int>> map, User& user);
bool MoveUser(vector<vector<int>> map, User& user, string user_input);
bool CheckUser(User& user);

// 메인  함수
int main() {
    vector<vector<int>> map(mapY, vector<int>(mapX));
    ifstream map_file("map.txt");

    if (!map_file) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }

    int map_num;

    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            map_file >> map[i][j];
        }
    }
    map_file.close();

    User* current_user;  // 현재 유저
    string user_condition;

    // 직업 입력받기
    while (1) {
        try {
            cout << "직업을 선택하세요." << endl;
            cout << "1. Magician, 2. Warrior" << endl;
            cin >> user_condition;

            if (user_condition == "1") {
                current_user = new Magician();
                break;
            } else if (user_condition == "2") {
                current_user = new Warrior();
                break;
            } else {
                throw out_of_range("잘못된 입력입니다. 1 또는 2를 입력하세요.");
            }
        } catch (exception& e) {
            cerr << "직업 입력 중 오류: " << e.what() << endl;
        }
    }

    // 게임 시작
    while (1) {  // 사용자에게 계속 입력받기 위해 무한 루프
        try {
            // 사용자의 입력을 저장할 변수
            string user_input = "";
            cout << "현재 HP: " << current_user->GetHP();
            cout << " 명령어를 입력하세요 (up,down,left,right,map,info,quit): ";
            cin >> user_input;
            // cout << "입력된 명령어: " << user_input << endl; // 입력한 명령어가 잘 입력되는지 확인

            // 이동하는 경우
            if (user_input == "up" || user_input == "down" || user_input == "left" || user_input == "right") {
                bool moved = MoveUser(map, *current_user, user_input);  // 유저 이동
                // 유저가 이동한 경우에만 유저의 위치에 있는것을 확인
                if (moved == true) {
                    CheckState(map, *current_user);  // 유저의 위치 확인
                } else {
                    continue;
                }
            }
            // 지도를 보여주는 경우
            else if (user_input == "map") {
                // TODO: 지도 보여주기 함수 호출
                DisplayMap(map, *current_user);
                continue;
            }
            // 종료
            else if (user_input == "quit") {
                cout << "게임을 종료합니다.";
                break;
            }
            // 정보
            else if (user_input == "info") {
                cout << *current_user << endl;
                continue;
            }

            // 잘못된 입력
            else {
                throw invalid_argument("up,down,left,right,map,info,quit 중 하나를 입력하세요.");
            }

            // HP가 0이 되었을 경우 실패를 출력하고 게임을 종료
            if (CheckUser(*current_user) == false) {
                cout << "HP가 0이하가 되었습니다. 실패했습니다." << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }

            // 목적지에 도달했는지 체크
            bool finish = CheckGoal(map, *current_user);
            if (finish == true) {
                cout << "목적지에 도착했습니다! 축하합니다!" << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }
        }

        catch (exception& e) {
            cerr << "게임 중 오류: " << e.what() << endl;
        }
    }
    delete current_user;
    return 0;
}

// 지도와 사용자 위치 출력하는 함수
void DisplayMap(vector<vector<int>> map, User& user) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user.GetY() && j == user.GetX()) {
                cout << " USER |";  // 양 옆 1칸 공백
            }

            else {
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
bool CheckGoal(vector<vector<int>> map, User& user) {
    // 목적지 도착하면
    if (map[user.GetY()][user.GetX()] == 4) {
        return true;
    }
    return false;
}

// 아이템, 적, 포션을 만났을 경우 메세지를 출력하는 함수
void CheckState(vector<vector<int>> map, User& user) {
    switch (map[user.GetY()][user.GetX()]) {
            // 아이템
        case 1:
            cout << "아이템을 만났습니다." << endl;
            user.IncreaseItemCnt(1);
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
bool MoveUser(vector<vector<int>> map, User& user, string user_input) {
    int x = user.GetX();
    int y = user.GetY();

    if (user_input == "up") {
        y--;
    } else if (user_input == "down") {
        y++;
    } else if (user_input == "left") {
        x--;
    } else if (user_input == "right") {
        x++;
    }

    if (checkXY(x, mapX, y, mapY) == false) {
        throw out_of_range("맵을 벗어났습니다. 다시 돌아갑니다.");
    }
    user.SetXY(x, y);
    user.DecreaseHP(1);
    cout << user_input << " 방향으로 이동합니다." << endl;
    DisplayMap(map, user);
    return true;
}

bool CheckUser(User& user) {
    if (user.GetHP() <= 0) {
        return false;
    } else {
        return true;
    }
}
