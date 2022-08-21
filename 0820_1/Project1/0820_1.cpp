#include <iostream>

using namespace std; 
//c에선 동일한 함수명 사용 불가, c++에서는 동인 함수명 사용 가능
//조건은 매개변수의 데이터 타입이나 갯수가 달라야 한다.
//c++에선 함수 네이밍하는 방법으로 네임 맹글링을 사용한다.
//같은 이름의 함수를 사용하는것을 Over loading이라 한다.



/*int add(int a, int b)  //addXX
{
	return a+b;

}*/

int add(int a, int b)  //addXX
{
	return a + b;

}

float add(float a, float b)	//addYY
{
	return a + b;

}

float add(float a, int b)	//addYX
{
		return a+b;
}

float add(float a, float b, float c) //addYYY
{
	return a + b + c;
}



int main() 
{
	int a = 20;
	int b = 30;
	float c = 1.21f;
	float d = 3.14f;

	int ret = add(a, b);
	float fret = add(c, d);

	cout << a << "+" << b << "=" << ret << endl; //call

	cout << c << "+" << d << "=" << fret << endl; //call

	return 0;
}


