#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP

// 创建型模式
// 原型模式（Prototype Pattern）是用于创建重复的对象，同时又能保证性能。这种模式是通过拷贝原型对象来创建新的对象，而不是直接创建新的对象。
// 这种模式是一种创建型模式，它提供了一种创建对象的最佳方式。

#include <iostream>

class Prototype {
public:
    virtual ~Prototype() = default;
    virtual Prototype* clone() const = 0;
protected:
    Prototype() = default;
};

class ConcretePrototype : public Prototype {
public:
    ConcretePrototype() = default;
    ~ConcretePrototype() = default;
    ConcretePrototype(const ConcretePrototype& other);
    Prototype* clone() const override;
};

ConcretePrototype::ConcretePrototype(const ConcretePrototype &other) {
    std::cout << "copy constructor called" << std::endl;
    // 进行浅拷贝或深拷贝操作
}

Prototype* ConcretePrototype::clone() const {
    return new ConcretePrototype(*this);
}



#endif // PROTOTYPE_HPP