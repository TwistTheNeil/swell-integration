#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include "modeldata.pb.h"

using namespace swellanimations;

extern "C"
{
	void iterate(swellanimations::Node* node) {
		//node->set_data(node->data() / -2);
		//if (node->has_childnode()) {
		//	iterate(node->mutable_childnode());
		//}
	}

	void* setDataNegative(char* a, int size, unsigned int& responseSize) {
		printf("test1\n");
//		swellanimations::Node* node = new swellanimations::Node();
		printf("test2\n");
		Node *node = (Node*)calloc(1, sizeof(Node));
		printf("what\n");
		printf("%s--\n", a);
		node->ParseFromArray(a, strlen(a));
		printf("test3\n");
		iterate(node);
		printf("test4\n");
		responseSize = node->ByteSize();
		printf("test5\n");
		void* response = malloc(responseSize);
		printf("test6\n");
		node->SerializeToArray(response, responseSize);
		printf("test7\n");
		return response;
	}

	int main() {
		printf("hello");
		char *s = (char*)calloc(9, sizeof(char));
		strncpy(s, "CgJzMA==", 8);
		unsigned int a = 8;
		setDataNegative(s, 8, a);
		return 0;
	}


}
