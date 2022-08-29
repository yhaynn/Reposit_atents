#include <iostream>

using namespace std;
//다중 상속 (부모가 둘이상인 경우)
//모호함 ambiguity 발생
//이질적인 클래스간은 사용 가능.


class A {
public:
	int _value=1000;
};

class B {
public:
	int _value=3000;
};

class C :public A,public B{
public:
	void ShowInfo() {
		cout << A::_value << endl;
		cout << B::_value << endl;

	}

};


// 이질적인 것은 괜찮다고 합니다.
// SmartPhone 클래스를 다중상속해서 만들어 보세요....
//class Phone {
//
//};
//
//
//class Computer {
//
//};
//
//class SmartPhone : public Phone, public Computer {
//
//};
//
//
//int main() {
//
//	C c;
//
//	c.ShowInfo();
//	return 0;
//}