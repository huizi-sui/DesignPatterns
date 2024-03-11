
#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

// 组合模式： 将对象组合成树形结构以表示“部分-整体”的层次结构。
// 组合模式使得用户对单个对象和组合对象的使用具有一致性。

#include <iostream>
#include <list>

// 基本对象
class Component {
public:
    Component() = default;
    virtual ~Component() = default;

    virtual void operation() = 0; // 整体与部分具有相同的操作
    virtual void add(Component* p_child) {
    }
    virtual void remove(Component* p_child){
    }
    virtual Component* get_child(int index) {
        return nullptr;
    }
};

// 部分个体
class Leaf : public Component {
public:
    Leaf() = default;
    ~Leaf() = default;
    void operation() override;
};

void Leaf::operation() {
    std::cout << "Leaf::operation()" << std::endl;
}

// 组合体
class Composite : public Component {
public:
    Composite() = default;
    virtual ~Composite();
    void operation() override;
    void add(Component* p_child) override;
    void remove(Component* p_child) override;
    Component* get_child(int index) override;

private:
    std::list<Component*> m_list_of_components;
};

Composite::~Composite() {
    auto begin = m_list_of_components.begin();
    auto end = m_list_of_components.end();
    while(begin != end) {
        delete *begin;
        m_list_of_components.erase(begin);
        begin = m_list_of_components.begin();
        end = m_list_of_components.end();
    }
}

void Composite::add(Component* p_child) {
    m_list_of_components.push_back(p_child);
}

void Composite::remove(Component *p_child) {
    auto res = std::find(m_list_of_components.begin(), m_list_of_components.end(), p_child);
    if(res != m_list_of_components.end()) {
        m_list_of_components.erase(res);
    }
}

Component* Composite::get_child(int index) {
    if(index < 0 || index >= m_list_of_components.size()) {
        return nullptr;
    }
    auto begin = m_list_of_components.begin();
    while(index--) {
        begin++;
    }
    return *begin;
}

void Composite::operation() {
    for(auto item : m_list_of_components) {
        item->operation();
    }
}

#endif // COMPOSITE_HPP