#pragma once

namespace aie
{
    // 'Timer' is a simple stop-watch style timer that offers high precision and
    // fast performance. It will use the high-performance hardware counter if one 
    // is available. The high-performance counter provides microsecond accuracy
    // (unlike the built-in Windows timer, which is only millisecond accurate).
    class Timer
    {
    public:

        Timer();

        // Starts the timer running. Time will be counted from the moment that 
        // the timer starts. Note that once the timer has been started, nothing
        // internal actually happens, i.e. there is no overhead with a running
        // timer. The only overhead that occurs is when 'elapsed' is called.
        // Thus, it is possible to have large numbers of timers running in an
        // application with no performance hit (at least until 'elapsed' is called).
        void start();

        // Stops the timer.
        void stop();

        // Returns the length of time elapsed since the Timer was started (in seconds).
        double elapsed() const;

        // Returns true if the Timer is currently running (i.e. has been started
        // but not yet stopped).
        bool running() const;

        // Returns true if the Timer is using the hardware high-performance counter,
        // otherwise the time is obtained from operating system calls (less accurate).
        bool isHighPerformance() const;

    private:
        double m_frequency;       // counts per second
        __int64 m_startTime;
        bool m_isHighPerformance;
        bool m_running;
    };

} // namespace aie

