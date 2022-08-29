#include <iostream>

using namespace std;

class A {
public:
    void PrintMessage() {                   //일반함수
        cout << "A::PrintMessage" << endl;
    }

    virtual void PrintInfo() {              //가상함수
        cout << "A::PrintInfo" << endl;
    }

    virtual void PrintInfo2() {
        cout << "A::PrintInfo2" << endl;
    }

};

class B : public A {
public:
    void PrintMessage() {                   //일반 함수.새롭게 만든 일반함수
        cout << "B::PrintMessage" << endl;
    }

    virtual void PrintInfo() override {     //가상함수 :부모의 가상함수를 자식이 재정의
        cout << "B::PrintInfo" << endl;
    }
};

class C : public A {
public:
    void PrintMessage() {
        cout << "C::PrintMessage" << endl;
    }


    virtual void PrintInfo2() override {    //가상함수
        cout << "C::PrintInfo2" << endl;
    }

};

void ExcutePrintMessage(A& ref) {           
    ref.PrintMessage();                     //일반함수는 ref의 변수 타입에 준해서 작동
    ref.A::PrintMessage();                     //정적바인딩
}

void ExcutePrintInfo(A& ref) {              //가상함수
    ref.PrintInfo();                        //어느 객체의 함수가 호출될지 정할 수 없어서 함수 호출이 유보
                                            //동적바인딩: 실행중에 어디에 함수가 호출될 지 결정되는것

    //ref.__vfptr[0]();                     //가상함수 테이블이 알아서 만들어짐
}

void ExcutePrintInfo2(A& ref) {
    ref.PrintInfo2();
}

int main() {
    A a;
    B b;
    C c;

    cout << "일반함수" << endl;
    ExcutePrintMessage(a);
    ExcutePrintMessage(b);
    ExcutePrintMessage(c);

    cout << endl;
    cout << "가상함수" << endl;
    ExcutePrintInfo(a);
    ExcutePrintInfo(b);
    ExcutePrintInfo(c);



    return 0;
}