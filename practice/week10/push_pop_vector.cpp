#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> v;

    // 벡터에 값 넣기
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    // 벡터 값 출력
    cout << "현재의 v = ";
    for (auto& e : v) {
        cout << e << " ";
    }
    cout << endl;

    cout << "삭제 요소 = ";
    // 벡터가 공백이 될 때까지 pop_back() 호출
    while (v.empty() != true) {
        cout << v.back() << " ";  // 제일 끝에 있는 것 출력
        v.pop_back();             // 끌에 있는 것 삭제
    }
    cout << endl;

    return 0;
}