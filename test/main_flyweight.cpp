
#include "Flyweight.hpp"


int main() {
    FlyweightFactory flyweight_factory;
    Flyweight* ccc = flyweight_factory.get_flyweight("ccc");
    Flyweight* aaa = flyweight_factory.get_flyweight("aaa");
    Flyweight* bbb = flyweight_factory.get_flyweight("aaa");

    std::cout << std::boolalpha  << (aaa == bbb) << std::endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}