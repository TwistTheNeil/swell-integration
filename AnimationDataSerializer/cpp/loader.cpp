#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "modeldata.pb.h"

typedef void (*simple_demo_function)(char* a, int size, unsigned int& responseSize);

int main(void) {
	const char *error;
	void *module;
	simple_demo_function demo_function;

	/* Load dynamically loaded library */
	printf("what1\n");
	module = dlopen("TestDLL.so", RTLD_LAZY);
	printf("what2\n");
	if (!module) {
		fprintf(stderr, "Couldn't open libhello.so: %s\n",
		dlerror());
		exit(1);
	}
	printf("what3\n");

	/* Get symbol */
	dlerror();
	//demo_function = (simple_demo_function)dlsym(module, "setDataNegative");
	demo_function = (simple_demo_function)dlsym(module, "_Z15setDataNegativePciRj");
	if ((error = dlerror())) {
		fprintf(stderr, "Couldn't dlsym: %s\n", error);
		exit(1);
	}

	/* Now call the function in the DL library */
	char *s = (char*)calloc(9, sizeof(char));
	printf("ltest1\n");
	strncpy(s, "CgJzMA==", 8);
	printf("ltest2\n");
	unsigned int a = 27;
	printf("ltest3\n");
	(*demo_function)(s, 8, a);
	printf("ltest4\n");

	/* All done, close things cleanly */
	dlclose(module);
	return 0;
}
