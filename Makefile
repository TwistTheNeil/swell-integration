windows: hello.c
	/dev/shm/mxe/usr/bin/i686-w64-mingw32.static-gcc -shared hello.c -o libhello.dll

linux: hello.c
	gcc -shared -o libhello.so -fPIC hello.c

mac: hello.c
	/dev/shm/osxcross/target/bin/o64-clang -dynamiclib -std=gnu99 hello.c -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o libhello.dylib

clean:
	@rm -f *.exe *.o *.dll *.bundle *.so *.dylib
