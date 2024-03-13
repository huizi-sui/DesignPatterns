
#ifndef PROXY_HPP
#define PROXY_HPP

// Proxy: 代理模式，一种结构型设计模式
// 提供一个代理对象来控制对另一个对象的访问。
// 代理对象与被代理对象具有相同的接口，客户端通过代理对象访问被代理对象

// 实现对被代理类的保护和控制

#include <iostream>
#include <memory>

// 接口
class Subject {
public:
    virtual void request() = 0;
    virtual ~Subject() = default;
};

// 被代理的对象
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject request" << std::endl;
    }
};

// 代理
class Proxy : public Subject {
public:
    Proxy();
    ~Proxy() override = default;
    void request() override;
private:
    std::shared_ptr<RealSubject> m_real_subject;
};

Proxy::Proxy() : m_real_subject(std::make_shared<RealSubject>()) {

}

void Proxy::request() {
    m_real_subject->request();
}

#endif