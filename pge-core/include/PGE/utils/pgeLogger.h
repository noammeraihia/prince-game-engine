#pragma once

#include <stdio.h>

namespace pge
{
    #define PGE_LOGGER_LOG_PRESET(PRIO, PRIO_NAME)\
        if (sPriority <= PRIO)\
        {\
            printf("PGE [%s] ->\t", PRIO_NAME);\
            printf(message, args...);\
            printf("\n");\
        }

    enum LogPriority
    {
        LPTRACE,
        LPDEBUG,
        LPINFO,
        LPWARN,
        LPERROR,
        LPCRITICAL
    };

    class Logger
    {
    public:
        static void setPriority(LogPriority new_priority);

        template <typename... Args>
        static void trace(const char* message, Args... args);
        template <typename... Args>
        static void debug(const char* message, Args... args);
        template <typename... Args>
        static void info(const char* message, Args... args);
        template <typename... Args>
        static void warn(const char* message, Args... args);
        template <typename... Args>
        static void error(const char* message, Args... args);
        template <typename... Args>
        static void critical(const char* message, Args... args);

    private:
        static LogPriority sPriority;
    };

    #define PGE_LOG_TRACE(message, ...)\
        pge::Logger::setPriority(LPTRACE);\
        pge::Logger::trace(##message);

    #define PGE_LOG_DEBUG(message, ...)\
        pge::Logger::setPriority(LPDEBUG);\
        pge::Logger::debug(##message);

    #define PGE_LOG_INFO(message, ...)\
        pge::Logger::setPriority(LPINFO);\
        pge::Logger::info(##message);

    #define PGE_LOG_WARN(message, ...)\
        pge::Logger::setPriority(LPWARN);\
        pge::Logger::warn(##message);

    #define PGE_LOG_ERROR(message, ...)\
        pge::Logger::setPriority(LPERROR);\
        pge::Logger::error(##message);

    #define PGE_LOG_CRITICAL(message, ...)\
        pge::Logger::setPriority(LPCRITICAL);\
        pge::Logger::critical(##message);
}