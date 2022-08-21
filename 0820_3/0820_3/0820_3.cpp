#include <iostream>
#include <string>

using namespace std;

//상속
//(일반화/특수화)
//일반화:공통된 부분을 부모클래스로 올리고 다른 클래스에 적용
//특수화:역으로 특수한 클래스를 내려 자식 클래스를 만든다


//동물 농장 시뮬레이션
//돼지,소,닭

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
		cout << _name << "이 뜁니다." << endl;

	}

	void Eat() {
		cout << _name << "이 먹습니다." << endl;
	}

	void info() {
		cout << "이름: " << _name << endl;
		cout << "나이: " << _age << endl;
		cout << "무게: " << _weight << endl;
		cout << "키: " << _height << endl;
	}
};

class Pig : public Stock{



public:
	Pig(string name, float age, float weight, float height)
		: Stock (name,age,weight,height) {}

	void Speak()
	{
		cout << _name << "이 꿀꿀합니다." << endl;
	}
	
	
};

class Cow : public Stock{


public:
	Cow(string name, float age, float weight, float height)
		: Stock(name, age, weight, height) {}

	void Speak()
	{
		cout << _name << "이 음머합니다." << endl;
	}

	};


class Chicken:public Stock {
private:

	bool _isFly;

	void Fly() {
		cout << _name << "이 납니다." << endl;
	}

public:
	Chicken(string name, float age, float weight, float height, bool isFly)
		: Stock(name, age, weight, height,isFly) {}

	void Speak()
	{
		cout << _name << "이 꼬끼오합니다." << endl;
	}

	void Run() {
		if (_isFly) {
			Fly();
		}

		else {
			cout << _name << "이 뜁니다." << endl;
		}
		

	}

	
	void info() {
		Stock::info();
		if (_isFly) {
			cout << "종류: 나는 닭" << endl;
		}
		else {
			cout << "종류: 못나는 닭" << endl;
		}

	}
};




class Horse {

};
int main() {

	Cow cow("소", 2.2f, 200.0f, 1.5f);
	Pig pig("돼지", 2.5f, 150.0f, 1.3f);
	Chicken flyChicken("나는닭", 0.5f, 2.5f, 0.3f, true);
	Chicken notFlyChicken("못나는닭", 0.5f, 2.5f, 0.3f, false);

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