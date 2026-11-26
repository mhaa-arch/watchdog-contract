# Porting the Watchdog Contract

Hardware Definitions can describe nominal hardware selections, clock tolerance, window facilities and configuration lock constraints. The Adapter maps exact nominal periods and documents supported modes and timing. Actual reset deadlines vary across devices and operating conditions. A successful host fake checks the API sequence, not reset timing.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
