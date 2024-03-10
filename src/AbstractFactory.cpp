
#include "AbstractFactory.hpp"
#include <iostream>

void ChinaApple::name() {
    std::cout << "China Apple" << std::endl;
}

void USAApple::name() {
    std::cout << "USA Apple" << std::endl;
}

void JapanApple::name() {
    std::cout << "Japan Apple" << std::endl;
}

void ChinaBanana::name() {
    std::cout << "China Banana" << std::endl;
}

void USABanana::name() {
    std::cout << "USA Banana" << std::endl;
}

void JapanBanana::name() {
    std::cout << "Japan Banana" << std::endl;
}

AbstractApple* ChinaFactory::get_apple() {
    return new ChinaApple();
}

AbstractBanana* ChinaFactory::get_banana() {
    return new ChinaBanana();
}

AbstractApple* USAFactory::get_apple() {
    return new USAApple();
}

AbstractBanana* USAFactory::get_banana() {
    return new USABanana();
}

AbstractApple* JapanFactory::get_apple() {
    return new JapanApple();
}

AbstractBanana* JapanFactory::get_banana() {
    return new JapanBanana();
}