
#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include <iostream>

class CallCar;

class Interface {
public:
    virtual void run() = 0;
    Interface() : call_car(nullptr) {}
    Interface(CallCar* car) : call_car(car) {}
    virtual ~Interface() {
        delete call_car;
    }

protected:
    CallCar* call_car;
};

class CallCar {
public:
    virtual void call() = 0;
    virtual ~CallCar() = default;
};


class ReinterFaceUber : public Interface {
public:
    ReinterFaceUber(CallCar* car) : Interface(car) {}

    void run() override {
        // 通常这里会做更多操作，如业务逻辑判断等
        std::cout << "ReInterface" << std::endl;
        call_car->call();
    }
};

class Cab : public CallCar {
public:
    void call() override {
        std::cout << "Cab" << std::endl;
    }
};

class Uber : public CallCar {
public:
    void call() override {
        std::cout << "Uber" << std::endl;
    }
};



#endif