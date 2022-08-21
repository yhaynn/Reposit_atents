#include <iostream>
#include <string>

using namespace std;

//���
//(�Ϲ�ȭ/Ư��ȭ)
//�Ϲ�ȭ:����� �κ��� �θ�Ŭ������ �ø��� �ٸ� Ŭ������ ����
//Ư��ȭ:������ Ư���� Ŭ������ ���� �ڽ� Ŭ������ �����


//���� ���� �ùķ��̼�
//����,��,��

class Stock {
protected:
	string _name;
	float _age;
	float _weight;
	float _height;


public:
	Stock(string name, float age, float weight, float height)
		: _name(name), _age(age), _weight(weight), _height(height) {}

public:
	void Run() {
		cout << _name << "�� �ݴϴ�." << endl;

	}

	void Eat() {
		cout << _name << "�� �Խ��ϴ�." << endl;
	}

	void info() {
		cout << "�̸�: " << _name << endl;
		cout << "����: " << _age << endl;
		cout << "����: " << _weight << endl;
		cout << "Ű: " << _height << endl;
	}
};

class Pig : public Stock{



public:
	Pig(string name, float age, float weight, float height)
		: Stock (name,age,weight,height) {}

	void Speak()
	{
		cout << _name << "�� �ܲ��մϴ�." << endl;
	}
	
	
};

class Cow : public Stock{


public:
	Cow(string name, float age, float weight, float height)
		: Stock(name, age, weight, height) {}

	void Speak()
	{
		cout << _name << "�� �����մϴ�." << endl;
	}

	};


class Chicken:public Stock {
private:

	bool _isFly;

	void Fly() {
		cout << _name << "�� ���ϴ�." << endl;
	}

public:
	Chicken(string name, float age, float weight, float height, bool isFly)
		: Stock(name, age, weight, height,isFly) {}

	void Speak()
	{
		cout << _name << "�� �������մϴ�." << endl;
	}

	void Run() {
		if (_isFly) {
			Fly();
		}

		else {
			cout << _name << "�� �ݴϴ�." << endl;
		}
		

	}

	
	void info() {
		Stock::info();
		if (_isFly) {
			cout << "����: ���� ��" << endl;
		}
		else {
			cout << "����: ������ ��" << endl;
		}

	}
};




class Horse {

};
int main() {

	Cow cow("��", 2.2f, 200.0f, 1.5f);
	Pig pig("����", 2.5f, 150.0f, 1.3f);
	Chicken flyChicken("���´�", 0.5f, 2.5f, 0.3f, true);
	Chicken notFlyChicken("�����´�", 0.5f, 2.5f, 0.3f, false);

	cow.Speak();
	cow.Run();

	cout << endl;

	pig.Speak();
	pig.Run();

	cout << endl;

	flyChicken.Speak();
	flyChicken.Run();

	cout << endl;

	notFlyChicken.Speak();
	notFlyChicken.Run();

	return 0;
}