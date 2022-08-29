#include <iostream>

using namespace std;

class Arm {
private:
    string _name;
public:
    Arm(string name)
        : _name(name) {}

    void info() {
        cout << _name << endl;
    }
};

class RocketArm : public Arm {
public:
    RocketArm()
        : Arm("RocketArm") {}
    void info() {
        cout << "RocketArm" << endl;
    }
};

class CannonArm : public Arm {

public:
    CannonArm()
        : Arm("CannonArm") {}

    void info() {
        cout << "CannonArm" << endl;
    }
};

class LazerArm : public Arm {
public:
    LazerArm()
        : Arm("LazerArm") {}

    void info() {
        cout << "LazerArm" << endl;
    }
};

class BombArm : public Arm {
public:
    BombArm()
        : Arm("BombArm") {}

    void info() {
        cout << "BombArm" << endl;
    }
};

class Robot {
private:
    Arm* _leftArm;
    Arm* _rightArm;

public:
    Robot(Arm* leftArm, Arm* rightArm)
        : _leftArm(leftArm), _rightArm(rightArm) {}

    void SetLeftArm(Arm* arm) {
        _leftArm = arm;
    }

    void SetRightArm(Arm* arm) {
        _rightArm = arm;
    }

    void info() {
        cout << "LeftArm: ";
        _leftArm->info();
        cout << "RightArm: ";
        _rightArm->info();
        cout << endl;
    }
};



int main() {
    CannonArm cannonArm;
    RocketArm rocketArm;
    LazerArm lazerArm;
    BombArm bombArm;

    Robot rocketArmRobot(&rocketArm, &rocketArm);
    rocketArmRobot.info();

    Robot cannonArmRobot(&cannonArm, &cannonArm);
    cannonArmRobot.info();

    Robot lcrrRobot(&cannonArm, &rocketArm);
    lcrrRobot.info();

    Robot lazerArmRobot(&lazerArm, &lazerArm);
    lazerArmRobot.info();

    lazerArmRobot.SetLeftArm(&rocketArm);
    lazerArmRobot.info();

    Robot bombArmRobot(&bombArm, &bombArm);
    bombArmRobot.info();


    return 0;
}