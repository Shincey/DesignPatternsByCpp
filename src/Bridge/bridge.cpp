#include <string>
#include <iostream>
using namespace std;

class Implementation {
public:
    virtual ~Implementation() {}
    virtual std::string Operation() const = 0;
};

class ConcreteImplA : public Implementation {
public:
    std::string Operation() const override {
        return "ConcreteImplA \n";
    }
};

class ConcreteImplB : public Implementation {
public:
    std::string Operation() const override {
        return "ConcreteImplB \n";
    }
};

class Abstraction {
protected:
    Implementation * _impl;
public:
    Abstraction(Implementation *impl) : _impl(impl) {}
    virtual ~Abstraction() {}
    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" + this->_impl->Operation();
    }
};

class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation *impl) : Abstraction(impl) {}
    std::string Operation() const override {
        return "Extended Abstraction: Base operation with:\n" + this->_impl->Operation();
    }
};

void ClientCode(const Abstraction &abs) {
    std::cout << abs.Operation() << endl;
}

int main() {
    Implementation *impl = new ConcreteImplA;
    Abstraction * abst = new Abstraction(impl);
    ClientCode(*abst);
    std::cout << std::endl;

    delete impl;
    delete abst;

    impl = new ConcreteImplB;
    abst = new ExtendedAbstraction(impl);
    ClientCode(*abst);

    delete impl;
    delete abst;

    return 0;
}