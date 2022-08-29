#include <iostream>

using namespace std;

class Watch {
private:
	string _name;

public:
	Watch(string name)
		:_name(name)	
	{
		cout << "Watch 생성자 생성" << endl;
	}

	~Watch() {
		cout << "Watch 소멸자 생성" << endl;
	}

	void WhatTime() {
		cout << "시계가 작동합니다" << endl;
	}
};

class SmartPhone {
public:
	SmartPhone() {
		cout << "스마트폰 생성자" << endl;
	}

	~SmartPhone() {
		cout << "스마트폰 소멸자" << endl;
	}

	void Say() {
		cout << "스마트폰이 작동합니다" << endl;
	}
};

class Heart {
public:
	Heart() {
		cout << "Heart 생성자" << endl;
	}

	~Heart() {
		cout << "Heart 소멸자" << endl;
	}

	void Say() {
		cout << "심장이 뜁니다" << endl;
	}

};

class Human {
private:
	Heart _heart;  //composition : 포함된 객체가 생명주기를 같이 함.강한 결합

	SmartPhone& _smartPhone; //참조형 변수. agreeggation: 포함된 객체가 생명주기를 같이하지 않음. 약한결합

	Watch* _pWatch; //포인터형 변수 agreeggatio: 포함된 객체가 생명주기를 같이 한다.


public:
	Human(SmartPhone& ref)
		:_smartPhone(ref) {
		cout << "Human 생성자" << endl;
	}

	~Human() {
		cout << "Human 소멸자" << endl;
	}

	void SetWatch(Watch* pvalue) {
		_pWatch = pvalue;
	}

	void PlayHeartSound() {
		_heart.Say();
	}

	void PlayPhone() {
		_smartPhone.Say();
	}

	
	void ShowWatch() {
		if (_pWatch != NULL)
		{
			_pWatch->WhatTime();
		}
	}
};

int main() {
	
	SmartPhone phone;
	Watch redWatch("redWatch");
	Watch blueWatch("blueWatch");
	
	
	cout << "포함 시작" << endl;
	
	{
		Human human(phone);
		human.PlayHeartSound();
		human.PlayPhone();

		human.SetWatch(&redWatch);
		human.ShowWatch();

		human.SetWatch(&blueWatch);
		human.ShowWatch();

	}
	cout << "포함 끝" << endl;
}