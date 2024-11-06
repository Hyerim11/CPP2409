#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> students;

    while (true) {
        int score;
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;

        if (score == -1) {
            break;
        }
        students.push_back(score);
    }

    float sum = 0;

    for (auto c : students) {
        sum += c;
    }

    float avg = sum / students.size();
    cout << "성적 평균" << avg << endl;
    return 0;
}