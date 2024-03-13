#ifndef COMMAND_HPP
#define COMMAND_HPP

// 命令模式： 行为型模式
// 将请求封装成对象，从而允许根据不同的请求将客户端参数化，对请求排队或记录请求日志，以及支持可撤销的操作。

// 命令模式包含以下主要角色：
// 1. Command：抽象命令类，声明执行操作的接口。
// 2. ConcreteCommand：具体命令类，实现命令接口，并将操作绑定到接收者。
// 3. Receiver：接收者，执行实际操作对象。
// 4. Invoker：调用者，持有命令对象并触发命令执行。
// 5. Client：客户端，创建具体命令对象并将其与接收者绑定。

#include <iostream>
#include <string>
#include <queue>

// 命令接口
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() const = 0;
};

// 接收者
class Receiver {
public:
    void add_money() {
        std::cout << "Add money" << std::endl;
    }
    void add_diamond() {
        std::cout << "Add diamond" << std::endl;
    }
};

// 具体命令
class AddMoneyCommand : public Command {
private:
    Receiver* m_receiver;
public:
    AddMoneyCommand(Receiver* receiver) : m_receiver(receiver) {}

    void execute() const override {
        m_receiver->add_money();
    }
};

class AddDiamondCommand : public Command {
private:
    Receiver* m_receiver;
public:
    AddDiamondCommand(Receiver* receiver) : m_receiver(receiver) {}

    void execute() const override {
        m_receiver->add_diamond();
    }
};

// 调用者
class Invoker {
private:
    std::queue<Command*> m_commands;
public:
    void add_command(Command* command) {
        m_commands.push(command);
    }
    void execute_commands() {
        while(!m_commands.empty()) {
            Command* command = m_commands.front();
            m_commands.pop();
            command->execute();
        }
    }
};


#endif