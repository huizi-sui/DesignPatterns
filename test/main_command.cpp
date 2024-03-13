
#include "Command.hpp"

int main() {
    // 创建接收者对象
    Receiver receiver;
    // 创建命令对象
    AddMoneyCommand command1(&receiver);
    AddDiamondCommand command2(&receiver);

    Invoker invoker;
    invoker.add_command(&command1);
    invoker.add_command(&command2);

    invoker.execute_commands();

    return 0;

}