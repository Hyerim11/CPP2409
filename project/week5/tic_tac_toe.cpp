#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누구의 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while (true) {
        
        // 1. 누구의 차례인지 출력
        switch (k % 2) {
            case 0:
                cout << "첫번째 유저(X)의 차례입니다. -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다. -> ";
                currentUser = 'O';
                break;
        }

        // 2. 좌표입력받기
        cout << "좌표를 입력하세요 (0 ~ 2) (0 ~ 2): ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << "좌표가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;

        // 6. 빙고 시 승자 출력 후 종료
        /*
        가로 세로 대각선
        가로: (00, 01, 02)(10, 11, 12)(20, 21, 22)
        세로: (00, 10, 20)(01, 11, 21)(02, 12, 22)
        대각선: 왼쪽 위에서 부터(00, 11, 22)
               오른쪽 위에서 부터(02, 11, 20)
        */
        
        // 승자출력
        for (int i = 0; i < numCell; i++) {
            // 가로로 승리할 경우
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
                cout << "가로에 모든 돌이 놓였습니다. " << currentUser <<"의 승리입니다. ";
                return 0;
            }
            // 세로로 승리할 경우
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
                cout << "세로에 모든 돌이 놓였습니다. " << currentUser <<"의 승리입니다. ";
                return 0;
            }
        }

        // 대각선으로 승리할 경우
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
            cout << " 대각선 왼쪽 위부터 오른쪽 아래까지 모든 돌이 놓였습니다. " << currentUser <<"의 승리입니다. ";
            return 0;
        }
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
            cout << " 대각선 오른쪽 위부터 왼쪽 아래까지 모든 돌이 놓였습니다. " << currentUser <<"의 승리입니다. ";
            return 0;
        }

        // 7. 모든칸이 찼으면 종료
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    checked++;
                }
                
            }
        }
        if (checked == 0) {
            cout << "칸이 다 찼습니다. 종료합니다." << endl;
            break;
        }
       

    }
    return 0;
}