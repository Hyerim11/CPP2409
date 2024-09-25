#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int answer = rand() % 100;
    int tries = 0;

    int guess;

    do{
        cout << "정답을 추측: ";
        cin >> guess;
        tries++;

        if (guess > answer){
            cout << "제시한 정수가 높습니다" << endl;
        }
        if (guess < answer){
            cout << "제시한 정수가 낮습니다" << endl;
        }

    } while (answer != guess);

    cout << "축하합니다. 시도횟수= " << tries << endl;

    return 0;
    
}