#ifndef MHAA_WATCHDOG_TYPES_HPP
#define MHAA_WATCHDOG_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace watchdog
    {
        enum class Mode
        {
            Reset,
            Interrupt,
            InterruptThenReset
        };
        enum class Status
        {
            Success,
            InvalidArgument,
            Unsupported,
            Locked,
            Error
        };
    }
}

#endif
