

#pragma once
#include <string>
#include <sstream>

// This is based off of example code given to us by our teacher, Jeff Cotter.
// I am using this becuase it provides a more graceful way to allow throws and asserts to be done.

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