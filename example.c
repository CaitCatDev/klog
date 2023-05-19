#define KLOG_MODULE "Example"
#include "klog.h"


int main(void) {
	klog(KLOG_MEMINFO, __LINE__, __FUNCTION__, "Hello World\n%s", "From Cat\n");
	klog(KLOG_INFO, __LINE__, __FUNCTION__, "Hello World\n%s", "From Cat\n");
	klog(KLOG_DEBUG, __LINE__, __FUNCTION__, "Hello World\n%s", "From Cat\n");
	klog(KLOG_WARN, __LINE__, __FUNCTION__, "Hello World\n%s", "From Cat\n");
	klog(KLOG_ERROR, __LINE__, __FUNCTION__, "Hello World\n%s", "From Cat\n");
	klog(KLOG_FATAL, __LINE__, __FUNCTION__, "Hello World\n%s", "From Cat\n");

	return 0;
}
