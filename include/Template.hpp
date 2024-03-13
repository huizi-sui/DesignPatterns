#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

// 模板模式： 一种行为设计模式，定义了一个算的骨架，将一些步骤的具体实现延迟
// 到子类中。模板模式使得子类可以在不改变算法结构的情况下重新定义某些步骤的具体实现。

#include <iostream>

class AbstractClass {
public:
    void template_method() {
        step1();
        step2();
        step3();
    }
    virtual ~AbstractClass() = default;

protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};

// 具体子类1
class Class1 : public AbstractClass {
protected:
    void step1() override {
        std::cout << "Class1 step1" << std::endl;
    }

    void step2() override {
        std::cout << "Class1 step2" << std::endl;
    }

    void step3() override {
        std::cout << "Class1 step3" << std::endl;
    }
};

// 具体子类2
class Class2 : public AbstractClass {
protected:
    void step1() override {
        std::cout << "Class2 step1" << std::endl;
    }

    void step2() override {
        std::cout << "Class2 step2" << std::endl;
    }

    void step3() override {
        std::cout << "Class2 step3" << std::endl;
    }
};


#endif