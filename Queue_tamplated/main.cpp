#include"Queue.h"
int main()
{

	Queue<int> q{ 5 };

	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(5);
	q.enQueue(3);
	q.enQueue(1);
	//cout << "front: " << q.getfront() << endl;
	//cout <<"rear: " << q.getrear() << endl;
	//cout <<"size: " << q.getsize() << endl;
	cout << "Hello" << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout <<"Dequeue: " << q.deQueue() << endl;
	//cout << "front: " << q.getfront() << endl;
	//cout << "rear: " << q.getrear() << endl;
	//cout << "size: " << q.getsize() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	//cout << "front: " << q.getfront() << endl;
	//cout << "rear: " << q.getrear() << endl;
	//cout << "size: " << q.getsize() << endl;
	cout << q.isEmpty()<<endl;

	q.enQueue(5);
	q.enQueue(3);
	q.enQueue(1); 
	q.enQueue(5);
	q.enQueue(3);
	q.enQueue(1);
	cout << q.isEmpty() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;
	cout << "Dequeue: " << q.deQueue() << endl;

	return 0;
}