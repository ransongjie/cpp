#include <iostream>
#include "decorator.h"
using namespace ::std;

#ifndef DELETE_OBJECT
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#endif

/*
g++ main.cpp
*/
int main()
{
    Phone *iphone = new iPhone();
    Phone *nokia = new Nokia();

    //装饰器放入被装饰对象
    Phone *diphone = new iPhoneDecorator(iphone);
    cout << diphone->function() << endl;
    cout << diphone->surface() << endl;

    Phone *dnokia = new NokiaDecorator(nokia);
    cout << dnokia->function() << endl;
    cout << dnokia->surface() << endl;

    DELETE_OBJECT(iphone);
    DELETE_OBJECT(nokia);
    DELETE_OBJECT(diphone);
    DELETE_OBJECT(dnokia);
}