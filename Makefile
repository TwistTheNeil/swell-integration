linux: libhello.cpp libhello.h
	g++ -shared -o libhello.so -fPIC libhello.cpp

loader: loader.cpp
	g++ -Wall -g -o loader.o -c loader.cpp
	g++ -g -o loader loader.o -ldl

test: linux loader
	LD_LIBRARY_PATH="." ./loader

mac: libhello.cpp libhello.h
	/dev/shm/osxcross/target/bin/o64-clang++ -dynamiclib libhello.cpp -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o libhello.bundle

win: libhello.cpp libhello.h
	x86_64-w64-mingw32-g++ -shared libhello.cpp -o libhello.dll

clean:
	@rm -f *.exe *.o *.dll *.bundle *.so* *.dylib loader
