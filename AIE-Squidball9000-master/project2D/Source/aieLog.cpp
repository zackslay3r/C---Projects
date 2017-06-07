#include "aieLog.h"
#include "aieLock.h"
#include "aieTimer.h"
#include "aieException.h"
#include <string>
#include <Windows.h>


namespace // anon
{
    std::string g_logFile = "";
    aie::Log *g_log = 0;
    aie::Timer g_timer;
    HANDLE g_mutex = 0;

} // namespace


/*******************************************************************************
********************************************************************************/
aie::Log::Log()
{
    g_log = this;
    g_timer.start();
}

/*******************************************************************************
********************************************************************************/
aie::Log::~Log()
{
    g_log = 0;
}

/*******************************************************************************
********************************************************************************/
aie::Log & aie::Log::instance()
{
    if (g_mutex == 0)
    {
        g_mutex = ::CreateMutex(NULL, FALSE, "@@_CoreLogMutex_@@");
        if (!g_mutex)
            aieTHROW("Failed creating core::Log mutex");
    }

    static Log log;
    return log;
}

/*******************************************************************************
********************************************************************************/
void aie::Log::append( const std::string & text )
{
    if( g_logFile != "" )
    {
        if (!g_mutex)
            aieTHROW("core::setLog - no mutex");

        if (::WaitForSingleObject(g_mutex, 5000) != WAIT_OBJECT_0)
            aieTHROW("core::setLog - timeout");

        FILE *f;
        if (fopen_s(&f, g_logFile.c_str(), "a+b") == 0)
        {
            fprintf(f, "%12.3lf  %s\r\n", (double)(::GetTickCount()) / 1000.0, text.c_str());
            fclose(f);
        }

        ::ReleaseMutex(g_mutex);
    }
}

/*******************************************************************************
********************************************************************************/
const std::string & aie::Log::filePath() const
{
    return g_logFile;
}

/*******************************************************************************
********************************************************************************/
void aie::Log::setLog( const std::string & filePath, bool erase )
{
    g_logFile = "";

    if( filePath != "" )
    {
        if (!g_mutex)
            aieTHROW("core::setLog - no mutex");

        if (::WaitForSingleObject(g_mutex, 5000) != WAIT_OBJECT_0)
            aieTHROW("core::setLog - timeout");

        if (erase)
            ::remove(filePath.c_str());

        FILE *f;
        if (fopen_s(&f, filePath.c_str(), "a+b") == 0)
        {
            fclose(f);
            g_logFile = filePath;
        }

        ::ReleaseMutex(g_mutex);
    } 
}
