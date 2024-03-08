#ifndef __BACKTRACE_H__
#define __BACKTRACE_H__

#include <stdio.h>

// crash trace enable
#define CRASH_TRACE_ENABLE   1

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void crash_trace_init(void);
void crash_trace_deinit(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // !__BACKTRACE_H__
