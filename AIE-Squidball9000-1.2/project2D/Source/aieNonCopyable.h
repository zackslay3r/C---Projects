#pragma once

namespace aie
{
    // Class 'NonCopyable' implements that standard C++ idiom of making it impossible
    // to copy an object (accidentally or otherwise) by making its assignment operator 
    // and copy constructor private. This can be useful when you want to guarantee
    // that an object that is not deep-copyable cannot ever be copied. To use, 
    // just inherit from this class.
    class NonCopyable 
    {
    protected :

        NonCopyable() {}
        ~NonCopyable() {}

    private:

        NonCopyable( const NonCopyable & );
        const NonCopyable & operator=( const NonCopyable & );
    };

} // namespace aie

