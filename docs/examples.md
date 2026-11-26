# Watchdog Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The fake declines a 100 ms reset timeout and accepts 2000 ms. It then allows one explicit service after the test opens its simulated window. The conformance program disables the fake and verifies that later service is locked. The simulated window is a test input, not a clock or scheduler.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <watchdog/controller.hpp>
#include <watchdog/disable_control.hpp>


using namespace mhaa::watchdog;

class Fake final : public DisableControl
{
public:
    Status configure(uint32_t timeout_ms, Mode mode) override
    {
        if (mode != Mode::Reset || timeout_ms != 2000)
        {
            return Status::Unsupported;
        }
        armed = true;
        return Status::Success;
    }
    Status service() override
    {
        if (!armed || !window_open)
        {
            return Status::Locked;
        }
        ++services;
        return Status::Success;
    }
    Status disable() override
    {
        armed = false;
        return Status::Success;
    }

    bool armed = false;
    bool window_open = false;
    unsigned services = 0;
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
