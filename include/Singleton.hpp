
#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
#include <memory>
// 1. 构造函数私有化
// 2. 添加静态私有指针
// 3. 提供接口

// 懒汉式，线程不安全
class SingletonLazy {
public:
    static SingletonLazy* get_instance() {
        if(ptr == nullptr) {
            ptr = new SingletonLazy();
        }
        return ptr;
    }
    void name() {
        std::cout << "lazy" << std::endl;
    }
private:
    static SingletonLazy* ptr;
    SingletonLazy() = default;
};

// 初始化
SingletonLazy* SingletonLazy::ptr = nullptr;

// 饿汉式，在main函数执行之前就已经完成初始化，线程安全
class SingletonHungry {
public:
    static SingletonHungry* get_instance() {
        return ptr;
    }
    void name() {
        std::cout << "hungry" << std::endl;
    }
private:
    static SingletonHungry* ptr;
    SingletonHungry() = default;
};

// 初始化
SingletonHungry* SingletonHungry::ptr = new SingletonHungry();


// 使用template 和shared_ptr
template<typename T>
class SingletonTemplate {
public:
    static T* get_instance() {
        static std::shared_ptr<T> instance = nullptr;
        if(instance == nullptr) {
            instance = std::make_shared<T>();
        }
        return instance.get();
    }
private:
    SingletonTemplate() = default;
};



#endif