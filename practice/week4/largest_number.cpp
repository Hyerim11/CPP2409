#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수 입력: ";
    cin >> a >> b >> c;

    /*

    if (a > b && a > c){         
        largest = a;             
    }
    else if (b > a && b > c){    
        largest = b;
    }
    else{
        largest = c;
    }

    만약 2 2 1 과 같이 a와 b가 중복인데 가장 큰 수 일 경우 제대로 작동하지 않는다. 
    if문과 else if문에서 a와 b가 같은경우 a > b, a < b 모두 거짓이 된다.
    그러므로 c가 결과로 나온다. 

    */

    if (a >= b && a >= c){        // 수가 같은 경우를 포함한다. 
        largest = a;
    }
    else if (b >= a && b >= c){    // 수가 같은 경우를 포함한다. 
        largest = b;
    }
    else{
        largest = c;
    }

    cout << "가장 큰 정수: " << largest << endl;

    return 0;

}