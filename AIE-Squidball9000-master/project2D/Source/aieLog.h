#pragma once

#include <string>
#include <sstream>

#include "aieNonCopyable.h"

#define aieLOG( stream_ ) do {                                              \
    std::ostringstream oss_;                                                \
    oss_ << stream_;                                                        \
    aie::Log::instance().append( oss_.str() ); } while(0)  

namespace aie
{
    // Class 'Log' provides a basic file logging service that can be used throughout
    // a complete code base. Class Log is also associated with the exception-handling 
    // mechanism (see aieException.h). A log can be set up at run-time by the application.
    // All logging calls made within the application (including exceptions) will then
    // also appear in the application's log. 
    // SHARING - The same log file can be safely shared among multiple threads
    // or processes. This is why the time output to the log file is Windows absolute
    // time (rather than app time) so that time-stamps can be interleaved when
    // logging from separate processes.
    class Log : private NonCopyable
    {
    public:

        // The single instance of the Log (i.e. Log is a singleton).
        static Log & instance();

        // Specifies an ASCII file to serve as the logging destination. The file
        // will be created automatically if it doesn't already exist.
        void setLog( const std::string & filePath, bool erase = true );

        // Append an entry into the log.
        void append( const std::string & text );

        const std::string & filePath() const;

    private:
        Log();
        ~Log();
    };

} // namespace aie

