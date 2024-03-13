
#include "Mediator.hpp"

int main() {
    ConcreteMediator mediator;
    ConcreteColleague colleague1(&mediator);
    ConcreteColleague colleague2(&mediator);

    // 将同事对象添加到中介者中
    mediator.add_colleague(&colleague1);
    mediator.add_colleague(&colleague2);

    // 同事之间通过中介者进行通信
    colleague1.send_message("Hello, colleague2!");
    colleague2.send_message("Hello, colleague1!");

    return 0;
}