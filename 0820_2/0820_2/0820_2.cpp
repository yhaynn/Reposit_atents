#include <iostream>

using namespace std;

class  Student
{
public:
	
	string _name;  // 멤버변수
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
		cout << "이름:" << _name << endl;
		cout << "나이:" << _age << endl;
		cout << "학년:" << _grade << endl;
	}
};

int main() {
	Student* pa = new Student("monter", 10, 3);		//동적객체를 할당

	pa->info(); //주소값으로 클래스의 멤버에 접글할때 화살표 연산자를 사용.

	//pa->_age = 20;
	//pa->_grade = 12;  ==(*pa)._age = 100;

	delete pa;		//동적개체 반환

	Student * parray= new Student[5];		//동적 객체 배열을 만들땐 기본 생성자가 필요.

	for (int i = 0; i < 5; i++) {
		parray[i].Init("monster", i, i);
	}

	for (int i = 0; i < 5; i++) {
		parray[i].info();
	}

	delete[] parray;
}


int global = 100;		//외부 변수(전역 변수). 어디서든지 어떤 함수에서든 접근 가능

int SetScore(int value) {
	static int score = 0;  //static: 로컬변수, 정적변수.
	//호출이 띁나도 함수가 사자리지 않고 존속 누적
	score += value;

	return value;
}


//동적객체
//변수의 종류
//접근 범위, 존속기간
//실행중에 메모리가 필요한 공간. 동적 메모리 공간 heap. OS가 관리
//동적 메모리 공간은 할당받으면 후에 반납처리 해야만 한다.
//안그러면 메모리에 게속 누적


//Datatype-변수

//int main() {
//
//	int a;		//로컬 변수(지역변수),자동 변수. 이 int main(){} 안에서만 통용
//	a = 20;
//
//	global = 100000;
//
//	int* pa; //포인터 형지정자
//	 pa = new int; //동적메모리 공간 할당
//
//	*pa = 1000; //  * : 포인터 연산자. 그 주소값에 할당받은 것에 접근할때. 
//
//
//	cout << " * pa =" << *pa << endl;
//
//
//	int count = 0;
//	cout << "필요한 정수의 갯수를 입력하세요: " << endl;
//	cin >> count;
//
//	int* parray = new int[count];  //동적배열
//
//	for (int i = 0; i < count; i++) {
//		parray[i] = i;		//parray[n]이면 parray로부터 n칸 떨어진 곳(요소)에 저장
//	}
//
//	for (int i = 0; i < count; i++) {
//		cout << "parray[" << i << "]" << "=" << parray[i] << endl;
//	}
//
//	delete pa;		//동적배열 반환처리
//	delete[] parray;  //동적배열을 반환시 []
//
//	return 0;
//
//	delete pa;	//동적 메모리 공간을 반환
//}