#include <iostream>

using namespace std;

//다형성. A가 B에 함수를 호출할때 다양한 값이 나타날수 있는것.
//오버로딩 - 부모의 가살함수에 자식의 가상함수가 덮어쓰는것
//오버라이딩 - 부모의 가상함수를 자식이 똑같은 가상함수를 만드는것


//프로그래머
//커피숖 관리 프로그램을 개발 의뢰 받았습니다.
//숖 안에 역할 분석: Cashier, Barista, Guest

//


class Coffee {
    string _name;

public:
    Coffee()
        : _name("Coffee") {}

    string GetName() {
        return _name;
    }
};

class Latte {
    string _name;

public:
    Latte()
        : _name("Latte") {}

    string GetName() {
        return _name;
    }

};

class Barista {
public:
    void MakeADrink(Coffee& drink) {
        cout << drink.GetName() << "를 만듭니다." << endl;
    }

    void MakeADrink(Latte& drink) {
        cout << drink.GetName() << "를 만듭니다." << endl;
    }
};

class Cashier {
private:
    Barista& bari;
public:
    Cashier(Barista& ref)
        : bari(ref) {}
    void OrderedDrink(Coffee& drink) {
        cout << drink.GetName() << "주문 을 받습니다." << endl;
        cout << drink.GetName() << " 음료 오더를 보냅니다." << endl;
        bari.MakeADrink(drink);
    }

    void OrderedDrink(Latte& drink) {
        cout << drink.GetName() << "주문 을 받습니다." << endl;
        cout << drink.GetName() << " 음료 오더를 보냅니다." << endl;
        bari.MakeADrink(drink);
    }

};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Coffee& drink) { // 의존적 관계(일시적인 관계)
        cout << drink.GetName() << "를 주문합니다." << endl;
        ref.OrderedDrink(drink);
    }

    void OrderingDrink(Cashier& ref, Latte& drink) { // 의존적 관계(일시적인 관계)
        cout << drink.GetName() << "를 주문합니다." << endl;
        ref.OrderedDrink(drink);
    }

};



int main() {
    Guest guest;
    Barista bari;
    Cashier cashier(bari);

    Coffee coffee;
    Latte latte;

    guest.OrderingDrink(cashier, coffee);

    guest.OrderingDrink(cashier, latte);


    return 0;
}