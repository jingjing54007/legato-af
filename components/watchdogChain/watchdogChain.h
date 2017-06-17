//--------------------------------------------------------------------------------------------------
/** @file watchdogChain.c
 *
 * Provides a watchdog chain to allow multiple tasks in a process to cooperate in kicking the
 * watchdog.  The watchdog will be kicked when all non-stopped tasks on the chain have requested
 * a kick.
 *
 * Copyright (C) Sierra Wireless Inc.
 */
//--------------------------------------------------------------------------------------------------

#ifndef LEGATO_WATCHDOG_CHAIN_INCLUDE_GUARD
#define LEGATO_WATCHDOG_CHAIN_INCLUDE_GUARD

//--------------------------------------------------------------------------------------------------
/**
 * Start watchdogs 0..N-1.  Typically this is used in COMPONENT_INIT to start all watchdogs needed
 * by the process.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void le_wdogChain_Init
(
    uint32_t wdogCount
);

//--------------------------------------------------------------------------------------------------
/**
 * Begin monitoring the event loop on the current thread.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void le_wdogChain_MonitorEventLoop
(
    uint32_t watchdog,          ///< Watchdog to use for monitoring
    le_clk_Time_t watchdogInterval ///< Interval at which to check event loop is functioning
);


//--------------------------------------------------------------------------------------------------
/**
 * Kick a watchdog on the chain.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void le_wdogChain_Kick
(
    uint32_t watchdog
);

//--------------------------------------------------------------------------------------------------
/**
 * Stop a watchdog.
 *
 * This can also cause the chain to be completely kicked, so check it.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void le_wdogChain_Stop
(
    uint32_t watchdog
);

#endif /* LEGATO_WATCHDOG_CHAIN_INCLUDE_GUARD */
