#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
	string _name;
	float _age;
	float _weight;
	float _height;
	

public:
	Animal(string name, float age, float weight, float hieght)
		:_name(name), _age(age), _weight(weight), _height(_height) {}


	void Speak() {
		cout << _name << "�� ���մϴ�." << endl;
		}

	void Eat() {
		cout << _name << "�� �Խ��ϴ�." << endl;
		}

	void Run() {
		cout << _name << "�� �ݴϴ�." << endl;
	}
	
	void Info() {
		cout << "�̸�: " << _name << endl;
		cout << "����: " << _age << endl;
		cout << "����: " << _weight << endl;
		cout << "Ű: " << _height << endl;
	}
};


class Pig : public Animal {
public:
	Pig(string name, float age, float weight, float height)
		: Animal(name, age, weight, height) {}
};

class Cow : public Animal {
public:
	Cow(string name, float age, float weight, float height)
		: Animal(name, age, weight, height) {}
};

class Chicken : public Animal {
public:
	Chicken(string name, float age, float weight, float height,bool _isFly)
		: Animal(name, age, weight, height) {}
};

int main() {
	Cow cow("��", 1.2f, 230.0f, 1.8f);
	Pig pig("����", 1.2f, 230.0f, 1.8f);
	Chicken notFlyChicken("������ ��", 1.2f, 230.0f, 1.8f, false);
	Chicken FlyChicken("���� ��", 1.2f, 230.0f, 1.8f, true);

	cow.Speak();
	cow.Run();

	cout << endl;

	pig.Speak();
	pig.Run();

	cout << endl;

	notFlyChicken.Speak();
	notFlyChicken.Run();

	cout << endl;
	FlyChicken.Speak();
	FlyChicken.Run();


	return 0;
}