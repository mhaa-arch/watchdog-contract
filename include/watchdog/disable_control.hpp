#ifndef MHAA_WATCHDOG_DISABLE_CONTROL_HPP
#define MHAA_WATCHDOG_DISABLE_CONTROL_HPP

#include <watchdog/controller.hpp>
#include <watchdog/types.hpp>

namespace mhaa
{
    namespace watchdog
    {
        /** @brief Exposes watchdog disable when the target implements it. */
        class DisableControl : public Controller
        {
        public:
            virtual Status disable() = 0;
        };
    }
}

#endif
