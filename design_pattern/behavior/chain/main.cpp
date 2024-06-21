#include "logger.h"
// g++ *.cpp -std=c++11
int main()
{
    Logger *chainOfLogger = ChainFactory::getChainOfLogger();
    chainOfLogger->log(Logger::INFO, "This is info level information");
    std::cout << "#########" << std::endl;
    chainOfLogger->log(Logger::ERROR, "This is error level information");

    // 因为Logger析构函数中delete了nextLogger，因此debugLogger，infoLogger将被递归清除
    delete chainOfLogger;
    chainOfLogger = nullptr;
}