#include <iostream>

using namespace std;

class  Student
{
public:
	
	string _name;  // �������
	int _age;
	int _grade;

public:
	Student() {};
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

int main() {
	Student* pa = new Student("monter", 10, 3);		//������ü�� �Ҵ�

	pa->info(); //�ּҰ����� Ŭ������ ����� �����Ҷ� ȭ��ǥ �����ڸ� ���.

	//pa->_age = 20;
	//pa->_grade = 12;  ==(*pa)._age = 100;

	delete pa;		//������ü ��ȯ

	Student * parray= new Student[5];		//���� ��ü �迭�� ���鶩 �⺻ �����ڰ� �ʿ�.

	for (int i = 0; i < 5; i++) {
		parray[i].Init("monster", i, i);
	}

	for (int i = 0; i < 5; i++) {
		parray[i].info();
	}

	delete[] parray;
}


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


//Datatype-����

//int main() {
//
//	int a;		//���� ����(��������),�ڵ� ����. �� int main(){} �ȿ����� ���
//	a = 20;
//
//	global = 100000;
//
//	int* pa; //������ ��������
//	 pa = new int; //�����޸� ���� �Ҵ�
//
//	*pa = 1000; //  * : ������ ������. �� �ּҰ��� �Ҵ���� �Ϳ� �����Ҷ�. 
//
//
//	cout << " * pa =" << *pa << endl;
//
//
//	int count = 0;
//	cout << "�ʿ��� ������ ������ �Է��ϼ���: " << endl;
//	cin >> count;
//
//	int* parray = new int[count];  //�����迭
//
//	for (int i = 0; i < count; i++) {
//		parray[i] = i;		//parray[n]�̸� parray�κ��� nĭ ������ ��(���)�� ����
//	}
//
//	for (int i = 0; i < count; i++) {
//		cout << "parray[" << i << "]" << "=" << parray[i] << endl;
//	}
//
//	delete pa;		//�����迭 ��ȯó��
//	delete[] parray;  //�����迭�� ��ȯ�� []
//
//	return 0;
//
//	delete pa;	//���� �޸� ������ ��ȯ
//}