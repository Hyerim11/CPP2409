#include <iostream>
using namespace std;

class Complex {
   public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
        cout << "생성자 호출";
        Print();
    }
    ~Complex() {
        cout << "소멸자 호출";
        Print();
    }
    void Print() {
        cout << real << "+" << imag << "i" << endl;
    }
};

// 복사 생성자 자동 호출
Complex Add(Complex x, Complex y) {
    Complex c;
    c.real = x.real + y.real;
    c.imag = x.imag + y.imag;

    return c;
}

int main() {
    Complex c1{1, 2}, c2{3, 4};
    Complex t;
    t = Add(c1, c2);
    t.Print();
    return 0;
}