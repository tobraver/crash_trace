#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // stderror
#include <signal.h> // signal
#include <execinfo.h> // backtrace, backtrace_symbols, backtrace_symbols_fd

#include "crash_trace.h"

void backtrace_dump(void)
{
    int nptrs;

#define SIZE 100
    void *buffer[SIZE];

    nptrs = backtrace(buffer, SIZE);
    backtrace_symbols_fd(buffer, nptrs, STDERR_FILENO);
}

static void signal_handler(int signum)
{
    backtrace_dump(); // dump backtrace info

    signal(signum, SIG_DFL); // recover signal
    raise(signum);
}

void crash_trace_init(void)
{
#if CRASH_TRACE_ENABLE
    signal(SIGSEGV, signal_handler);
    signal(SIGABRT, signal_handler);
#endif
}

void crash_trace_deinit(void)
{
#if CRASH_TRACE_ENABLE
    signal(SIGSEGV, SIG_DFL); // recover signal
    signal(SIGABRT, SIG_DFL); // recover signal
#endif
}
