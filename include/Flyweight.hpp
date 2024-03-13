
#ifndef FLYWEIGHT_HPP
#define FLYWEIGHT_HPP

// Flyweight: 享元模式，是一种结构型设计模式，它旨在通过共享尽可能多的对象来
// 最小化内存使用和对象创建的成本。

// 在该模式中，共享对象称为“享元”，而享元对象的状态被分为内部状态和外部状态。
// 内部状态是指可以被多个对象共享的信息，而外部状态是指依赖于特定对象的信息。

// 用途： 优化内存使用，尤其是在需要大量相似对象时。通过共享内部状态，可以减少需要创建的对象数量，
// 从而降低内存使用。

// 在实际应用中，享元模式通常和其他模式一起使用，例如组合模式和代理模式
// 有点像对象池

#include <iostream>
#include <string>
#include <list>

class Flyweight {
public:
    virtual ~Flyweight() = default;
    std::string get_intrinsic_state();
    virtual void operation(std::string& extrinsic_state) = 0;
protected:
    Flyweight(const std::string& state);

private:
    std::string m_state;
};

Flyweight::Flyweight(const std::string &state) : m_state(state) {

}

std::string Flyweight::get_intrinsic_state() {
    return m_state;
}

class ConcreateFlyweight : public Flyweight {
public:
    ConcreateFlyweight(const std::string& state) : Flyweight(state) {

    }
    virtual ~ConcreateFlyweight() = default;
    void operation(std::string& extrinsic_state) override {
        // ....
    }
};

class FlyweightFactory {
public:
    FlyweightFactory() = default;
    ~FlyweightFactory();
    Flyweight* get_flyweight(const std::string& key);
private:
    std::list<Flyweight*> m_list;
};

FlyweightFactory::~FlyweightFactory() {
    for(Flyweight* ptr : m_list) {
        delete ptr;
    }
    m_list.clear();
}

Flyweight* FlyweightFactory::get_flyweight(const std::string &key) {
    for(Flyweight* ptr : m_list) {
        if(ptr->get_intrinsic_state() == key) {
            return ptr;
        }
    }
    // 找不到，创建新对象
    Flyweight* ptr = new ConcreateFlyweight(key);
    m_list.push_back(ptr);
    return ptr;
}

#endif
