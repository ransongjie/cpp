#include "component.h"
#include <iostream>
#include <algorithm>
void Leaf::add(Component *c) {}
void Leaf::del(Component *c) {}
Component *Leaf::get(const std::string &name) const
{
    return nullptr;
}
void Leaf::operate()
{
    std::cout << this->getName() << " is visited." << std::endl;
}

void Composite::add(Component *c)
{
    components->push_back(c);
}
void Composite::del(Component *c)
{
    auto it = std::find(components->begin(), components->end(), c);
    if (it != components->end())
    {
        components->erase(it);
    }
}
Component *Composite::get(const std::string &name) const
{
    auto it = std::find_if(components->begin(), components->end(), [&name](const Component *c)
                           { return c->getName() == name; });
    if (it == components->end())
    {
        return nullptr;
    }
    return *it; // 获取it指向的元素
}
void Composite::operate()
{
    std::cout << this->getName() << " is visited." << std::endl;
    for (int i = 0; i < components->size(); i++)
    {
        auto c = (*components)[i];
        c->operate();
    }
}