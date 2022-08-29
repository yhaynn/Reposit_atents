#include <iostream>

using namespace std;

//������. A�� B�� �Լ��� ȣ���Ҷ� �پ��� ���� ��Ÿ���� �ִ°�.
//�����ε� - �θ��� �����Լ��� �ڽ��� �����Լ��� ����°�
//�������̵� - �θ��� �����Լ��� �ڽ��� �Ȱ��� �����Լ��� ����°�


//���α׷���
//Ŀ�Ǚ� ���� ���α׷��� ���� �Ƿ� �޾ҽ��ϴ�.
//�� �ȿ� ���� �м�: Cashier, Barista, Guest

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
        cout << drink.GetName() << "�� ����ϴ�." << endl;
    }

    void MakeADrink(Latte& drink) {
        cout << drink.GetName() << "�� ����ϴ�." << endl;
    }
};

class Cashier {
private:
    Barista& bari;
public:
    Cashier(Barista& ref)
        : bari(ref) {}
    void OrderedDrink(Coffee& drink) {
        cout << drink.GetName() << "�ֹ� �� �޽��ϴ�." << endl;
        cout << drink.GetName() << " ���� ������ �����ϴ�." << endl;
        bari.MakeADrink(drink);
    }

    void OrderedDrink(Latte& drink) {
        cout << drink.GetName() << "�ֹ� �� �޽��ϴ�." << endl;
        cout << drink.GetName() << " ���� ������ �����ϴ�." << endl;
        bari.MakeADrink(drink);
    }

};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Coffee& drink) { // ������ ����(�Ͻ����� ����)
        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
        ref.OrderedDrink(drink);
    }

    void OrderingDrink(Cashier& ref, Latte& drink) { // ������ ����(�Ͻ����� ����)
        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
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