#include <iostream>
using namespace std;

int main(){
    cout << "구구단: " << endl;

    // 2단부터 9단까지
    for (int i = 2; i <= 9; ++i){
        cout << i << "단:" <<endl;

        for (int j = 1 ; j <= 9; ++j)
        {
            cout << i << " x " << j << " = " << (i * j) << endl;
        }

        cout << endl;
        
    }
    return 0;
}