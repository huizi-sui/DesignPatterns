#ifndef MEMENTO_HPP
#define MEMENTO_HPP

// 备忘录模式： 行为型模式
// 允许在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，
// 从而在以后可以恢复到原先保存的状态。

#include <iostream>
#include <string>
#include <vector>

// 备忘录类, 用于保存状态
class Memento {
public:
    Memento(const std::string& state) : m_state(state) {
    }
    std::string get_state() const {
        return m_state;
    }
private:
    std::string m_state;
};

// 需要保存状态的对象
class Originator {
public:
    void set_state(const std::string& state) {
        m_state = state;
    }
    std::string get_state() const {
        return m_state;
    }
    // 创建备忘录，保存当前状态
    Memento create_memento() const {
        return Memento(m_state);
    }
    // 恢复状态
    void restore_memento(const Memento& memento) {
        m_state = memento.get_state();
    }
private:
    std::string m_state;
};

// Memento Mgr
class Caretaker {
public:
    void add_memento(const Memento& memento) {
        m_mementos.push_back(memento);
    }
    Memento get_memento(int index) const {
        return m_mementos[index];
    }
private:
    std::vector<Memento> m_mementos;
};

#endif