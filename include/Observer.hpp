#ifndef OBSERVER_HPP
#define OBSERVER_HPP

// 观察者模式：行为型设计模式，允许对象自动向其依赖的观察者对象通知其状态的变化。

// 主要角色： 主题和观察者
// 主题（Subject）：维护一个观察者集合，当主题状态发生变化时，向观察者发送通知。
// 观察者（Observer）：它定义了一个更新方法，以便在接收到主题通知时执行相应的操作。

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Observer;

// 主题接口
class Subject {
public:
    virtual void register_observer(std::shared_ptr<Observer> observer) = 0;
    virtual void remove_observer(std::shared_ptr<Observer> observer) = 0;
    virtual void notify_observers() = 0;
};

// 抽象观察者类
class Observer {
public:
    virtual void update(int value) = 0;
};

// 具体主题类
class MySubject : public Subject {
public:
    void register_observer(std::shared_ptr<Observer> observer) override;
    void remove_observer(std::shared_ptr<Observer> observer) override;
    void notify_observers() override;
    void set_value(int value);
private:
    int value{0};
    std::vector<std::shared_ptr<Observer>> m_observers;
};

void MySubject::register_observer(std::shared_ptr<Observer> observer) {
    m_observers.push_back(observer);
}

void MySubject::remove_observer(std::shared_ptr<Observer> observer) {
    auto iter = std::find(m_observers.begin(), m_observers.end(), observer);
    if(iter != m_observers.end()) {
        m_observers.erase(iter);
    }
}

void MySubject::notify_observers() {
    for(auto& observer : m_observers) {
        observer->update(value);
    }
}

void MySubject::set_value(int value) {
    this->value = value;
    notify_observers();
}

// 具体观察者类
class MyObserver : public Observer {
public:
    MyObserver(const std::string& name);
    void update(int value) override;
private:
    std::string name;
};

MyObserver::MyObserver(const std::string &name) : name(name) {

}

void MyObserver::update(int value) {
    std::cout << "Observer " << name << " received update with value " << value << std::endl;
}

#endif