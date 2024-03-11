
#ifndef DECRATOR_HPP
#define DECRATOR_HPP

#include <iostream>

// 装饰者模式

class Base {
public:
    virtual ~Base() = default;
    virtual void show() = 0;
    virtual float cost() = 0;

    std::string m_str;
};


class Girl : public Base {
public:
    Girl() {
        m_str = "without anything";
    }
    ~Girl() = default;
    void show() override {
        std::cout << m_str << std::endl;
    }
    float cost() override {
        return 200.;
    }
};

class Decrator : public Base {
protected:
    Base* m_ptr;

public:
    virtual void show() = 0;
    virtual float cost() = 0;
};

class MiniSkirt : public Decrator {
public:
    // 不能使用初始化列表初始化ptr
    // 因为这里不确定父类的ptr是否是const的，
    // 如果是const的，则在父类中已经初始化了，这里不会允许再次初始化
    MiniSkirt(Base* ptr) {
        m_ptr = ptr;
    }
    ~MiniSkirt() = default;
    void show() override {
        m_ptr->show();
        std::cout << "add mini skirt" << std::endl;
    }
    float cost() override {
        return 50.0 + m_ptr->cost();
    }
};

class BlackSilk : public Decrator {
public:
    BlackSilk(Base* ptr) {
        m_ptr = ptr;
    }
    ~BlackSilk() = default;
    void show() override {
        m_ptr->show();
        std::cout << "add black silk" << std::endl;
    }
    float cost() override {
        return 100.0 + m_ptr->cost();
    }
};

#endif