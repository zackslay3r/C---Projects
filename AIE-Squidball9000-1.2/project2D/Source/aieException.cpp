#include "aieException.h"
#include "aieLog.h"

bool aie::Exception::g_logging = true;


/******************************************************************************
*******************************************************************************/
aie::Exception::Exception( const std::string & reason, 
                            const char *fileName, int lineNum ) 
{
    set( reason, fileName, lineNum );
}

/******************************************************************************
*******************************************************************************/
aie::Exception::~Exception()
{
}

/******************************************************************************
*******************************************************************************/
void aie::Exception::enableLogging( bool enable )
{
    g_logging = enable;
}

/******************************************************************************
*******************************************************************************/
const std::string & aie::Exception::fileName() const
{
    return m_fileName;
}

/******************************************************************************
*******************************************************************************/
bool aie::Exception::isLoggingEnabled()
{
    return g_logging;
}

/******************************************************************************
*******************************************************************************/
int aie::Exception::lineNumber() const
{
    return m_lineNumber;
}

/******************************************************************************
*******************************************************************************/
const std::string & aie::Exception::reason() const
{
    return m_reason;
}

/******************************************************************************
*******************************************************************************/
void aie::Exception::set( const std::string & reason,
                          const char *fileName, 
                          int lineNum )
{
    m_reason = reason;
    if( fileName )
        m_fileName = fileName;
    m_lineNumber = lineNum;

    if( g_logging && fileName )
    {
        // Extract file name only
        const char *name = strrchr( fileName, '\\' );
        if( name ) 
            name++;
        else if( 0 == name )
        {
            name = strrchr( fileName, '/' );
            if( name )
                name++;
        }
        if( 0 == name )
            name = fileName;
        char nameBuf[100];
        strncpy_s( nameBuf, name, sizeof(nameBuf) - 2 );

        // Strip off the file extension
        char *ext = strrchr( nameBuf, '.' );
        if( ext )
            *ext = 0;

        // Build the fully-formatted string
        static char str[5000];
        _snprintf_s( str, sizeof(str) - 10, "%s (%s %ld)", 
            reason.c_str(), nameBuf, lineNum );

        aieLOG( str );
    }
}

