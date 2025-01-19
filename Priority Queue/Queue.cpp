#include"Queue.h"
ostream& operator<<(ostream& os, const Queue ref)
{
	ref.showQueue();
	return os;
}
Queue::Queue() :rear(0), numberOfEntries(0)
{
	for (int i = 0; i < maxSize; i++)
	{
		queue[i] = 0;
		priorities[i] = 0;
	}
}
void Queue::enQueue(int guest, int priority)
{
	if (!isFull())
	{
		queue[rear] = guest;
		priorities[rear++] = priority;
		numberOfEntries++;
	}
	else
	{
		cout << "Full!!" << endl;
	}
}
int Queue::deQueue()
{
	if (!isEmpty())
	{
		int index = 0;
		int maxPriority = priorities[index];
		for (int i = 1; i < rear; i++)
		{
			if (priorities[i] > maxPriority)
			{
				index = i;
				maxPriority = priorities[i];
			}
		}
		int temp = queue[index];
		for (int i = 0; i < (rear - 1); i++)
		{
			if (i >= index)
			{
				queue[i] = queue[i + 1];
				priorities[i] = priorities[i + 1];
			}
		}
		queue[rear--] = 0;
		return temp;
		numberOfEntries--;
	}
	else
	{
		cout << "Empty!!" << endl;
		exit(0);
	}
}
int Queue::top()
{
	int index = 0;
	int maxPriority = priorities[index];
	for (int i = 1; i < rear; i++)
	{
		if (priorities[i] > maxPriority)
		{
			index = i;
			maxPriority = priorities[i];
		}
	}
	return queue[index];
}
bool Queue::isEmpty() const
{
	return (rear == 0) ? true : false;
}
bool Queue::isFull() const
{
	return (rear == (maxSize)) ? true : false;
}
void Queue::showQueue() const
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		for (int i = 0;i < numberOfEntries;i++)
		{
			cout << queue[i] << ' ';
		}
		cout << endl;
	}
}
Queue::~Queue()
{
	rear = 0;
	for (int i = 0; i < numberOfEntries; i++)
	{
		queue[i] = 0;
		priorities[i] = 0;
	}
	numberOfEntries = 0;
}