#include <time.h>
#include <iostream>
using namespace std;

int main() {
    int *ptr;
    srand(time(NULL));  // 난수 발생기 시드 설정
    ptr = new int[10];  // 동적 메모리 할당

    for (int i = 0; i < 10; i++)
        ptr[i] = rand();  // 동적 메모리 사용

    for (int i = 0; i < 10; i++)
        cout << ptr[i] << " ";

    delete[] ptr;  // 동적 메모리 반납
    cout << endl;
    return 0;
}