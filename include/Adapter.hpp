
#ifndef ADAPTER_HPP
#define ADAPTER_HPP

#include <iostream>

// 适配器模型： 结构型模式
// 适配器模式（Adapter Pattern）是作为两个不兼容的接口之间的桥梁。

// 使用场景通常为，我们因为任务已经写好了接口，但是拿来了一个第三方库，
// 接口并不相同，则在中间可以有一个适配器进行过渡，适配器可以采用继承或者组合的方式进行实现


// 原先我们的程序使用的接口
class MyInterface {
public:
    enum exe_type {
        CALL,
        REQUEST
    };
    virtual void exe(exe_type type) = 0;
    MyInterface() = default;
    virtual ~MyInterface() = default;
};

// 最新找来的第三方库
class ThirdPart {
public:
    void call();
    void request();
};

void ThirdPart::call() {
    std::cout << "ThirdPart call" << std::endl;
}

void ThirdPart::request() {
    std::cout << "ThirdPart request" << std::endl;
}

// 编写适配器——继承
class Adapter : public MyInterface, public ThirdPart {
public:
    void exe(exe_type type) override;
};

void Adapter::exe(exe_type type) {
    switch (type) {
        case exe_type::CALL:
            call();
            break;
        case exe_type::REQUEST:
            request();
            break;
        default:
            break;
    }
}

// 编写适配器——组合
class Adapter2 : public MyInterface {
public:
    Adapter2(ThirdPart* third_part) : m_third_part(third_part) {}
    void exe(exe_type type) override;
    ~Adapter2() {
        delete m_third_part;
    }
private:
    ThirdPart* m_third_part;
};

void Adapter2::exe(exe_type type) {
    switch (type) {
        case exe_type::CALL:
            m_third_part->call();
            break;
        case exe_type::REQUEST:
            m_third_part->request();
            break;
        default:
            break;
    }
}

#endif