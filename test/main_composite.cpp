
#include "Composite.hpp"


int main() {
    Composite* composite = new Composite();
    composite->add(new Leaf());
    composite->add(new Leaf());
    // 整体与部分使用一致性操作operation
    composite->operation(); // 整体
    composite->get_child(1)->operation(); // 个体

    // composite下面还有一个小整体
    Composite* composite_child = new Composite();
    composite_child->add(new Leaf());
    composite->add(new Leaf());
    composite->add(composite_child);

    composite->operation();

    delete composite;
    return 0;
}