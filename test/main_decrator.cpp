
#include "Decrator.hpp"

int main() {
    Base* girl = new Girl();

    girl->show();
    std::cout << girl->cost() << std::endl;

    Decrator* mini_skirt = new MiniSkirt(girl);
    Decrator* black_silk = new BlackSilk(girl);

    mini_skirt->show();
    std::cout << mini_skirt->cost() << std::endl;

    black_silk->show();
    std::cout << black_silk->cost() << std::endl;
}