#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include <string>
#include <vector>
class Component
{
private:
    std::string name;

public:
    Component(const std::string &name) : name(name) {}
    virtual ~Component() {}
    virtual void operate() = 0;
    inline std::string getName() const
    {
        return name;
    }
};

class Leaf : public Component
{
public:
    Leaf(const std::string &name) : Component(name) {}
    virtual ~Leaf() {}
    void operate() override;
};

class Composite : public Component
{
private:
    // 定义初始化
    std::vector<Component *> *components = new std::vector<Component *>();

public:
    Composite(const std::string &name) : Component(name) {}
    virtual ~Composite()
    {
        delete components;
        components = nullptr;
    }
    void add(Component *c);
    void del(Component *c);
    Component *get(const std::string &name) const;
    void operate() override;
};

#endif