#include "factory.hpp"

int main() {
    Factory *factory = new Factory();
    AbstractProduct *pa = factory->create_product("ProductA");
    AbstractProduct *pb = factory->create_product("ProductB");
    pa->do_something();
    pb->do_something();
    delete pa;
    delete pb;
    delete factory;
    return 0;
}