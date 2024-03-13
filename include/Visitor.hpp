#ifndef VISITOR_HPP
#define VISITOR_HPP

// 访问者模式： 行为型设计模式
// 用于在不改变对象结构的情况下，定义作用于某对象结构的新操作。
// 该模式将操作与对象结构分离，使得可以在不改变元素类的前提下，定义新的操作。

#include <iostream>
#include <vector>

class ElementA;
class ElementB;

// 访问者抽象类
class Visitor {
public:
    virtual void visit(ElementA* element) = 0;
    virtual void visit(ElementB* element) = 0;
};

// 元素抽象
class Element {
public:
    virtual void accept(Visitor* visitor) = 0;
};

// 具体元素A
class ElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
    void operationA() {
        std::cout << "ElementA operationA" << std::endl;
    }
};

// 具体元素B
class ElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
    void operationB() {
        std::cout << "ElementB operationB" << std::endl;
    }
};

// 具体访问者
class ConcreteVisitor : public Visitor {
public:
    void visit(ElementA* element) override {
        std::cout << "访问者访问元素A， 执行相关操作" << std::endl;
        element->operationA();
    }
    void visit(ElementB* element) override {
        std::cout << "访问者访问元素B， 执行相关操作" << std::endl;
        element->operationB();
    }
};

/////////////////////////////
// 更具体的例子

class Circle;
class Rectangle;
class Triangle;

class Visitor2 {
public:
    virtual void visit(Circle* circle) = 0;
    virtual void visit(Rectangle* rectangle) = 0;
    virtual void visit(Triangle* triangle) = 0;
};

class Shape {
public:
    virtual void accept(Visitor2* visitor) = 0;
};

class Circle : public Shape {
public:
    void accept(Visitor2* visitor) override {
        visitor->visit(this);
    }
    void draw() {
        std::cout << "绘制圆形" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void accept(Visitor2* visitor) override {
        visitor->visit(this);
    }
    void draw() {
        std::cout << "绘制矩形" << std::endl;
    }
};

class Triangle : public Shape {
public:
    void accept(Visitor2* visitor) override {
        visitor->visit(this);
    }
    void draw() {
        std::cout << "绘制三角形" << std::endl;
    }
};

// 具体访问者
class DrawVisitor : public Visitor2 {
public:
    void visit(Circle* circle) override {
        std::cout << "绘制访问者绘制圆形" << std::endl;
        circle->draw();
    }
    void visit(Rectangle* rectangle) override {
        std::cout << "绘制访问者绘制矩形" << std::endl;
        rectangle->draw();
    }
    void visit(Triangle* triangle) override {
        std::cout << "绘制访问者绘制三角形" << std::endl;
        triangle->draw();
    }
};

class MoveVisitor : public Visitor2 {
public:
    void visit(Circle* circle) override {
        std::cout << "移动访问者移动圆形" << std::endl;
        // 执行圆形的移动操作
    }
    void visit(Rectangle* rectangle) override {
        std::cout << "移动访问者移动矩形" << std::endl;
        // 执行矩形的移动操作
    }
    void visit(Triangle* triangle) override {
        std::cout << "移动访问者移动三角形" << std::endl;
        // 执行三角形的移动操作
    }
};


#endif // VISITOR_HPP