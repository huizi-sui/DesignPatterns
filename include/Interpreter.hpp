#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

// 解释器模型：行为型设计模式，用于解释和评估语言的语法或表达式
// 定义了一种表示语言语法的类结构，并提供了一种解释器解释语法中的表达式。

// 一般有两种类型的角色
// 1. 抽象表达式：定义解释器接口，所有具体表达式都必须实现这个接口。
// 2. 具体表达式：实现抽象表达式接口，并提供具体的解释逻辑。

// 解释器模式通过递归的方式解释表达式，将表达式转换为一系列的操作或动作。
// 这些操作可以是简单的操作，也可以是复杂的操作，具体取决于语言的语法规则。

// 总结一下，解释器模式适用于需要解释和评估语言语法或表达式的场景。
// 它可以灵活地定义语法规则，并提供了一种解释器来解释和执行这些规则。

#include <iostream>
#include <string>

class Context {
public:
    Context(int num) : m_num(num), m_res(0) {}
    void set_num(int num) {
        m_num = num;
    }
    int get_num() const {
        return m_num;
    }
    void set_res(int res) {
        m_res = res;
    }
    int get_res() const {
        return m_res;
    }
private:
    int m_num;
    int m_res;
};

// 表达式抽象类
class Expression {
public:
    virtual void interpreter(Context& context) = 0;
};

// 具体表达式类
class PlusExpression : public Expression {
public:
    void interpreter(Context& context) override {
        int num = context.get_num();
        num++;
        context.set_num(num);
        context.set_res(num);
    }
};

class MinusExpression : public Expression {
public:
    void interpreter(Context& context) override {
        int num = context.get_num();
        num--;
        context.set_num(num);
        context.set_res(num);
    }
};

#endif // INTERPRETER_HPP