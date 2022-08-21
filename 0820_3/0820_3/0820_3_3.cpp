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


//업캐스팅

int main() {

	Parent a;
	Child b;
	a._value1 = 100;
	b._value1 = 300;
	b._value2 = 400;


	//부모의 데이터타빕에 자긷의 데이타 타입을 대입할 수 있습니다.
	//업캐스팅
	cout << "a._value1 = " << a._value1 << endl;
	a = b;  //b=a 불가. 부무에서 자식은 가능하나 자식에서 부모는 안된다.

	cout << "a._value1 = " << a._value1 << endl;
	
	Parent& refa = b;  //업캐스팅

	cout << "refa._value1 = " << refa._value1 << endl;

	Child& refaa = (Child&)refa; //다운캐스팅
	
	Parent* pa = &b; //pa라는 변수가 만들어지고 여기에 b변수의 주소값이 들어감. parent형 주소값
	pa->_value1 = 100;  //업캐스팅

	cout << "pa->_value1 = " << pa->_value1 << endl;

	Child* paa = (Child*)pa;

	cout << "paa->_value1 = " << paa->_value1 << endl;
	cout << "paa->_value2 = " << paa->_value2 << endl;

	return 0;
}