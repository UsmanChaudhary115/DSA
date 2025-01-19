#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
class Queue
{
	static const int maxSize = 100;
	int queue[maxSize];
	int priorities[maxSize];
	int rear;
	int numberOfEntries;
public:
	Queue();
	void enQueue(int, int = 0);
	int deQueue();
	int top();
	bool isEmpty() const;
	bool isFull() const;
	void showQueue() const;
	~Queue();
	friend ostream& operator<<(ostream& os, const Queue);
};
#endif // !QUEUE_H
