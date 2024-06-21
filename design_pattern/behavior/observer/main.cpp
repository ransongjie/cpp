#include "observer.h"
// g++ *.cpp -std=c++11
int main()
{
    Target target(1);
    ObserverA observera(&target);
    ObserverB observerb(&target);
    ObserverB observerc(&target);
    target.registe(&observera);
    target.registe(&observerb);
    target.registe(&observerc);
    target.setState(2);
}