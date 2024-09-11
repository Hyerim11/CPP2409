#include <iostream>
using namespace std;

int main()
{
    int x = 1;

    cout << "x = " << x++ << endl;  // 1 출력 후 증가 (현재 2)
    cout << "x = " << x++ << endl;  // 2 출력 후 증가 (현재 3)
    cout << "x = " << ++x << endl;  // 3에서 증가한후 4 출력
    cout << "x = " << x-- << endl;  // 4 출력 후 감소(현재 3)
    cout << "x = " << x-- << endl;  // 3 출력 후 감소(현재 2)
    cout << "x = " << --x << endl;  // 2에서 감소 후 1 출력

    return 0;
}