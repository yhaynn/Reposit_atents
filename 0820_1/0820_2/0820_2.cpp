#include <iostream>

using namespace std;

class  Student
{
private:
	string _name;  // �������
	int _age;
	int _grade;

public:
	Student(string name, int age, int grade)
		: _name(name), _age(age), _grade(grade) {}

	void Init(string name, int age, int grade) {
		_name = name;
		_age = age;
		_grade = grade;
	}

	void info() {
		cout << "�̸�:" << _name << endl;
		cout << "����:" << _age << endl;
		cout << "�г�:" << _grade << endl;
	}
};



int global = 100;		//�ܺ� ����(���� ����). ��𼭵��� � �Լ������� ���� ����

int SetScore(int value) {
	static int score = 0;  //static: ���ú���, ��������.
							//ȣ���� ������ �Լ��� ���ڸ��� �ʰ� ���� ����
	score += value;

	return value;
}



//������ü
//������ ����
//���� ����, ���ӱⰣ
//�����߿� �޸𸮰� �ʿ��� ����. ���� �޸� ���� heap. OS�� ����
//���� �޸� ������ �Ҵ������ �Ŀ� �ݳ�ó�� �ؾ߸� �Ѵ�.
//�ȱ׷��� �޸𸮿� �Լ� ����

int main() {
	
	int a;		//���� ����(��������),�ڵ� ����. �� int main(){} �ȿ����� ���
	a = 20;		

	global = 100000;

	int* pa; //������ ��������
	int*pa =new int; //�����޸� ���� �Ҵ�

	*pa = 1000; //  * : ������ ������. �� �ּҰ��� �Ҵ���� �Ϳ� �����Ҷ�


	cout << " * pa =" << *pa << endl;


	int count = 0;
	cout << "�ʿ��� ������ ������ �Է��ϼ���: " << endl;
	cin >> count;

	int* parray = new int[count];  //�����迭

	for (int i = 0; i < count; i++) {
		parray[i] = i;		//parray[n]�̸� parray�κ��� nĭ ������ ��(���)�� ����
	}

	for (int i = 0; i < count; i++) {
		cout << "parray[" << i << "]" << "=" << parray[i] << endl;
	}

	delete pa;		//�����迭 ��ȯó��
	delete[] parray;  //�����迭�� ��ȯ�� []

	return 0;

	delete pa;	//���� �޸� ������ ��ȯ
}