#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*simple_demo_function)(void);

int main(void) {
	const char *error;
	void *module;
	simple_demo_function demo_function;

	/* Load dynamically loaded library */
	module = dlopen("libhello.so", RTLD_LAZY);
	if (!module) {
		fprintf(stderr, "Couldn't open libhello.so: %s\n",
		dlerror());
		exit(1);
	}

	/* Get symbol */
	dlerror();
	demo_function = (simple_demo_function)dlsym(module, "hello");
	if ((error = dlerror())) {
		fprintf(stderr, "Couldn't find hello: %s\n", error);
		exit(1);
	}

	/* Now call the function in the DL library */
	(*demo_function)();

	/* All done, close things cleanly */
	dlclose(module);
	return 0;
}
