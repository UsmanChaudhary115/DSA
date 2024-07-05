#ifndef QUEUE_H
#define	QUEUE_H
#include<iostream>
using namespace std;
class Queue
{
	int* data;
	int size;
	int front;
	int rear;
	void reSize();
public:
	Queue();
	Queue(int);
	bool isFull();
	bool isEmpty();
	void enQueue(int);
	int deQueue();
	~Queue();
}; 
#endif // !QUEUE_H
