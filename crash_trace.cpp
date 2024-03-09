#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // stderror
#include <signal.h> // signal
#include <execinfo.h> // backtrace, backtrace_symbols, backtrace_symbols_fd
#include <dlfcn.h> // dladdr
#include <cxxabi.h> // abi::__cxa_demangle

#include "crash_trace.h"

void crash_trace_dump(int signum)
{
    void *bt_buffer[256];
	size_t size = backtrace(bt_buffer, 256);

	// Dump the backtrace to stderr with a message to the user
	printf("\n================================================================\n");
	printf("%s: Program crashed with signal %d\n", __FUNCTION__, signum);

	char **strings = backtrace_symbols(bt_buffer, size);
	if (strings) 
    {
		for (size_t i = 1; i < size; i++) 
        {
			char fname[1024];
			Dl_info info;

			snprintf(fname, 1024, "%s", strings[i]);

			// Try to demangle the function name to provide a more readable one
			if (dladdr(bt_buffer[i], &info) && info.dli_sname) 
            {
				if (info.dli_sname[0] == '_') 
                {
					int status = 0;
					char *demangled = abi::__cxa_demangle(info.dli_sname, nullptr, nullptr, &status);

					if (status == 0 && demangled) 
                    {
						snprintf(fname, 1024, "%s", demangled);
					}
					if (demangled) 
                    {
						free(demangled);
					}
				}
			}

			printf("[%lu] %s\n", i, fname);
		}

		free(strings);
	}
	printf("-- END OF BACKTRACE --\n");
	printf("================================================================\n");
}

static void signal_handler(int signum)
{
    crash_trace_dump(signum);

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
