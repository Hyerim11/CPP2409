#include <iostream>
using namespace std;

class Rectangle {
   public:
    int width, height;

    int CalcArea() {
        return width * height;
    }
};

int main() {
    Rectangle obj1;
    Rectangle obj2;

    obj1.width = 3;
    obj1.height = 4;
    int area1 = obj1.CalcArea();

    obj2.width = 10;
    obj2.height = 10;
    int area2 = obj2.CalcArea();

    cout << "사각형1의 넓이: " << area1 << endl;
    cout << "사각형2의 넓이: " << area2 << endl;
    return 0;
}