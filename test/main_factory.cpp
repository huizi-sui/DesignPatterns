#include <iostream>

#include "Factory.hpp"

int main() {
    Factory* factory = new ProductFactory();

    Product* apple = factory->create_apple();
    Product* orange = factory->create_orange();

    apple->print();
    orange->print();

    delete factory;
    delete apple;
    delete orange;

    return 0;
}
