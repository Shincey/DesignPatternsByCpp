#include <iostream>
#include <string>

using namespace std;

class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};

class Decorator : public Component {
protected:
    Component *_comp;

public:
    Decorator(Component *comp) : _comp(comp) {}

    std::string Operation() const override {
        return this->_comp->Operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component *comp) : Decorator(comp) {}

    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component *comp) : Decorator(comp) {}

    std::string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component *comp) {
    std::cout << "Result: " << comp->Operation() << std::endl;
}

int main() {
    Component *comp = new ConcreteComponent;
    std::cout << "Client: I've got a simple component." << std::endl;
    ClientCode(comp);

    Component *dec1 = new ConcreteDecoratorA(comp);
    Component *dec2 = new ConcreteDecoratorB(dec1);
    std::cout << "Client: I've got a decorated component." << std::endl;
    ClientCode(dec2);

    delete comp;
    delete dec1;
    delete dec2;
    
    return 0;
}