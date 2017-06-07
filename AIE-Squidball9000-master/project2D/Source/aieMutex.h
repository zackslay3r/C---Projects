#pragma once

#include <Windows.h>
#include "aieNonCopyable.h"

namespace aie
{
    // CLass 'Mutex' implements a logical mutex object (note, NOT the Windows
    // MUTEX object) that can be used to protect code across multiple threads.
    // It is based internally on the Windows Critical Section, a very light-weight
    // mechanism for thread synchronization. This class is designed to be used
    // with aie::Lock rather than by itself.
    class Mutex : private NonCopyable
    {
    public:

        Mutex();
        ~Mutex();

    private:
        CRITICAL_SECTION m_cs;

        friend class Lock;
        void lock();
        void unlock();
    };

} // namespace core

