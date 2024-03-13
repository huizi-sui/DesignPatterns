
#include "State.hpp"

int main() {
    Context context(new StateA());
    context.request();
    context.request();
    context.request();
    context.request();

    return 0;
}