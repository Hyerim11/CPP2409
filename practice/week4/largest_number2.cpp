#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수 입력: ";
    cin >> a >> b >> c;
/*
    if (a >= b && a >= c){        // 수가 같은 경우를 포함한다. 
        largest = a;
    }
    else if (b >= a && b >= c){    // 수가 같은 경우를 포함한다. 
        largest = b;
    }
    else{
        largest = c;
    }
*/
    
    if (a >= b) {
        if (a >= c) {
            largest = a;
        }
        else {
            largest = c;
        }
    }
    else if (b >= c){
        largest = b;
    }
    else largest = c;

    cout << "가장 큰 정수: " << largest << endl;

    return 0;

}