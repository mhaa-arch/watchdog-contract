#ifndef MHAA_WATCHDOG_CONTROLLER_HPP
#define MHAA_WATCHDOG_CONTROLLER_HPP

#include <stdint.h>
#include <watchdog/types.hpp>

namespace mhaa
{
    namespace watchdog
    {
        /** @brief Configures and services the watchdog of one target resource. */
        class Controller
        {
        public:
            virtual ~Controller() = default;

            /** @brief Requests an exact positive nominal timeout in milliseconds. */
            virtual Status configure(uint32_t timeout_ms, Mode mode) = 0;

            /** @brief Services an armed watchdog at a permitted time. */
            virtual Status service() = 0;
        };
    }
}

#endif
