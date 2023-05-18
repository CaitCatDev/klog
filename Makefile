CC=clang
LD=lld
AR=llvm-ar
INSTALL_PREFIX=/usr/local

all: libklog.a libklog.so

libklog.a: klog.c
	$(CC) -c klog.c -o klog.o
	$(AR) rcs libklog.a klog.o

libklog.so: klog.c
	$(CC) -fuse-ld=$(LD) -fPIC -shared klog.o -o libklog.so

install: libklog.a libklog.so
	install -m=644 libklog.a $(INSTALL_PREFIX)/lib/libklog.a
	install -m=755 libklog.so $(INSTALL_PREFIX)/lib/libklog.so
	install -m=644 klog.h $(INSTALL_PREFIX)/include/klog.h

uninstall:
	rm -iv $(INSTALL_PREFIX)/lib/libklog.so $(INSTALL_PREFIX)/lib/libklog.a $(INSTALL_PREFIX)/include/klog.h

clean:
	rm klog.o libklog.a libklog.so
