
#include "Strategy.hpp"

int main() {
    std::shared_ptr<Strategy> a = std::make_shared<StrategyA>();
    std::shared_ptr<Strategy> b = std::make_shared<StrategyB>();

    std::cout << a.use_count() << " " << b.use_count() << std::endl;
    Context context(a);
    context.execute_strategy();
    std::cout << a.use_count() << " " << b.use_count() << std::endl;

    context.set_strategy(b);
    context.execute_strategy();
    std::cout << a.use_count() << " " << b.use_count() << std::endl;

    return 0;
}