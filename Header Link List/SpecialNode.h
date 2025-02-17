#ifndef SPECIALNODE_H
#define SPECIALNODE_H
#include"Node.h"
class SpecialNode
{
public:
	int size;
	int minData;
	int maxData;
	Node* next;
	SpecialNode() : size(0), minData(0), maxData(0) ,next(nullptr)
	{}
};
#endif // !SPECIALNODE_H
