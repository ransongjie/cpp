#include "observer.h"

void ObserverA::observe()
{
    std::cout << "observer A, target state is changed into "
              << this->getTarget()->getState()
              << std::endl;
}

void ObserverB::observe()
{
    std::cout << "observer B, target state is changed into "
              << this->getTarget()->getState()
              << std::endl;
}

// 状态变化，通知所有观察者
void Target::setState(int state)
{
    this->state = state;
    notify();
}
void Target::registe(Observer *observer)
{
    observers.push_back(observer);
}
void Target::notify()
{
    for (int i = 0; i < observers.size(); i++)
    {
        observers[i]->observe();
    }
}