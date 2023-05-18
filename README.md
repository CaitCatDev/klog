# Klog:
Klog is simple C logging library designed to be easyily dropped into any project.

# Compatiblity:
It should work with all C standard versions all the back to C89 so for the most part it should work with pretty much any compiler.

## Features:
- [x] Several different log levels.
- [x] Supports silencing and silencing by log levels
- [x] Supports opening a log file
- [x] Colorized stderr output

## How to use:

### Bulding:
A Makefile is provided however if you are on a system without make you can easily make it manually as there is only one C source file. Below are some examples of how to compile it. Of course remember to replace clang and llvm-ar with your own toolchain.
    ```sh
		#With make
		make

		#Without make static
		clang -c klog.c -o klog.o
		llvm-ar rcs libklog.a klog.o


		#Without make shared
		clang -fPIC -shared klog.c -o libklog.so
    ```

### Using:
To use with your own projects either include the shared/static object file in your compile command or install the library files under your `$LD_LIBRARY_PATH` and call the command with -lklog

To use in code see example below
```c
int main(int argc, char **argv) {
	klog(KLOG_INFO, __LINE__, __FUNCTION__, "Hello World\n");

}

```

### Install and Uninstall:
Install and uninstall targets are provided by the make file. By default Files are installed to `/usr/local` and can be changed by modifying the `$INSTALL_PREFIX` environtment variable
