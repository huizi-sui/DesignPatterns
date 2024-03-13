
#include "ChainOfResponsibility.hpp"

int main() {
    Handler* handlerA = new HandlerA();
    Handler* handlerB = new HandlerB();
    Handler* handlerC = new HandlerC();

    handlerA->set_next(handlerB);
    handlerB->set_next(handlerC);

    handlerA->handle_request(5);
    handlerA->handle_request(15);
    handlerA->handle_request(25);

    delete handlerA;
    delete handlerB;
    delete handlerC;

    return 0;
}