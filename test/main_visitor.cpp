
#include "Visitor.hpp"

int main() {
    std::vector<Element*> elements;
    elements.push_back(new ElementA());
    elements.push_back(new ElementB());

    ConcreteVisitor visitor;
    for(auto& element : elements) {
        element->accept(&visitor);
    }
    for(auto element : elements) {
        delete element;
    }

    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Triangle());

    DrawVisitor drawVisitor;
    MoveVisitor moveVisitor;
    for(auto& shape : shapes) {
        shape->accept(&drawVisitor);
    }
    for(auto& shape : shapes) {
        shape->accept(&moveVisitor);
    }
    for(auto shape : shapes) {
        delete shape;
    }
    return 0;
}