#include <iostream>

using namespace std;

class Watch {
private:
	string _name;

public:
	Watch(string name)
		:_name(name)	
	{
		cout << "Watch ������ ����" << endl;
	}

	~Watch() {
		cout << "Watch �Ҹ��� ����" << endl;
	}

	void WhatTime() {
		cout << "�ð谡 �۵��մϴ�" << endl;
	}
};

class SmartPhone {
public:
	SmartPhone() {
		cout << "����Ʈ�� ������" << endl;
	}

	~SmartPhone() {
		cout << "����Ʈ�� �Ҹ���" << endl;
	}

	void Say() {
		cout << "����Ʈ���� �۵��մϴ�" << endl;
	}
};

class Heart {
public:
	Heart() {
		cout << "Heart ������" << endl;
	}

	~Heart() {
		cout << "Heart �Ҹ���" << endl;
	}

	void Say() {
		cout << "������ �ݴϴ�" << endl;
	}

};

class Human {
private:
	Heart _heart;  //composition : ���Ե� ��ü�� �����ֱ⸦ ���� ��.���� ����

	SmartPhone& _smartPhone; //������ ����. agreeggation: ���Ե� ��ü�� �����ֱ⸦ �������� ����. ���Ѱ���

	Watch* _pWatch; //�������� ���� agreeggatio: ���Ե� ��ü�� �����ֱ⸦ ���� �Ѵ�.


public:
	Human(SmartPhone& ref)
		:_smartPhone(ref) {
		cout << "Human ������" << endl;
	}

	~Human() {
		cout << "Human �Ҹ���" << endl;
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
	
	
	cout << "���� ����" << endl;
	
	{
		Human human(phone);
		human.PlayHeartSound();
		human.PlayPhone();

		human.SetWatch(&redWatch);
		human.ShowWatch();

		human.SetWatch(&blueWatch);
		human.ShowWatch();

	}
	cout << "���� ��" << endl;
}