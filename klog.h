#pragma once

enum {
	KLOG_MEMINFO,
	KLOG_INFO,
	KLOG_DEBUG,
	KLOG_WARN,
	KLOG_ERROR,
	KLOG_FATAL
};

#define KLOG_VERSION_MAJ 1
#define KLOG_VERSION_MIN 2

#include <stdio.h>
#include "klogbool.h"
#include <stdint.h>
#include <stddef.h>

void klog_set_silent(bool silent);
void klog_set_level(uint8_t level);
void klog_set_file(FILE *file);
int klog_file_init(const char *path);
int klog_file_close(void);
int klog(int level, int line, const char *func, char *fmt, ...);

/*if your project is C99 or newer you can use
 * these va macros to allow for less typing
 * when calling klog function
 */

#if __STDC_VERSION__ >= 199901

#define klog_info(...) klog(KLOG_INFO, __LINE__, __FUNCTION__, __VA_ARGS__)
#define klog_debug(...) klog(KLOG_DEBUG, __LINE__, __FUNCTION__, __VA_ARGS__)
#define klog_meminfo(...) klog(KLOG_MEMINFO, __LINE__, __FUNCTION__, __VA_ARGS__)
#define klog_warn(...) klog(KLOG_WARN, __LINE__, __FUNCTION__, __VA_ARGS__)
#define klog_error(...) klog(KLOG_ERROR, __LINE__, __FUNCTION__, __VA_ARGS__)
#define klog_fatal(...) klog(KLOG_FATAL, __LINE__, __FUNCTION__, __VA_ARGS__)

#endif

