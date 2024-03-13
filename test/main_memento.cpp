
#include "Memento.hpp"

int main() {
    Originator originator;
    Caretaker caretaker;

    originator.set_state("State 1");
    std::cout << originator.get_state() << std::endl;

    caretaker.add_memento(originator.create_memento());
    originator.set_state("State 2");
    caretaker.add_memento(originator.create_memento());
    originator.set_state("State 3");
    caretaker.add_memento(originator.create_memento());

    std::cout << originator.get_state() << std::endl;

    // rollback
    originator.restore_memento(caretaker.get_memento(0));
    std::cout << originator.get_state() << std::endl;
    return 0;
}