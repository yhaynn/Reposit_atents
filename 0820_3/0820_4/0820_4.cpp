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
    Point _pt1, _pt2;   //포함. 생명주기를 같이 한다. 강한 결합
                        //참조. 약한 결합
public:
    Line(int x1, int y1, int x2, int y2)
        : _pt1(x1, y1), _pt2(x2, y2) {}

    Line(Point pt1, Point pt2)
        : _pt1(pt1), _pt2(pt2) {}

    float GetLength() {
        //사선의 방정식
        return sqrt(pow(_pt2.GetX() - _pt1.GetX(), 2) + pow(_pt2.GetY() - _pt1.GetY(), 2));
    }
};

//숙제: 삼각형 클래스를 만들고 삼각형의 면적을 구하세요..(정삼각형 직각삼각형)
//사각형 클래스를 만들고 사각형의 면적을 구하세요..(정사각형,직사각형)
//원 클래스를 만들고 원의 면적을 구하세요.

class Rectangle {
private:
    Point _topLeftPT, _bottomRightPT;

public:
    Rectangle(Point topleftPT, Point bottomRightPT)
        :_topLeftPT(topleftPT), _bottomRightPT(bottomRightPT) {}

    Rectangle(int topx, int topy, int bottomx, int bottomy) 
    : _topLeftPT(topx, topy), _bottomRightPT(bottomx, bottomy) {}

    int GetArea() {
        int weight = _bottomRightPT.GetX() - _topLeftPT.GetX();
        int height = _bottomRightPT.GetY() - _topLeftPT.GetY();

        return weight * height;
    }


};

class Triangle {
private:
    Point _topPT, _leftPT, _rightPT;

public:
    Triangle(Point topPT, Point leftPT, Point rightPT)
        : _topPT(topPT), _leftPT(leftPT), _rightPT(rightPT) {}

    Triangle(int topx, int topy, int leftx, int lefty, int rightx, int righty)
        : _topPT(topx, topy), _leftPT(leftx, lefty), _rightPT(rightx, righty) {}

    float GetArea() {
        int base = _rightPT.GetX() - _leftPT.GetX();
        int height = _rightPT.GetY() - _topPT.GetY();

        return  base * height / 2;
    }
};


class Circle {
private:
    Point _centerPT;
    int _radius;
    const float PI = 3.14f;

public:
    Circle(Point centerPT, int radius)
        :_centerPT(centerPT), _radius(radius) {}

    float GetArea() {
        return PI * _radius * _radius;
    }
};


int main() {
    Line line(0, 0, 10, 10);
    cout << "line 길이는 " << line.GetLength() << endl;

    Rectangle rect(0, 0, 10, 10);
    cout << "rect area =" << rect.GetArea() << endl;

    Triangle tri( 0,0, 0, 5, 5,5);
    cout << "tri area =" << tri.GetArea() << endl;

    Circle cir(Point(10,10),5);
    cout << "circle area =" << cir.GetArea() << endl;
    return 0;
}