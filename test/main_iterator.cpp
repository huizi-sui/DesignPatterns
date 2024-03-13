
#include "Iterator.hpp"

int main() {
    ConcreteAggregate* names = new ConcreteAggregate();
    if(names == nullptr) {
        return -1;
    }
    names->push("Hello");
    names->push("World");
    names->push("!");
    Iterator* it = names->create_iterator();

    if(it == nullptr) {
        return -1;
    }

    while(!it->is_done()) {
        std::cout << it->current_item() << std::endl;
        it->next();
    }
    delete names;
    return 0;
}