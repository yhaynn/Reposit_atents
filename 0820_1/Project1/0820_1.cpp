#include <iostream>

using namespace std; 
//c���� ������ �Լ��� ��� �Ұ�, c++������ ���� �Լ��� ��� ����
//������ �Ű������� ������ Ÿ���̳� ������ �޶�� �Ѵ�.
//c++���� �Լ� ���̹��ϴ� ������� ���� �ͱ۸��� ����Ѵ�.
//���� �̸��� �Լ��� ����ϴ°��� Over loading�̶� �Ѵ�.



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


