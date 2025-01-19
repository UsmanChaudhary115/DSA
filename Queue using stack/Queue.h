#ifndef QUEUE_H
#define QUEUE_H
#include"Stack.h"
class Queue
{
	Stack data;
public:
	Queue();
	bool isFull();
	bool isEmpty();
	void enQueue(int val);
	int deQueue();
	~Queue();
};
#endif // !QUEUE_H
