#ifndef QUEUE_H
#define	QUEUE_H
#include"List.h"
class Queue
{
	List list;
public:
	Queue();
	bool isEmpty();
	void enQueue(int);
	int deQueue();
	void showQueue() const;
	friend ostream& operator<<(ostream os, const Queue);
}; 
#endif // !QUEUE_H
