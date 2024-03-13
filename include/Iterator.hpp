#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// 迭代器模型
// 提供一种顺序访问集合对象元素的方法，而无需暴露其底层表示。
// 通过使用迭代器模式，可以在不了解集合内部结构的情况下遍历集合的元素。

// 核心是迭代器接口，定义了访问和遍历集合元素的方法。具体的集合类
// 实现迭代器接口，并提供用于创建迭代器对象的方法。

// 好处：将集合类的遍历行为与集合类的实现分离，可以独立的改变遍历算法而无需修改集合类的代码

#include <iostream>
#include <string>
#include <vector>

// 迭代器抽象类
class Iterator {
public:
    Iterator() = default;
    virtual ~Iterator() = default;
    virtual std::string first() = 0;
    virtual std::string next() = 0;
    virtual std::string current_item() = 0;
    virtual bool is_done() = 0;
};

// 聚集抽象类
class Aggregate {
public:
    virtual int count() = 0;
    virtual void push(const std::string& value) = 0;
    virtual std::string pop(const int index) = 0;
    virtual Iterator* create_iterator() = 0;
};

// 具体迭代器
class ConcreteIterator : public Iterator {
public:
    ConcreteIterator(Aggregate* aggregate) : Iterator(), m_current(0), m_aggregate(aggregate) {}
    std::string first() override {
        return m_aggregate->pop(0);
    }
    std::string next() override {
        m_current++;
        std::string s;
        if(m_current < m_aggregate->count()) {
            s = m_aggregate->pop(m_current);
        }
        return s;
    }
    std::string current_item() override {
        return m_aggregate->pop(m_current);
    }
    bool is_done() override {
        return (m_current >= m_aggregate->count());
    }
private:
    Aggregate* m_aggregate;
    int m_current;
};

// 具体聚集类
class ConcreteAggregate : public Aggregate {
public:
    ConcreteAggregate() : Aggregate(), m_iterator(nullptr) {}
    ~ConcreteAggregate() {
        if(m_iterator) {
            delete m_iterator;
            m_iterator = nullptr;
        }
    }
    Iterator* create_iterator() override {
        if(nullptr == m_iterator) {
            m_iterator = new ConcreteIterator(this);
            return m_iterator;
        }
    }
    int count() override {
        return m_items.size();
    }
    void push(const std::string& value) override {
        m_items.push_back(value);
    }
    std::string pop(const int index) override {
        std::string s;
        if(index < count()) {
            s = m_items[index];
        }
        return s;
    }
private:
    std::vector<std::string> m_items;
    Iterator* m_iterator;
};

#endif