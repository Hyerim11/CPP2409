#include <iostream>
using namespace std;

int main()
{
    float tem;
    
    cout << "화씨온도 : ";
    cin >> tem;
    
    cout << "섭씨온도 : " << (5.0 / 9.0)*(tem - 32) << endl;

    return 0;
}