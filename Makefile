linux: libhello.cpp libhello.h
	g++ -shared -o libhello.so -fPIC libhello.cpp

loader: loader.cpp
	g++ -Wall -g -o loader loader.cpp -ldl `pkg-config --cflags --libs protobuf` #-Wl,--no-as-needed -ldl

testobj: swell-integration.cpp loader
	g++ -g -shared -o swell-integration.so -fPIC AnimationDataSerializer/modeldata.pb.cc swell-integration.cpp `pkg-config --cflags --libs protobuf` -Wl,--no-as-needed -ldl
	LD_LIBRARY_PATH="." ./loader

test: linux loader
	LD_LIBRARY_PATH="." ./loader

mac: libhello.cpp libhello.h
	/dev/shm/osxcross/target/bin/o64-clang++ -dynamiclib libhello.cpp -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o libhello.bundle

win: libhello.cpp libhello.h
	x86_64-w64-mingw32-g++ -shared libhello.cpp -o libhello.dll

maclocal: swell-integration.cpp
	g++ -dynamiclib  -arch x86_64 AnimationDataSerializer/modeldata.pb.cc swell-integration.cpp -lprotobuf -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o swell-integration.bundle

clean:
	@rm -f *.exe *.o *.dll *.bundle *.so* *.dylib loader
