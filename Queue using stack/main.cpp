#include"Queue.h"
int main()
{
	Queue q;
	q.enQueue(4);

	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	cout<<q.deQueue();
}