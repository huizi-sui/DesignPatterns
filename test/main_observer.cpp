
#include "Observer.hpp"

int main() {
    std::shared_ptr<MySubject> subject = std::make_shared<MySubject>();
    std::shared_ptr<Observer> observer1 = std::make_shared<MyObserver>("observer1");
    std::shared_ptr<Observer> observer2 = std::make_shared<MyObserver>("observer2");

    subject->register_observer(observer1);
    subject->register_observer(observer2);

    // 改变主题状态
    subject->set_value(12);

    subject->remove_observer(observer2);

    subject->set_value(2);

    return 0;

}