
#ifndef FACADE_HPP
#define FACADE_HPP

// Facade: 外观模式，是一种结构型设计模式，提供一个简单的接口
// 隐藏了一组复杂的子系统，使客户端可以方便地使用这些子系统

// Facade封装一组复杂子系统，并提供一个简单的接口供客户端使用。
// 这个接口可以隐藏子系统的复杂性，使得客户端无需了解子系统的内部实现细节，
// 也无需直接与子系统交互，降低了系统的耦合性。

#include <iostream>

class SystemA {
public:
    void operationA() {
        std::cout << "SystemA operation" << std::endl;
    }
};

class SystemB {
public:
    void operationB() {
        std::cout << "SystemB operation" << std::endl;
    }
};

// 外观类
class Facade {
public:
    void operation() {
        m_systemA.operationA();
        m_systemB.operationB();
    }
private:
    SystemA m_systemA;
    SystemB m_systemB;
};


#endif