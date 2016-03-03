#include <iostream>
#include <sstream>
#include "modeldata.pb.h"

extern "C"
{
	void main() {
		printf("hello");
	}

	void iterate(swellanimations::Node* node) {
		//node->set_data(node->data() / -2);
		//if (node->has_childnode()) {
		//	iterate(node->mutable_childnode());
		//}
	}

	void* setDataNegative(char* a, int size, unsigned int& responseSize) {
		swellanimations::Node* node = new swellanimations::Node();
		node->ParseFromArray(a, size);
		iterate(node);
		responseSize = node->ByteSize();
		void* response = malloc(responseSize);
		node->SerializeToArray(response, responseSize);
		return response;
	}
}
