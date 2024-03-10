#include "Factory.hpp"
#include <iostream>

void Product::print() {
    std::cout << "Width: " << width << " Height: " << height << std::endl;
}

Product::~Product() {
    std::cout << "~product()" << std::endl;
}


Apple::~Apple() {
    std::cout << "~Apple()" << std::endl;
}

Orange::~Orange() {
    std::cout << "~Orange()" << std::endl;
}

Factory::~Factory() {
    std::cout << "~Factory()" << std::endl;
}

ProductFactory::~ProductFactory() {
    std::cout << "~ProductFactory()" << std::endl;
}

Product* ProductFactory::create_apple() {
    return new Apple();
}

Product* ProductFactory::create_orange() {
    return new Orange();
}
