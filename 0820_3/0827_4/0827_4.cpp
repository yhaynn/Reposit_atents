#include <iostream>

using namespace std;
//���� ��� (�θ� ���̻��� ���)
//��ȣ�� ambiguity �߻�
//�������� Ŭ�������� ��� ����.


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


// �������� ���� �����ٰ� �մϴ�.
// SmartPhone Ŭ������ ���߻���ؼ� ����� ������....
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