#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <vector>
#include <iostream>

class Observer; // Target和Observer循环依赖，需要声明Observer

class Target
{
private:
    int state = 0;
    std::vector<Observer *> observers;

public:
    Target(int state) : state(state) {}
    ~Target() {}
    inline int getState() const { return state; }
    void setState(int state);
    void registe(Observer *observer);
    void notify();
};

class Observer
{
private:
    Target *target;

public:
    Observer(Target *target) : target(target) {}
    ~Observer() {}
    // ~Observer()// main方法中target栈上分配将自动调用Target的delete方法
    // {
    //     delete target;// error: double free or corruption (out)
    //     target = nullptr;
    // }
    inline Target *getTarget() const { return target; }
    virtual void observe() = 0;
};

class ObserverA : public Observer
{
public:
    ObserverA(Target *target) : Observer(target) {}
    ~ObserverA() {}
    void observe() override;
};

class ObserverB : public Observer
{
public:
    ObserverB(Target *target) : Observer(target) {}
    ~ObserverB() {}
    void observe() override;
};
#endif