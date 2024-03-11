
#include "Adapter.hpp"


int main() {
    MyInterface* api = new Adapter();
    api->exe(MyInterface::CALL);
    api->exe(MyInterface::REQUEST);

    delete api;
    api = nullptr;

    MyInterface* api2 = new Adapter2(new ThirdPart());
    api2->exe(MyInterface::CALL);
    api2->exe(MyInterface::REQUEST);

    delete api2;
    api2 = nullptr;

    return 0;
}