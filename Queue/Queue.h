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

	void reSize()
	{
		int newSize = (size * 3) / 2;
		int* temp = new int[newSize];

		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}

		size = newSize;
		delete[]data;
		data = temp;
		temp = nullptr;
	}
public:
	Queue():data(nullptr),size(0),front(-1),rear(-1)
	{}
	Queue(int size):Queue()
	{
		if (size > 0)
		{
			this->size = size;
			data = new int[size];
		}
	}
	bool isFull()
	{
		return (rear == (size - 1)) ? true : false;
	}
	bool isEmpty()
	{
		return (front == rear) ? true : false;
	}
	void enQueue(int val)
	{
		if (isFull())
		{
			cout << "Queue is Full!" << endl;
		}
		else
		{
			data[++rear] = val;
		}
	}
	int deQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return -1;
		}
		int element = data[++front];
		if (isFull() && (front + 1) == rear)
		{
			data[0] = data[rear];
			front = -1;
			rear = 0;
		}
		if (isEmpty())
		{
			front = -1;
			rear = -1;
		}
		return element;
	}
	~Queue()
	{
		if (data != nullptr)
		{
			delete[]data;
		}
		size = 0;
		front = -1;
		rear = -1;
	}
}; 
#endif // !QUEUE_H
