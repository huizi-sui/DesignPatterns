#ifndef CHAIN_OF_RESPONSIBILITY_HPP
#define CHAIN_OF_RESPONSIBILITY_HPP

// 责任链模式 行为型设计模式
// 允许多个对象按照顺序处理请求，直到其中一个对象能够处理为止。
// 每个对象都可以决定是否处理请求，以及将请求传递给下一个对象。
// 可以避免请求的发送者和接收者之间的耦合关系，并使得系统的扩展性变得更好。

#include <iostream>

class Handler {
public:
    virtual void set_next(Handler* handler) = 0;
    virtual void handle_request(int request) = 0;
};

class HandlerA : public Handler {
private:
    Handler* m_next;
public:
    void set_next(Handler* handler) override {
        m_next = handler;
    }
    void handle_request(int request) override {
        if(request >= 0 && request < 10) {
            std::cout << "HandlerA handles request" << std::endl;
        } else if(m_next != nullptr) {
            m_next->handle_request(request);
        }
    }
};

class HandlerB : public Handler {
private:
    Handler* m_next;
public:
    void set_next(Handler* handler) override {
        m_next = handler;
    }
    void handle_request(int request) override {
        if(request >= 10 && request < 20) {
            std::cout << "HandlerB handles request" << std::endl;
        } else if(m_next != nullptr) {
            m_next->handle_request(request);
        }
    }
};

class HandlerC : public Handler {
private:
    Handler* m_next;
public:
    void set_next(Handler* handler) override {
        m_next = handler;
    }
    void handle_request(int request) override {
        if(request >= 20 && request < 30) {
            std::cout << "HandlerC handles request" << std::endl;
        } else if(m_next != nullptr) {
            m_next->handle_request(request);
        }
    }
};



#endif // CHAIN_OF_RESPONSIBILITY_HPP