# 项目功能

用于管理 `Linux` 的 `SIGSEGV` `SIGABRT`；打印相关的追溯日志；

# 项目使用

`add_subdirectory(format)`

添加编译选项：`-g -rdynamic`

```
This is needed for our crash handler to work properly.
gdb works fine without it though, so maybe our crash handler could too.
```


# 项目参考

[backtrace 使用说明](https://www.cnblogs.com/muahao/p/7610645.html)

[GCC Options for Linking](https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#index-rdynamic)

[参考连接](https://github.com/godotengine/godot/blob/aef11a1/platform/linuxbsd/crash_handler_linuxbsd.h)

