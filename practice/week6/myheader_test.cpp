// 헤더파일 include 해서 함수 사용
#include <iostream>
#include "myheader.h"
using namespace std;

int main() {
    int a = 2, b = 3;
    int value = summation(a, b);
    cout << value << endl;

    return 0;
}