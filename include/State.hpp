
#ifndef STATE_HPP
#define STATE_HPP

// 状态模式：行为设计模式，允许一个对象在内部状态发生改变时改变其行为。
// 状态模式将对象的行为包装在不同的状态对象中，使得对象能够根据当前状态来选择不同的行为。

// 状态模式主要包含以下几个角色：
// 环境Context：定义客户端所感兴趣的接口，维护一个当前状态对象的引用。在环境中，
//             可以通过调用当前状态对象的方法来执行相应的行为。
// 抽象状态Abstract State： 定义一个抽象的状态接口，所有具体状态都实现这个接口。
//                          抽象状态中的方法代表了对象在该状态下可能执行的行为。
// 具体状态Concrete State：实现抽象状态接口，且实现在特定状态下对象可能执行的行为。

#include <iostream>

class Context;
class StateB;

// 状态抽象类
class State {
public:
    virtual void handle(Context* context) = 0;
    virtual ~State() = default;
};

class StateA : public State {
public:
    void handle(Context* context) override;
    StateA() {
        std::cout << "new StateA" << std::endl;
    }
    ~StateA() {
        std::cout << "~StateA" << std::endl;
    }
};

class StateB : public State {
public:
    void handle(Context* context) override;
    StateB() {
        std::cout << "new StateB" << std::endl;
    }
    ~StateB() {
        std::cout << "~StateB" << std::endl;
    }
};

class Context {
public:
    Context(State* state) : m_state(state) {}
    ~Context() {
        if(m_state != nullptr) {
            delete m_state;
        }
    }
    void set_state(State* state) {
        // 更改上下文状态
        m_state = state;
    }
    void request() {
        m_state->handle(this);
    }

private:
    State* m_state;
};

void StateA::handle(Context* context) {
    std::cout << "state a" << std::endl;
    // 改变状态
    context->set_state(new StateB());
    delete this;
}

void StateB::handle(Context *context) {
    std::cout << "state b" << std::endl;
    // 改变状态
    context->set_state(new StateA());
    delete this;
}

#endif