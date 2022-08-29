///일반화 프로그래밍
///standard template library
///#include <list>


//#include <iostream>
//
//using namespace std;
//
//class DynamicArray {
//private:
//    int* _arr;
//    int _size;
//
//public:
//    DynamicArray(int size) {
//        _arr = new int[size];
//        _size = size;
//    }
//
//    ~DynamicArray() {
//        delete[] _arr;
//    }
//
//    int& operator[](int index) {
//        return _arr[index];
//    }
//
//    int GetSize() {
//        return _size;
//    }
//
//};
//
//class FloatDynamicArray {
//private:
//    float* _arr;
//    int _size;
//
//public:
//    FloatDynamicArray(int size) {
//        _arr = new float[size];
//        _size = size;
//    }
//
//    ~FloatDynamicArray() {
//        delete[] _arr;
//    }
//
//    float& operator[](int index) {
//        return _arr[index];
//    }
//
//    int GetSize() {
//        return _size;
//    }
//
//};
//
//int main() {
//    DynamicArray array(10);
//
//    for (int i = 0; i < array.GetSize(); i++) {
//        array[i] = i;
//    }
//
//    for (int i = 0; i < array.GetSize(); i++) {
//        cout << "array[" << i << "]= " << array[i] << endl;
//    }
//
//    FloatDynamicArray array2(10);
//
//    for (int i = 0; i < array2.GetSize(); i++) {
//        array2[i] = i * 1.2f;
//    }
//
//    for (int i = 0; i < array2.GetSize(); i++) {
//        cout << "array2[" << i << "]= " << array2[i] << endl;
//    }
//
//}

#include <iostream>
#include <list>

using namespace std;

class Student {
public:
    int _age;
    int _grade;
};

template <typename T>
class DynamicArray {
private:
    T* _arr;
    int _size;

public:
    DynamicArray(int size) {
        _arr = new T[size];
        _size = size;
    }

    ~DynamicArray() {
        delete[] _arr;
    }

    T& operator[](int index) {
        return _arr[index];
    }

    int GetSize() {
        return _size;
    }

};


int main() {
    DynamicArray<int> array(10);

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = i;
    }

    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "]= " << array[i] << endl;
    }

    cout << endl;

    DynamicArray<float> array2(10);
    for (int i = 0; i < array2.GetSize(); i++) {
        array2[i] = i * 2.3f;
    }

    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "]= " << array2[i] << endl;
    }

    cout << endl;
    DynamicArray<Student> array3(10);
    for (int i = 0; i < array3.GetSize(); i++) {
        array3[i]._age = i;
        array3[i]._grade = i % 3 + 1;
    }

    for (int i = 0; i < array3.GetSize(); i++) {
        cout << "array3[" << i << "]._age = " << array3[i]._age << endl;
        cout << "array3[" << i << "]._grade = " << array3[i]._grade << endl << endl;
    }

    auto a = 100;   // 타입유추

    // STL
    list<int> intlist;


    for (int i = 0; i < 10; i++) {
        intlist.push_back(i);
    }

    for (auto obj : intlist) {
        cout << obj << endl;

    }



}