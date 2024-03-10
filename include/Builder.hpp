
#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <iostream>
#include <vector>

class Product {
public:
    std::vector<std::string> vec;
    std::ostream& operator<<(std::ostream& os) {
        for(const auto& s : vec) {
            os << s << " ";
        }
        return os;
    }
};

class Builder {
public:
    virtual ~Builder() = default;
    virtual Builder* process_a() = 0;
    virtual Builder* process_b() = 0;
    virtual Builder* process_c() = 0;
};

class MyBuilder : public Builder {
public:
    ~MyBuilder() {
        delete ptr;
    }
    MyBuilder() : ptr(new Product) {}
    void reset();
    Builder* process_a() override;
    Builder* process_b() override;
    Builder* process_c() override;
    Product* get();
private:
    Product* ptr;
};

class Director {
private:
    Builder* m_builder;
public:
    void set_builder(Builder* builder) {
        m_builder = builder;
    }

    void build_minimal_product() {
        m_builder->process_a();
    }

    void build_full_feature_product() {
        m_builder->process_a()->process_b()->process_c();
    }
};

void MyBuilder::reset() {
    ptr = new Product();
}

Builder* MyBuilder::process_a() {
    ptr->vec.push_back(std::string("process A"));
    return this;
}

Builder* MyBuilder::process_b() {
    ptr->vec.push_back(std::string("process B"));
    return this;
}

Builder* MyBuilder::process_c() {
    ptr->vec.push_back(std::string("process C"));
    return this;
}

Product* MyBuilder::get() {
    Product* ptrTemp = ptr;
    // 创建新的对象实例
    reset();
    // 将装配好的产品返回
    return ptrTemp;
}


#endif