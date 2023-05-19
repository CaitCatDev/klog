#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "klog.h"

typedef struct _klog_cfg_s {
	uint8_t level;
	bool silent;
	const char *progname;

	FILE *file;
} klog_cfg_t;

static klog_cfg_t klog_cfg = {
	KLOG_WARN,
	0,
	"klog",
	NULL
};

void klog_set_silent(bool silent) {
	klog_cfg.silent = silent;
}

void klog_set_level(uint8_t level) {
	klog_cfg.level = level;
}

void klog_set_file(FILE *file) {
	klog_cfg.file = file;
}

int klog_file_init(const char *path) {
	klog_cfg.file = fopen(path, "w");
	return klog_cfg.file == NULL;
}

void klog_progname_init(const char *name) {
	klog_cfg.progname = name;
}

int klog_file_close(void) {
	int ret = fclose(klog_cfg.file);
	if(ret == 0) {
		klog_cfg.file = NULL;
	}

	return ret;
}

char *klog_level_str(int level) {
	switch(level) {
		case KLOG_MEMINFO:
			return "MINFO";
		case KLOG_INFO:
			return "INFO";
		case KLOG_DEBUG:
			return "DEBUG";
		case KLOG_WARN:
			return "WARN";
		case KLOG_ERROR:
			return "ERROR";
		case KLOG_FATAL:
			return "FATAL";
	}

	return "Unknown";
}

char *klog_level_colour(int level) {
	switch(level) {
		case KLOG_MEMINFO:
			return "\033[1;33m";
		case KLOG_INFO:
			return "\033[1;36m";
		case KLOG_DEBUG:
			return "\033[1;35m";
		case KLOG_WARN:
			return "\033[1;33m";
		case KLOG_ERROR:
			return "\033[1;31m";
		case KLOG_FATAL:
			return "\033[0;41m";
	}

	return "\033[0;41m";
}

int klog(int level, int line, const char *func, char *fmt, ...) {
	va_list args;
	int ret = 0;
	
	if(klog_cfg.silent || level < klog_cfg.level) {
		return ret;
	}

	va_start(args, fmt);

	ret = fprintf(stderr, "%s%s %5s %s(%d):\033[0m ", klog_level_colour(level),
				klog_cfg.progname, klog_level_str(level), func, line);
	ret += vfprintf(stderr, fmt, args);

	if(klog_cfg.file) {
		fprintf(stderr, "%d %d %s: ", level, line, func);
		vfprintf(stderr, fmt, args);
	}

	va_end(args);
	return ret;
}
