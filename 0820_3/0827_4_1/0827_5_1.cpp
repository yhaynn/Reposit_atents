////#include <iostream>
////#include <string>
////
////using namespace std;
////
////// 프로그래머
////// 커피숖 관리프로그램을 개발 의뢰 받았습니다.
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
////        cout << drink.GetName() << "를 만듭니다." << endl;
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
////        cout << drink.GetName() << "주문 을 받습니다." << endl;
////        cout << drink.GetName() << " 음료 오더를 보냅니다." << endl;
////        bari.MakeADrink(drink);
////    }
////};
////
////class Guest {
////public:
////    void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적 관계(일시적인 관계)
////        cout << drink.GetName() << "를 주문합니다." << endl;
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
//        cout << "음료를 만듭니다." << endl;
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
//        cout << "커피를 만듭니다." << endl;
//    }
//};
//
//class Latte : public Drink {
//public:
//    Latte()
//        : Drink("Latte") {}
//
//    void MakeADrink() {
//        cout << "라떼를 만듭니다." << endl;
//    }
//};
//
//class Cola : public Drink {
//public:
//    Cola()
//        : Drink("Cola") {}
//
//    void MakeADrink() {
//        cout << "콜라를 만듭니다." << endl;
//    }
//};
//
//class Barista {
//public:
//    void MakeADrink(Drink& drink) {
//        cout << drink.GetName() << "를 제작을 지시합니다." << endl;
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
//        cout << drink.GetName() << "주문 을 받습니다." << endl;
//        cout << drink.GetName() << " 음료 오더를 보냅니다." << endl;
//        bari.MakeADrink(drink);
//    }
//};
//
//class Guest {
//public:
//    void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적 관계(일시적인 관계)
//        cout << drink.GetName() << "를 주문합니다." << endl;
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

    virtual void MakeADrink() {   // 가상함수
        cout << "음료를 만듭니다." << endl;
    }

};


class Coffee : public Drink {
public:
    Coffee()
        : Drink("Coffee") {}

    void MakeADrink() override {
        cout << "커피를 만듭니다." << endl;
    }
};

class Latte : public Drink {
public:
    Latte()
        : Drink("Latte") {}

    void MakeADrink() override {
        cout << "라떼를 만듭니다." << endl;
    }
};

class Cola : public Drink {
public:
    Cola()
        : Drink("Cola") {}

    void MakeADrink() override {
        cout << "콜라를 만듭니다." << endl;
    }
};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << drink.GetName() << "를 제작을 지시합니다." << endl;
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
        cout << drink.GetName() << "주문 을 받습니다." << endl;
        cout << drink.GetName() << " 음료 오더를 보냅니다." << endl;
        bari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적 관계(일시적인 관계)
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
//// 프로그래머
//// 커피숖 관리프로그램을 개발 의뢰 받았습니다.
//
//// Cashier, Barista, guest, 
//
//// 순수가상함수를 하나라도 가지고 있는 클래스를 추상클래스라고 합니다.
////순수가상함수는 자기를 상속 받는 클래스들을 무조건 부모의 순수 가상 함수를 따르게 한다
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
//    virtual void MakeADrink() = 0; // 순수가상함수
//};
//
//
//class Coffee : public Drink {
//public:
//    Coffee()
//        : Drink("Coffee") {}
//
//    void MakeADrink() override {
//        cout << "커피를 만듭니다." << endl;
//    }
//};
//
//class Latte : public Drink {
//public:
//    Latte()
//        : Drink("Latte") {}
//
//    void MakeADrink() override {
//        cout << "라떼를 만듭니다." << endl;
//    }
//};
//
//class Cola : public Drink {
//public:
//    Cola()
//        : Drink("Cola") {}
//
//    void MakeADrink() override {
//        cout << "콜라를 만듭니다." << endl;
//    }
//};
//
//class Aid : public Drink {
//public:
//    Aid()
//        : Drink("Aid") {}
//
//    void MakeADrink() override {
//        cout << "Aid를 만듭니다." << endl;
//    }
//};
//
//class Barista {
//public:
//    void MakeADrink(Drink& drink) {
//        cout << drink.GetName() << "를 제작을 지시합니다." << endl;
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
//        cout << drink.GetName() << "주문 을 받습니다." << endl;
//        cout << drink.GetName() << " 음료 오더를 보냅니다." << endl;
//        bari.MakeADrink(drink);
//    }
//};
//
//class Guest {
//public:
//    void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적 관계(일시적인 관계)
//        cout << drink.GetName() << "를 주문합니다." << endl;
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