#include "logger.h"

void Logger::setNextLogger(Logger *nextLogger)
{
    this->nextLogger = nextLogger;
}
void Logger::log(int level, const std::string &msg)
{
    if (level >= this->level)
    {
        write(msg);
    }
    if (nextLogger != nullptr)
    {
        nextLogger->log(level, msg);
    }
}

void InfoLogger::write(std::string msg)
{
    std::cout << "Info Logger: " << msg << std::endl;
}

void DebugLogger::write(std::string msg)
{
    std::cout << "Debug Logger: " << msg << std::endl;
}
void ErrorLogger::write(std::string msg)
{
    std::cout << "Error Logger: " << msg << std::endl;
}

Logger *ChainFactory::getChainOfLogger()
{
    Logger *infoLogger = new InfoLogger(Logger::INFO);
    Logger *debugLogger = new DebugLogger(Logger::DEBUG);
    Logger *errorLogger = new ErrorLogger(Logger::ERROR);

    errorLogger->setNextLogger(debugLogger);
    debugLogger->setNextLogger(infoLogger);
    return errorLogger;
}