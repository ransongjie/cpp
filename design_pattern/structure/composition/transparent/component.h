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
    virtual void add(Component *c) = 0;
    virtual void del(Component *c) = 0;
    virtual Component *get(const std::string &name) const = 0;
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
    void add(Component *c) override;
    void del(Component *c) override;
    Component *get(const std::string &name) const override;
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
    void add(Component *c) override;
    void del(Component *c) override;
    Component *get(const std::string &name) const override;
    void operate() override;
};

#endif