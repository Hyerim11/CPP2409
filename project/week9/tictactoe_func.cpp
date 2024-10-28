#include <iostream>
using namespace std;
const int numCell = 5;  // 보드판의 가로 세로 길이

// 유효성을 검사하는 함수
int isValid(int x, int y, char board[numCell][numCell]) {
    // 좌표 범위를 벗어날 때
    if (x >= numCell || y >= numCell) {
        cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
        return false;
    }
    // 좌표범위의 입력값이 중복될 때
    if (board[x][y] != ' ') {
        cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
        return false;
    }

    return true;
}

// 승자를 확인하는 함수
bool checkWin(char currentUser, char board[numCell][numCell]) {
    int countLR = 0;  // 왼쪽 위에서 오른쪽 아래
    int countRL = 0;  // 오른쪽 위에서 왼쪽 아래

    // 가로/세로 돌 체크하기
    for (int i = 0; i < numCell; i++) {
        int countRow = 0;
        int countCol = 0;

        for (int j = 0; j < numCell; j++) {
            if (board[i][j] == currentUser) {
                countRow++;
            }
            if (board[j][i] == currentUser) {
                countCol++;
            }
        }
        if (countRow == numCell) {
            cout << "가로에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }
        if (countCol == numCell) {
            cout << "세로에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }
    }

    // 대각선
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] == currentUser) {
            countLR++;
        }
        if (board[i][numCell - i - 1] == currentUser) {
            countRL++;
        }
    }

    if (countLR == numCell) {
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    if (countRL == numCell) {
        cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    return false;
}

int main() {
    // 게임을 진행하는 데 필요한 변수 선언
    int k = 0;                       // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X';          // 현재 유저의 돌을 저장하기 위한 변수
    char board[numCell][numCell]{};  // 보드판을 나타내는 2차원 배열
    int x, y = 0;                    // 사용자에게 xy좌표값을 입력받기 위한 변수
    int numUser = 3;                 // 플레이 하는 유저 수

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // 게임을 무한 반복
    while (true) {
        // 1. 누구 차례인지 출력
        // 3인용 게임
        switch (k % numUser) {
            case 0:
                currentUser = 'X';
                break;
            case 1:
                currentUser = 'O';
                break;
            case 2:
                currentUser = 'H';
                break;
        }
        cout << k % numUser + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 함수 호출
        bool valid = isValid(x, y, board);

        // valid 값이 false이면 유효성 검사 실패, 다시 입력하세요
        if (valid == false) {
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        // numCell에 맞추기
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell - 1; j++) {
                cout << "---|";
            }
            cout << "---" << endl;

            for (int k = 0; k < numCell; k++) {
                cout << board[i][k];
                if (k == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }

        for (int j = 0; j < numCell - 1; j++) {
            cout << "---|";
        }
        cout << "---" << endl;

        bool isWin = checkWin(currentUser, board);  // 승리 여부

        // 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
        if (isWin == true) {
            cout << k % numUser + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 7. 모든 칸 다 찼는지 체크하기
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    checked++;
                }
            }
        }
        if (checked == 0) {
            cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
            break;
        }

        k++;
    }

    return 0;
}