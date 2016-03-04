#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include "AnimationDataSerializer/modeldata.pb.h"

using namespace swellanimations;

extern "C" {

	void iterate(Node* node) {
		node->set_positionx(node->positionx() / -2);
		node->set_positiony(node->positiony() / -2);
		node->set_positionz(node->positionz() / -2);
		node->set_rotationx(node->rotationx() / -2);
		node->set_rotationy(node->rotationy() / -2);
		node->set_rotationz(node->rotationz() / -2);
		if (node->children_size() != 0) {
			iterate(node->mutable_children(0));
		}
	}
	#ifdef _WIN32 
	__declspec (dllexport) 
	#endif
	void* setDataNegative(char* a, int size, unsigned int& responseSize) {
		printf("test1\n");
		Node* node = new Node();
		printf("test2\n");
		//		Node *node = (Node*)calloc(1, sizeof(Node));
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
