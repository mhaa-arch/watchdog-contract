#include <watchdog/controller.hpp>

using namespace mhaa::watchdog;

class WrongOverride final : public Controller
{
public:
    Status configure(uint32_t timeout_ms, Mode mode) const override;
};
