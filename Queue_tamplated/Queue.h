#ifndef QUEUE_H
#define	QUEUE_H
#include<iostream>
using namespace std;
template <typename T>
class Queue
{
	T* data;
	int size;
	int front;
	int rear;

	void reSize();
public:
	Queue();
	Queue(int);
	bool isFull();
	bool isEmpty();
	void enQueue(T val);
	T deQueue();
	~Queue();
}; 
#endif // !QUEUE_H
