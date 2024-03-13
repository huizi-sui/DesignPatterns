#ifndef STRATEGY_HPP
#define STRATEGY_HPP

// 策略模式： 行为型设计模式
// 允许在运行时根据需求来选择不同的算法或行为。
// 该模式通过将算法封装在独立的策略类中，使得算法可以相互替换而不影响使用算法的客户端

#include <iostream>

// 策略接口
class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute() const = 0;
};

// 具体策略A
class StrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "StrategyA::execute()" << std::endl;
    }
    ~StrategyA() {
        std::cout << "~StrategyA" << std::endl;
    }
};

// 具体策略B
class StrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "StrategyB::execute()" << std::endl;
    }
    ~StrategyB() {
        std::cout << "~StrategyB" << std::endl;
    }
};

// 上下文用于调用策略
class Context {
private:
    std::shared_ptr<Strategy> m_strategy;

public:
    Context(std::shared_ptr<Strategy> strategy);
    void set_strategy(std::shared_ptr<Strategy> strategy);
    void execute_strategy();
};

Context::Context(std::shared_ptr<Strategy> strategy) : m_strategy(std::move(strategy)) {
}

void Context::set_strategy(std::shared_ptr<Strategy> strategy) {
    // m_strategy.reset();
    // m_strategy.swap(strategy);
    m_strategy = std::move(strategy);
}

void Context::execute_strategy() {
    m_strategy->execute();
}

#endif