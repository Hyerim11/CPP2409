#include <iostream>
using namespace std;

#define WIDTH 9
#define HEIGHT 3

int main() {
    // 이차원 배열 3 x 9
    int table[HEIGHT][WIDTH];
    int r, c; 

    // 배열에 값 넣기
    for (r = 0; r < HEIGHT; r++){
        for (c = 0; c < WIDTH; c++){
            table[r][c] = (r + 1) * (c + 1); 
        }
    }

    // 배열 출력
    for (r = 0; r < HEIGHT; r++){
        for (c = 0; c < WIDTH; c++){
            cout << table[r][c] << ", ";
        }
        cout << endl;
    } 
}