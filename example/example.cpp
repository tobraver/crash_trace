#include "stdio.h"
#include "../crash_trace.h"

void fun3(void)
{
    int *p = NULL;
    *p = 1024;
}

/* "static" means don't export the symbol... */
static void fun2(void)
{
    fun3();
}

void fun1(void)
{
    fun2();
}

int main(int argc, char const *argv[])
{
    crash_trace_init();

    printf("example start!\n");

    fun1();
    
    printf("example end!\n");
    return 0;
}
