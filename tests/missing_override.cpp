#include <watchdog/controller.hpp>

using namespace mhaa::watchdog;

class Incomplete final : public Controller
{
public:
    Status service() override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
