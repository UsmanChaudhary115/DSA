#include"Queue.h"
void Queue::reSize()
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
Queue::Queue() :data(nullptr), size(0), front(-1), rear(-1)
{}
Queue::Queue(int size) :Queue()	
{
	if (size > 0)
	{
		this->size = size;
		data = new int[size];
	}
}
bool Queue::isFull()
{
	return (rear == (size - 1)) ? true : false;
}
bool Queue::isEmpty()
{
	return (front == rear) ? true : false;
}
void Queue::enQueue(int val)
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
int Queue::deQueue()
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
Queue::~Queue()
{
	if (data != nullptr)
	{
		delete[]data;
	}
	size = 0;
	front = -1;
	rear = -1;
}