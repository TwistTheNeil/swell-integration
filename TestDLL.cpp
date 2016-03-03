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
		swellanimations::Node* node = new swellanimations::Node();
	//	Node *node = (Node*)calloc(1, sizeof(Node));
		node->ParseFromArray(a, size);
		iterate(node);
		responseSize = node->ByteSize();
		void* response = malloc(responseSize);
		node->SerializeToArray(response, responseSize);
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
