#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <map>


namespace pge
{
    enum LogLevel 
    {
        PGELLVL_FATAL,
        PGELLVL_ERROR,
        PGELLVL_INFO,
        PGELLVL_WARN,
        PGELLVL_DEBUG 
    };

    class Logger
    {
    public:

        static void Init();
        static int Log(LogLevel lvl, const char* fmt, ...);

    private:
        static std::map<LogLevel, const char*> sLLvl2LStr;
        static std::map<LogLevel, int> sLLvl2LClr;
    };
}

#define PGE_LOG pge::Logger::Log