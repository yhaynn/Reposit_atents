#include <iostream>

using namespace std;



class RocketArm {
public:
    void info() {
        cout << "RocketArm" << endl;
    }
};

class CannonArm {
public:
    void info() {
        cout << "CannonArm" << endl;
    }
};

class RocketArmRobot {
private:
    RocketArm _leftArm, _rightArm;

public:
    RocketArmRobot() {

    }

    ~RocketArmRobot() {

    }

    void info() {
        cout << "LeftArm: ";
        _leftArm.info();
        cout << "RightArm: ";
        _rightArm.info();
        cout << endl;
    }

};

class CannonArmRobot {
private:
    CannonArm& _leftArm; //������ ����
    CannonArm& _rightArm;

public:
    CannonArmRobot(CannonArm& leftArm, CannonArm& rightArm) //
        : _leftArm(leftArm), _rightArm(rightArm) {}

    void info() {
        cout << "LeftArm: ";
        _leftArm.info();
        cout << "RightArm: ";
        _rightArm.info();
        cout << endl;
    }
};

class LeftCannonArmRightRocketArmRobot {
private:
    CannonArm& _leftArm;
    RocketArm& _rightArm;

public:
    LeftCannonArmRightRocketArmRobot(CannonArm& leftArm, RocketArm& rightArm)
        : _leftArm(leftArm), _rightArm(rightArm) {}

    void info() {
        cout << "LeftArm: ";
        _leftArm.info();
        cout << "RightArm: ";
        _rightArm.info();
        cout << endl;
    }
};



int main() {
    CannonArm cannonArm; //CannonArm �̶� �Լ��� cannonArm�̶� ���ڷ� ����
    RocketArm rocketArm; 

    RocketArmRobot rocketArmRobot;
    rocketArmRobot.info();

    CannonArmRobot cannonArmRobot(cannonArm, cannonArm);
    cannonArmRobot.info();

    LeftCannonArmRightRocketArmRobot lcrrRobot(cannonArm, rocketArm); //�� ����� �ȵɱ�
    lcrrRobot.info();

   
    return 0;
}