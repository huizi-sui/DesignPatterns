
#include <iostream>
#include "Singleton.hpp"

int main() {
    SingletonLazy::get_instance()->name();
    SingletonHungry::get_instance()->name();

    int* ptr = SingletonTemplate<int>::get_instance();
    *ptr = 999;
    std::cout << *(SingletonTemplate<int>::get_instance()) << std::endl;
}