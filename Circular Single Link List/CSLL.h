#ifndef CSLL_H
#define CSLL_H
#include"Node.h"
class CSLL
{
	Node* tail;
public:
	CSLL();
	bool isEmpty();
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void displayList();
	bool deleteNode(int);
	bool isInList(int);
	~CSLL();
};
#endif // !CSLL_H
