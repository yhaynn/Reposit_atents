#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
    int _x, _y;

public:
    Point(int x, int y)
        : _x(x), _y(y) {}

    int GetX() {
        return _x;
    }

    int GetY() {
        return _y;
    }

    void info() {
        cout << "x: " << _x << endl;
        cout << "y: " << _y << endl << endl;
    }
};

class Line {
private:
    Point _pt1, _pt2;   //����. �����ֱ⸦ ���� �Ѵ�. ���� ����
                        //����. ���� ����
public:
    Line(int x1, int y1, int x2, int y2)
        : _pt1(x1, y1), _pt2(x2, y2) {}

    Line(Point pt1, Point pt2)
        : _pt1(pt1), _pt2(pt2) {}

    float GetLength() {
        //�缱�� ������
        return sqrt(pow(_pt2.GetX() - _pt1.GetX(), 2) + pow(_pt2.GetY() - _pt1.GetY(), 2));
    }
};

//����: �ﰢ�� Ŭ������ ����� �ﰢ���� ������ ���ϼ���..(���ﰢ�� �����ﰢ��)
//�簢�� Ŭ������ ����� �簢���� ������ ���ϼ���..(���簢��,���簢��)
//�� Ŭ������ ����� ���� ������ ���ϼ���.


int main() {
    Line line(0, 0, 10, 10);
    cout << "line ���̴� " << line.GetLength() << endl;


    return 0;
}