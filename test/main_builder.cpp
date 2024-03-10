
#include "Builder.hpp"

int main() {
    Director* director = new Director();
    MyBuilder* my_builder = new MyBuilder();
    director->set_builder(my_builder);

    director->build_full_feature_product();
    Product* product = my_builder->get();
    // *product << std::cout;
    product->operator<<(std::cout);
    std::cout << std::endl;

    delete product;

    director->build_minimal_product();
    product = my_builder->get();
    product->operator<<(std::cout);
    std::cout << std::endl;

    delete product;

    delete my_builder;
    delete director;
    return 0;
}