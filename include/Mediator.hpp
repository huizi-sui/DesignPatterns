#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

// 中介者模式： 行为型设计模式
// 旨在通过引入一个中介者，来解耦多个对象之间的交互关系。
// 在中介者模式中，对象之间不直接通信，而通过中介者进行沟通，使各对象松耦合，提高系统的可维护性和可扩展性。

// 中介者：定义一个接口用于与各个同事对象进行通信，并协调各个同时对象的行为。
// 具体中介者： 实现中介者接口，协调各个同事对象的行为
// 同事： 定义一个接口用于与中介者进行通信。
// 具体同事： 实现同事接口，与其他同事对象进行通信。

#include <iostream>
#include <string>
#include <vector>

class Mediator;

// 同事抽象类
class Colleague {
protected:
    Mediator* m_mediator;
public:
    Colleague(Mediator* mediator) : m_mediator(mediator) {}
    virtual void send_message(const std::string& message) = 0;
    virtual void receive_message(const std::string& message) = 0;
};

// 中介者抽象类
class Mediator {
public:
    virtual void send_message(const std::string& message, Colleague* colleague) = 0;
};

// 具体中介者类
class ConcreteMediator : public Mediator {
private:
    std::vector<Colleague*> m_colleagues;
public:
    void add_colleague(Colleague* colleague) {
        m_colleagues.push_back(colleague);
    }
    void send_message(const std::string& message, Colleague* colleague) override {
        for(auto& c : m_colleagues) {
            if(c != colleague) {
                c->receive_message(message);
            }
        }
    }
};

// 具体同事类
class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator) : Colleague(mediator) {}
    void send_message(const std::string& message) override {
        m_mediator->send_message(message, this);
    }
    void receive_message(const std::string& message) override {
        std::cout << "Received message: " << message << std::endl;
    }
};

#endif