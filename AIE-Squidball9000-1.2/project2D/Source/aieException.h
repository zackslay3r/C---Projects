#pragma once

#include <string>
#include <sstream>

#define aieTHROW( stream_ ) do {                                            \
    std::ostringstream oss_;                                                \
    oss_ << stream_;                                                        \
    throw aie::Exception( oss_.str(), __FILE__, __LINE__ ); } while(0)  

#define aieASSERT( condition_ ) do {                                        \
    if( ! (condition_) ) aieTHROW( "aie assertion failure" ); } while(0)

namespace aie
{
    // Class 'Exception' provides a robust exception-handling mechanism. It is 
    // designed to be as simple as possible to use (e.g. no severity levels or 
    // other complications) for the calling code.
    class Exception
    {
    public:

        //---------------------------------------
        // Static Methods
        //---------------------------------------

        // When logging is enabled, all exceptions thrown via the Exception class
        // will write there details into the application log (see aieLog.h).
        static void enableLogging( bool enable );

        // Returns true if logging is currently enabled.
        static bool isLoggingEnabled();


        //---------------------------------------
        // Public Methods
        //---------------------------------------

        // Constructs *this with a text reason and (optionally) the file and line
        // number where the exception occurred. The file and line number arguments
        // are supplied automatically if the 'coreTHROW' macro is used (see above).
        Exception( const std::string & reason, 
                   const char *fileName = 0, 
                   int lineNumber = 0 );

        // Sets a new reason, file and line number.
        void set( const std::string & reason, 
                  const char *fileName = 0, 
                  int lineNumber = 0 );

        ~Exception();


        //---------------------------------------
        // Attributes
        //---------------------------------------

        const std::string & fileName() const;

        const std::string & reason() const;

        int lineNumber() const;

    private:
        std::string m_reason;
        std::string m_fileName;
        int m_lineNumber;
        static bool g_logging;
    };

} // namespace core

