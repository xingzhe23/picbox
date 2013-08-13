#ifndef _LOGGER_H
#define _LOGGER_H

#include <fstream>
#include <string>

static const char* logFile = "d:\\picBox.log";

template<typename T1>
void Logger(T1 v1)
{
    std::fstream fs;
    fs.open(logFile, std::ios::app|std::ios::in|std::ios::out);
    fs << " " <<v1 << "\n" << std::endl;
    fs.close();
}

template<typename T1, typename T2>
void Logger(T1 v1, T2 v2)
{
    std::fstream fs;
    fs.open(logFile, std::ios::app|std::ios::in|std::ios::out);
    fs << " " <<v1 << " " <<v2 << "\n" << std::endl;
    fs.close();
}

template<typename T1, typename T2, typename T3>
void Logger(T1 v1, T2 v2, T3 v3)
{
    std::fstream fs;
    fs.open(logFile, std::ios::app|std::ios::in|std::ios::out);
    fs << " " <<v1 << " " <<v2 << " " <<v3 << "\n" << std::endl;
    fs.close();
}

template<typename T1, typename T2, typename T3, typename T4>
void Logger(T1 v1, T2 v2, T3 v3, T4 v4)
{
    std::fstream fs;
    fs.open(logFile, std::ios::app|std::ios::in|std::ios::out);
    fs << " " <<v1 << " " <<v2 << " " <<v3 << " " <<v4 <<"\n" << std::endl;
    fs.close();
}

template<typename T1, typename T2, typename T3, typename T4, typename T5>
void Logger(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5)
{
    std::fstream fs;
    fs.open(logFile, std::ios::app|std::ios::in|std::ios::out);
    fs << " " <<v1 << " " <<v2 << " " <<v3 << " " <<v4 << " " <<v5 << "\n" << std::endl;
    fs.close();
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
void Logger(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
{
    std::fstream fs;
    fs.open(logFile, std::ios::app|std::ios::in|std::ios::out);
    fs << " " <<v1 << " " <<v2 << " " <<v3 << " " <<v4 << " " <<v5 << " " <<v6 << "\n" << std::endl;
    fs.close();
}



#endif