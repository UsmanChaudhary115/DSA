#include"Queue.h"
ostream& operator<<(ostream os, const Queue ref)
{
	ref.showQueue();
	return os;
}
Queue::Queue() :list()
{}
bool Queue::isEmpty()
{
	return list.isEmpty();
}
void Queue::enQueue(int val)
{
	list.addToTail(val);
}
int Queue::deQueue()
{
	return list.deleteFromHead();
}
void Queue::showQueue() const
{
	if (list.isEmpty())
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		list.displayList();
	}
}