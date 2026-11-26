#include <watchdog/controller.hpp>
#include <watchdog/disable_control.hpp>

#include <cassert>

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

int main()
{
    Fake fake;
    DisableControl &control = fake;
    assert(control.configure(100, Mode::Reset) == Status::Unsupported);
    assert(control.configure(2000, Mode::Reset) == Status::Success);
    fake.window_open = true;
    assert(control.service() == Status::Success);
    assert(control.disable() == Status::Success);
    assert(control.service() == Status::Locked);
}
