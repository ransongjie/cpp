#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <string>
#include <iostream>

class Logger
{
protected:
    // 避免野指针
    Logger *nextLogger = nullptr;
    int level = 0;
    virtual void write(std::string msg) = 0;

public:
    static const int INFO = 1;
    static const int DEBUG = 2;
    static const int ERROR = 3;
    Logger() {}
    inline Logger(int level) : level(level) {}
    virtual ~Logger()
    {
        delete nextLogger;
        nextLogger = nullptr;
    }
    void setNextLogger(Logger *nextLogger);
    void log(int level, const std::string &msg);
};

class InfoLogger : public Logger
{
public:
    InfoLogger() {}
    InfoLogger(int level) : Logger(level) {}
    ~InfoLogger() {}

protected:
    void write(std::string msg) override;
};

class DebugLogger : public Logger
{
public:
    DebugLogger() {}
    DebugLogger(int level) : Logger(level) {}
    ~DebugLogger() {}

protected:
    void write(std::string msg) override;
};

class ErrorLogger : public Logger
{
public:
    ErrorLogger() {}
    ErrorLogger(int level) : Logger(level) {}
    ~ErrorLogger() {}

protected:
    void write(std::string msg) override;
};

class ChainFactory
{
public:
    static Logger *getChainOfLogger();
};

#endif