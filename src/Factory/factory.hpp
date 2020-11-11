#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <string>
#include <iostream>

class AbstractProduct {
public:
    virtual ~AbstractProduct() {}

    virtual void do_something() = 0;
};

class ProductA : public AbstractProduct {
public:
    void do_something() {
        std::cout << "ProductA do something ..." << std::endl;
    }
};

class ProductB : public AbstractProduct {
public:
    void do_something() {
        std::cout << "ProductB do something ..." << std::endl;
    }
};

class Factory {
public:
    AbstractProduct * create_product(const std::string prod) {
        AbstractProduct * abs = nullptr;
        if (prod == std::string("ProductA")) {
            abs = new ProductA;
        } else if (prod == std::string("ProductB")) {
            abs = new ProductB;
        } else {
            abs = nullptr;
        }
        return abs;
    }
};


#endif // __FACTORY_HPP__