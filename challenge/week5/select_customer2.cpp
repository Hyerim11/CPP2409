#include <iostream>
#include <string>
using namespace std;

int main(){
    // 5명의 이름과 나이를 입력받기
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++){
        cout << "사람" << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람" << i+1 << "의 나이: ";
        cin >> ages[i];
    }
    
    // 나이가 가장 많은 사람 
    int max = ages[0];
    int maxIndex = 0;
    for (int i = 0; i < maxPeople; i++){
        if (ages[i] > max){
            max = ages[i];
            maxIndex = i;
            
            // 비교가 잘 되는지 확인용 출력
            // cout << "i:" << i << " max:" << max << endl;
        }
    }
    
    // 나이가 가장 적은 사람
    int min = ages[0];
    int minIndex = 0;
    for (int i = 0; i < maxPeople; i++){
        if (ages[i] < min){
            min = ages[i];
            minIndex = i;

            // 비교가 잘 되는지 확인용 출력
            // cout << "i:" << i << " min:" << min << endl;
        }
    }
    // 메뉴 보여주기
    while(true){
        int menu;
        cout << "1. 나이가 가장 많은 사람" << endl;
        cout << "2. 나이가 가장 적은 사람" << endl;
        cout << "3. 종료" << endl;
        cout << "메뉴를 입력하세요: ";
        cin >> menu;
        
        if (menu == 1){
            cout << "나이가 가장 많은 사람: "<< names[maxIndex] << " (" << ages[maxIndex] << "세)" << endl;
        }
        else if (menu == 2){
            cout << "나이가 가장 적은 사람: "<< names[minIndex] << " (" << ages[minIndex] << "세)" << endl;
        }
        else if(menu == 3){
            cout << "종료" << endl;
            return 0;
        }
        else{
            cout << "잘못된 선택입니다. 종료 합니다. " << endl;
            return 0;
        }
    }
    
}