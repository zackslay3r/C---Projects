
#pragma once
#include <string>
#include <sstream>

/**
* Error handling macros.
* Usage example:
*    eASSERT(someValue < 0);
*    if (!fileHandle) eTHROW("Could not open file.");
* Catch example:
*    try
*    {
*        //Some code that may throw errors using eTHROW and eASSERT goes here...
*    }
*    catch (const std::exception &e)
*    {
*        std::cerr << "Error: " << e.what() << std::endl;
*    }
*    catch ( ... )
*    {
*        std::cerr << "Unspecified error." << std::endl;
*    }
* @This is based off of example code given to us by our teacher, Jeff
*/

#define eTHROW( errormessage ) do { \
    std::ostringstream oss; \
    oss << errormessage; \
    /*Remove file path, so we end up with just the file name.*/ \
    const char *name = strrchr( __FILE__, '\\' ); \
    if (name) \
    { \
        name++; \
    } \
    else if (name == 0) \
    { \
        /*We may be on an OS that uses the alternate slash for paths.*/ \
        name = strrchr(__FILE__, '/'); \
        if (name) name++; \
    } \
    if (name == 0) name = __FILE__; \
    std::string eMessage = "\"" + oss.str() + "\" File: " + name + ". Line: " + std::to_string(__LINE__) + "."; \
    throw std::runtime_error(eMessage); } while(0)  

#define eASSERT( condition ) do { if( !(condition) ) eTHROW( "Assertion Failure" ); } while(0)