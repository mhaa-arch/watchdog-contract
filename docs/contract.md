# Watchdog contract

## Request an exact nominal period

[Controller](../include/watchdog/controller.hpp) accepts a positive nominal `timeout_ms` and one of reset, interrupt or interrupt-then-reset. Reject an unsupported period or mode as `Unsupported` without silently rounding the period. Use `Locked` for a request prohibited by the current state and `InvalidArgument` for a zero timeout. Publish supported nominal values and actual tolerance in target integration. Configuration is an arming operation, so it is not a discovery mechanism.

## Service or disable

`service` requires an armed watchdog and a permitted instant on windowed hardware. Report `Locked` when rejection can be done safely. Some hardware can reset if serviced too early. [DisableControl](../include/watchdog/disable_control.hpp) extends the same watchdog when disabling is possible. Always-on targets can supply only the base.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`watchdog/types.hpp`](../include/watchdog/types.hpp).
