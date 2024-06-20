#include "./include/proxy.h"
#include <iostream>

void BrideGroom::wed()
{
    std::cout << "新郎新娘结婚" << std::endl;
}

void WedCompany::wed()
{
    std::cout << "婚庆公司代理布置婚礼现场" << std::endl;
    this->brideGroom.wed();
    std::cout << "婚庆公司代理收拾婚礼现场" << std::endl;
}