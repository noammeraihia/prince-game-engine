#include "PGE/utils/pgeLogger.h"

namespace pge
{
    std::map<LogLevel, const char*> Logger::sLLvl2LStr;
    std::map<LogLevel, i32> Logger::sLLvl2LClr;
    bool Logger::sDebug = false;

    void Logger::Init()
    {
        sLLvl2LStr.insert(std::pair<LogLevel, const char*>(PGELLVL_FATAL, "FATAL"));
        sLLvl2LStr.insert(std::pair<LogLevel, const char*>(PGELLVL_ERROR, "ERROR"));
        sLLvl2LStr.insert(std::pair<LogLevel, const char*>(PGELLVL_INFO, "INFO"));
        sLLvl2LStr.insert(std::pair<LogLevel, const char*>(PGELLVL_WARN, "WARN"));
        sLLvl2LStr.insert(std::pair<LogLevel, const char*>(PGELLVL_DEBUG, "DEBUG"));

        sLLvl2LClr.insert(std::pair<LogLevel, i32>(PGELLVL_FATAL, FOREGROUND_RED | FOREGROUND_BLUE));
        sLLvl2LClr.insert(std::pair<LogLevel, i32>(PGELLVL_ERROR, FOREGROUND_RED));
        sLLvl2LClr.insert(std::pair<LogLevel, i32>(PGELLVL_INFO, 15));
        sLLvl2LClr.insert(std::pair<LogLevel, i32>(PGELLVL_WARN, FOREGROUND_RED | FOREGROUND_GREEN));
        sLLvl2LClr.insert(std::pair<LogLevel, i32>(PGELLVL_DEBUG, FOREGROUND_GREEN));
    }

    i32 Logger::Log(LogLevel lvl, const char* fmt, ...)
    {
        if (lvl != PGELLVL_DEBUG)
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(h, sLLvl2LClr.at(lvl));

            va_list arg;
            i32 done;

            time_t now = time(0);
            char* dt = ctime(&now);

            dt[strcspn(dt, "\n")] = 0;

            char prefix[255];
            sprintf(prefix, "PrinceGE - %s - [%s] : ", dt, sLLvl2LStr.at(lvl));

            char* final = strcat(prefix, fmt);

            va_start(arg, fmt);
            done = vfprintf(stdout, final, arg);
            va_end(arg);
            printf("\n");

            SetConsoleTextAttribute(h, 15);

            return done;
        }
        else if (sDebug)
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(h, sLLvl2LClr.at(lvl));

            va_list arg;
            i32 done;

            time_t now = time(0);
            char* dt = ctime(&now);

            dt[strcspn(dt, "\n")] = 0;

            char prefix[255];
            sprintf(prefix, "PrinceGE - %s - [%s] : ", dt, sLLvl2LStr.at(lvl));

            char* final = strcat(prefix, fmt);

            va_start(arg, fmt);
            done = vfprintf(stdout, final, arg);
            va_end(arg);
            printf("\n");

            SetConsoleTextAttribute(h, 15);

            return done;
        }

        return -1;
    }
}