
#include "Bridge.hpp"


int main() {
    Interface* api1 = new ReinterFaceUber(new Cab());
    api1->run();

    Interface* api2 = new ReinterFaceUber(new Uber());
    api2->run();

    delete api1;
    delete api2;
    //这里可以这样理解，我们是一个网约车程序
    //ReinterfaceCab是叫普通出租车,在其run方法进行某些业务操作
    //然后用callCar->call()，真正的去叫出租车
    //ReinterfaceUber是叫Uber,在其run方法进行某些业务操作
    //然后callCar->call(),真正的去叫Uber
    //当叫不同的车有不同的业务逻辑，则在不同的Reinterface内进行就好了
    //而不用把复杂的业务逻辑由不同的CallCar派生类实现
    return 0;
}