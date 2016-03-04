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
		Node* node = new Node();
		node->ParseFromArray(a, size);
		iterate(node);
		responseSize = node->ByteSize();
		void* response = malloc(responseSize);
		node->SerializeToArray(response, responseSize);
		return response;
	}
}
