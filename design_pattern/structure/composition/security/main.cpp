#include "component.h"

// g++ *.cpp -std=c++11
int main()
{
    Composite *composite0 = new Composite("composite0");
    Composite *composite1 = new Composite("composite1");
    Component *leaf1 = new Leaf("leaf1");
    Component *leaf2 = new Leaf("leaf2");
    Component *leaf3 = new Leaf("leaf3");
    composite0->add(leaf1);
    composite0->add(composite1);
    composite1->add(leaf2);
    composite1->add(leaf3);
    composite0->operate();

    delete composite0;
    delete composite1;
    delete leaf1;
    delete leaf2;
    delete leaf3;
    composite0 = nullptr;
    composite1 = nullptr;
    leaf1 = nullptr;
    leaf2 = nullptr;
    leaf3 = nullptr;
    return 0;
}