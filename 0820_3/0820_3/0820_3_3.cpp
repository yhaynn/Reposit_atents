#include <iostream>

using namespace std;

class Parent {
public:
	int _value1;
};


class Child :public Parent {
public:
	int _value2;

};


//��ĳ����

int main() {

	Parent a;
	Child b;
	a._value1 = 100;
	b._value1 = 300;
	b._value2 = 400;


	//�θ��� ������Ÿ���� �ڱ��� ����Ÿ Ÿ���� ������ �� �ֽ��ϴ�.
	//��ĳ����
	cout << "a._value1 = " << a._value1 << endl;
	a = b;  //b=a �Ұ�. �ι����� �ڽ��� �����ϳ� �ڽĿ��� �θ�� �ȵȴ�.

	cout << "a._value1 = " << a._value1 << endl;
	
	Parent& refa = b;  //��ĳ����

	cout << "refa._value1 = " << refa._value1 << endl;

	Child& refaa = (Child&)refa; //�ٿ�ĳ����
	
	Parent* pa = &b; //pa��� ������ ��������� ���⿡ b������ �ּҰ��� ��. parent�� �ּҰ�
	pa->_value1 = 100;  //��ĳ����

	cout << "pa->_value1 = " << pa->_value1 << endl;

	Child* paa = (Child*)pa;

	cout << "paa->_value1 = " << paa->_value1 << endl;
	cout << "paa->_value2 = " << paa->_value2 << endl;

	return 0;
}