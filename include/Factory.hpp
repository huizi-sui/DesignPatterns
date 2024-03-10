
#pragma once

class Product {
    int width, height;

protected:
    Product(int w, int h) : width(w), height(h) {}
    Product() = default;

public:
    virtual ~Product() = 0;
    void print();
};

class Apple : public Product {
public:
    Apple() : Product(10, 20) {}
    ~Apple();
};

class Orange : public Product {
public:
    Orange() : Product(2, 20) {}
    ~Orange();
};

class Factory {
public:
    virtual ~Factory() = 0;
    virtual Product* create_apple() = 0;
    virtual Product* create_orange() = 0;
protected:
    Factory() = default;
};

class ProductFactory : public Factory {
public:
    ~ProductFactory();
    ProductFactory() = default;
    Product* create_apple() override;
    Product* create_orange() override;
};