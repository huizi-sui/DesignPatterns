
#include "Prototype.hpp"

int main() {
    Prototype* prototype = new ConcretePrototype();
    Prototype* other = prototype->clone();
    delete prototype;
    delete other;
    return 0;
}