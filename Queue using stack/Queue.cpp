#include"Queue.h"
Queue::Queue():data()
{}
bool Queue::isFull()
{
	return data.isFull();
}
bool Queue::isEmpty()
{
	return data.isEmpty();
}
void Queue::enQueue(int val)
{
	Stack temp;
	while (!data.isEmpty())
	{
		temp.push(data.pop());
	}
	//cout << temp.isEmpty();
	data.push(val);
	while (!temp.isEmpty())
	{
		data.push(temp.pop());
	}
}
int Queue::deQueue()
{
	return data.pop();
}
Queue::~Queue()
{
	data.~Stack();
}