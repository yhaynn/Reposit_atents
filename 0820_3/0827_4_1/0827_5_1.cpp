////#include <iostream>
////#include <string>
////
////using namespace std;
////
////// ���α׷���
////// Ŀ�Ǚ� �������α׷��� ���� �Ƿ� �޾ҽ��ϴ�.
////
////// Cashier, Barista, guest, 
////
////class Drink {
////private:
////    string _name;
////    int _type;
////
////public:
////    Drink(string name, int type)
////        : _name(name), _type(type) {}
////
////    string GetName() {
////        return _name;
////    }
////
////    int GetType() {
////        return _type;
////    }
////};
////
////
////class Coffee : public Drink {
////public:
////    Coffee()
////        : Drink("Coffee", 0) {}
////};
////
////class Latte : public Drink {
////public:
////    Latte()
////        : Drink("Latte", 1) {}
////};
////
////class Cola : public Drink {
////public:
////    Cola()
////        : Drink("Cola", 2) {}
////};
////
////class Barista {
////public:
////    void MakeADrink(Drink& drink) {
////
////        switch (drink.GetType()) {
////        case 0:
////            break;
////
////        case 1:
////            break;
////
////        case 2:
////            break;
////        }
////
////        cout << drink.GetName() << "�� ����ϴ�." << endl;
////    }
////};
////
////class Cashier {
////private:
////    Barista& bari;
////public:
////    Cashier(Barista& ref)
////        : bari(ref) {}
////
////    void OrderedDrink(Drink& drink) {
////        cout << drink.GetName() << "�ֹ� �� �޽��ϴ�." << endl;
////        cout << drink.GetName() << " ���� ������ �����ϴ�." << endl;
////        bari.MakeADrink(drink);
////    }
////};
////
////class Guest {
////public:
////    void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(�Ͻ����� ����)
////        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
////        ref.OrderedDrink(drink);
////    }
////};
////
////
////
////int main() {
////    Guest guest;
////    Barista bari;
////    Cashier cashier(bari);
////
////    Coffee coffee;
////    Latte latte;
////    Cola cola;
////
////    guest.OrderingDrink(cashier, coffee);
////    cout << endl;
////    guest.OrderingDrink(cashier, latte);
////    cout << endl;
////    guest.OrderingDrink(cashier, cola);
////
////
////
////    return 0;
////}
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Drink {
//private:
//    string _name;
//
//
//public:
//    Drink(string name)
//        : _name(name) {}
//
//    string GetName() {
//        return _name;
//    }
//
//    virtual void MakeADrink() {
//        cout << "���Ḧ ����ϴ�." << endl;
//    }
//
//};
//
//
//class Coffee : public Drink {
//public:
//    Coffee()
//        : Drink("Coffee") {}
//
//    void MakeADrink() {
//        cout << "Ŀ�Ǹ� ����ϴ�." << endl;
//    }
//};
//
//class Latte : public Drink {
//public:
//    Latte()
//        : Drink("Latte") {}
//
//    void MakeADrink() {
//        cout << "�󶼸� ����ϴ�." << endl;
//    }
//};
//
//class Cola : public Drink {
//public:
//    Cola()
//        : Drink("Cola") {}
//
//    void MakeADrink() {
//        cout << "�ݶ� ����ϴ�." << endl;
//    }
//};
//
//class Barista {
//public:
//    void MakeADrink(Drink& drink) {
//        cout << drink.GetName() << "�� ������ �����մϴ�." << endl;
//        drink.MakeADrink();
//    }
//};
//
//class Cashier {
//private:
//    Barista& bari;
//public:
//    Cashier(Barista& ref)
//        : bari(ref) {}
//
//    void OrderedDrink(Drink& drink) {
//        cout << drink.GetName() << "�ֹ� �� �޽��ϴ�." << endl;
//        cout << drink.GetName() << " ���� ������ �����ϴ�." << endl;
//        bari.MakeADrink(drink);
//    }
//};
//
//class Guest {
//public:
//    void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(�Ͻ����� ����)
//        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
//        ref.OrderedDrink(drink);
//    }
//};
//
//
//
//int main() {
//    Guest guest;
//    Barista bari;
//    Cashier cashier(bari);
//
//    Coffee coffee;
//    Latte latte;
//    Cola cola;
//
//    guest.OrderingDrink(cashier, coffee);
//    cout << endl;
//    guest.OrderingDrink(cashier, latte);
//    cout << endl;
//    guest.OrderingDrink(cashier, cola);
//
//
//
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

class Drink {
private:
    string _name;

public:
    Drink(string name)
        : _name(name) {}

    string GetName() {
        return _name;
    }

    virtual void MakeADrink() {   // �����Լ�
        cout << "���Ḧ ����ϴ�." << endl;
    }

};


class Coffee : public Drink {
public:
    Coffee()
        : Drink("Coffee") {}

    void MakeADrink() override {
        cout << "Ŀ�Ǹ� ����ϴ�." << endl;
    }
};

class Latte : public Drink {
public:
    Latte()
        : Drink("Latte") {}

    void MakeADrink() override {
        cout << "�󶼸� ����ϴ�." << endl;
    }
};

class Cola : public Drink {
public:
    Cola()
        : Drink("Cola") {}

    void MakeADrink() override {
        cout << "�ݶ� ����ϴ�." << endl;
    }
};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << drink.GetName() << "�� ������ �����մϴ�." << endl;
        drink.MakeADrink();
    }
};

class Cashier {
private:
    Barista& bari;
public:
    Cashier(Barista& ref)
        : bari(ref) {}

    void OrderedDrink(Drink& drink) {
        cout << drink.GetName() << "�ֹ� �� �޽��ϴ�." << endl;
        cout << drink.GetName() << " ���� ������ �����ϴ�." << endl;
        bari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(�Ͻ����� ����)
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
    Cola cola;

    guest.OrderingDrink(cashier, coffee);
    cout << endl;
    guest.OrderingDrink(cashier, latte);
    cout << endl;
    guest.OrderingDrink(cashier, cola);



    return 0;
}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// ���α׷���
//// Ŀ�Ǚ� �������α׷��� ���� �Ƿ� �޾ҽ��ϴ�.
//
//// Cashier, Barista, guest, 
//
//// ���������Լ��� �ϳ��� ������ �ִ� Ŭ������ �߻�Ŭ������� �մϴ�.
////���������Լ��� �ڱ⸦ ��� �޴� Ŭ�������� ������ �θ��� ���� ���� �Լ��� ������ �Ѵ�
//class Drink {
//private:
//    string _name;
//
//public:
//    Drink(string name)
//        : _name(name) {}
//
//    string GetName() {
//        return _name;
//    }
//
//    virtual void MakeADrink() = 0; // ���������Լ�
//};
//
//
//class Coffee : public Drink {
//public:
//    Coffee()
//        : Drink("Coffee") {}
//
//    void MakeADrink() override {
//        cout << "Ŀ�Ǹ� ����ϴ�." << endl;
//    }
//};
//
//class Latte : public Drink {
//public:
//    Latte()
//        : Drink("Latte") {}
//
//    void MakeADrink() override {
//        cout << "�󶼸� ����ϴ�." << endl;
//    }
//};
//
//class Cola : public Drink {
//public:
//    Cola()
//        : Drink("Cola") {}
//
//    void MakeADrink() override {
//        cout << "�ݶ� ����ϴ�." << endl;
//    }
//};
//
//class Aid : public Drink {
//public:
//    Aid()
//        : Drink("Aid") {}
//
//    void MakeADrink() override {
//        cout << "Aid�� ����ϴ�." << endl;
//    }
//};
//
//class Barista {
//public:
//    void MakeADrink(Drink& drink) {
//        cout << drink.GetName() << "�� ������ �����մϴ�." << endl;
//        drink.MakeADrink();
//    }
//};
//
//class Cashier {
//private:
//    Barista& bari;
//public:
//    Cashier(Barista& ref)
//        : bari(ref) {}
//
//    void OrderedDrink(Drink& drink) {
//        cout << drink.GetName() << "�ֹ� �� �޽��ϴ�." << endl;
//        cout << drink.GetName() << " ���� ������ �����ϴ�." << endl;
//        bari.MakeADrink(drink);
//    }
//};
//
//class Guest {
//public:
//    void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(�Ͻ����� ����)
//        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
//        ref.OrderedDrink(drink);
//    }
//};
//
//
//
//int main() {
//    Guest guest;
//    Barista bari;
//    Cashier cashier(bari);
//
//    Coffee coffee;
//    Latte latte;
//    Cola cola;
//    Aid aid;
//
//    guest.OrderingDrink(cashier, coffee);
//    cout << endl;
//    guest.OrderingDrink(cashier, latte);
//    cout << endl;
//    guest.OrderingDrink(cashier, cola);
//    cout << endl;
//    guest.OrderingDrink(cashier, aid);
//
//
//    return 0;
//}