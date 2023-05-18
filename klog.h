#pragma once

enum {
	KLOG_MEMINFO,
	KLOG_INFO,
	KLOG_DEBUG,
	KLOG_WARN,
	KLOG_ERROR,
	KLOG_FATAL
};

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
