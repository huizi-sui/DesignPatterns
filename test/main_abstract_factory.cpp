
#include "AbstractFactory.hpp"

int main() {
    AbstractFactory* china = new ChinaFactory();
    AbstractFactory* usa = new USAFactory();
    AbstractFactory* japan = new JapanFactory();

    AbstractApple* china_apple = china->get_apple();
    AbstractBanana* china_banana = china->get_banana();

    AbstractApple* usa_apple = usa->get_apple();
    AbstractBanana* usa_banana = usa->get_banana();

    AbstractApple* japan_apple = japan->get_apple();
    AbstractBanana* japan_banana = japan->get_banana();

    china_apple->name();
    china_banana->name();
    usa_apple->name();
    usa_banana->name();
    japan_apple->name();
    japan_banana->name();

    delete china;
    delete china_apple;
    delete china_banana;
    delete usa;
    delete usa_apple;
    delete usa_banana;
    delete japan;
    delete japan_apple;
    delete japan_banana;

    return 0;
}