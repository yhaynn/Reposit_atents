//
//
//#include <iostream>
//
//using namespace std;
//
//class Complex {
//private:
//    int _real;
//    int _imaginary;
//
//public:
//    Complex(int real, int imaginary)
//        : _real(real), _imaginary(imaginary) {}
//
//    Complex operator+(Complex& ref) {
//        Complex temp(_real + ref._real, _imaginary + ref._imaginary);
//
//    
////연산자는 기본적으로 기본 datatype(int float 등)에만 제공되는것
////C++은 기본 데이터타입이 아니어도(만들어진 객체) 연산을 가능하게 해주능 연산자 오버로딩이 존재
//
//        return temp;
//    }
//
//    void info() {
//        cout << _real << showpos << _imaginary << "i" << endl;
//        cout << noshowpos;
//    }
//
//};
//
//int main() {
//    Complex a(10, 10);
//    Complex b(20, 20);
//    Complex c(0, 0);
//
//    c = a + b;
//    c = a.operator+(b);  //위 항을 풀어쓴것
//
//    a.info();
//    b.info();
//
//    c.info();
//
//    return 0;
//}

#include <iostream>

using namespace std;

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {}

    Complex operator+(Complex& ref) {
        Complex temp(_real + ref._real, _imaginary + ref._imaginary);

        return temp;
    }


    Complex operator-(Complex& ref) {
        Complex temp(_real - ref._real, _imaginary - ref._imaginary);

        return temp;
    }

    void info() {
        cout << _real << showpos << _imaginary << "i" << endl;
        cout << noshowpos;
    }

};

int main() {
    Complex a(10, 10);
    Complex b(20, 20);
    Complex c(0, 0);

    c = a + b;
    c = a.operator+(b);



    a.info();
    b.info();

    c.info();

    c = a - b;
    c.info();

    return 0;
}