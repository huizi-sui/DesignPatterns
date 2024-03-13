
#include "Template.hpp"

#include <memory>

int main() {
    std::unique_ptr<AbstractClass> ptr1(new Class1());
    std::unique_ptr<AbstractClass> ptr2(new Class2());

    ptr1->template_method();
    ptr2->template_method();

    return 0;
}