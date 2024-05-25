#include"Queue.h"
template <typename T>
void Queue<T>::reSize()
{
	int newSize = (size * 3) / 2;
	T* temp = new T[newSize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}
	size = newSize;
	delete[]data;
	data = temp;
	temp = nullptr;
}
template <typename T>
Queue<T>::Queue() :data(nullptr), size(0), front(-1), rear(-1)
{}
template <typename T>
Queue<T>::Queue(int size) :Queue()
{
	if (size > 0)
	{
		this->size = size;
		data = new T[size];
	}
}
template <typename T>
bool Queue<T>::isFull()
{
	return (rear == (size - 1)) ? true : false;
}
template <typename T>
bool Queue<T>::isEmpty()
{
	return (front == rear) ? true : false;
}
template <typename T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
	{
		//cout << "Queue is Full!" << endl;
		reSize();
	}
	//else
	{
		data[++rear] = val;
	}
}
template <typename T>
T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "Queue is empty! Exiting program!" << endl;
		exit(0);
	}
	T element = data[++front];
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
template <typename T>
Queue<T>::~Queue()
{
	if (data != nullptr)
	{
		delete[]data;
	}
	size = 0;
	front = -1;
	rear = -1;
}