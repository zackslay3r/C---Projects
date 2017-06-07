#pragma once

#include "aieMutex.h"
#include "aieNonCopyable.h"

namespace aie
{
    // Class 'Lock' implements the Scoped Lock pattern. To use, instantiate
    // lock objects in multiple threads that all reference a shared global mutex. 
    // All code within the scope of the lock will then be thread-safe.
    class Lock : private NonCopyable
    {
    public:

        Lock( aie::Mutex & mutex );

        ~Lock();

    private:
        Mutex & m_mutex;
    };

} // namespace core

