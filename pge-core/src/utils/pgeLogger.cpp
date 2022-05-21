#include "PGE/utils/pgeLogger.h"

namespace pge 
{
    void Logger::setPriority(LogPriority priority)
    {
        sPriority = priority;
    }

    template <typename... Args>
    void Logger::trace(const char* message, Args... args){ PGE_LOGGER_LOG_PRESET(LPTRACE, "TRACE"); }

    template <typename... Args>
    void Logger::debug(const char* message, Args... args) { PGE_LOGGER_LOG_PRESET(LPDEBUG, "DEBUG"); }

    template <typename... Args>
    void Logger::info(const char* message, Args... args) { PGE_LOGGER_LOG_PRESET(LPINFO, "INFO"); }

    template <typename... Args>
    void Logger::warn(const char* message, Args... args) { PGE_LOGGER_LOG_PRESET(LPWARN, "WARNING"); }

    template <typename... Args>
    void Logger::error(const char* message, Args... args) { PGE_LOGGER_LOG_PRESET(LPERROR, "ERROR"); }

    template <typename... Args>
    void Logger::critical(const char* message, Args... args) { PGE_LOGGER_LOG_PRESET(LPCRITICAL, "CRITICAL"); }

}