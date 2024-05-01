#include"Stack.h"
template <typename T>
void Stack<T>::reSize(int cap)
{
	T* newData = new T[cap];
	for (int i = 0; i < top; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	size = cap;
	data = newData;
}
template <typename T>
Stack<T>::Stack() :data(nullptr), top(0), size(0)
{}
template <typename T>
Stack<T>::Stack(const Stack<T>& rfs)
{
	*this = rfs;
}
template <typename T>
Stack<T>::~Stack()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	size = 0;
	top = 0;
}
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& ref)
{
	if ((this == &ref) || (ref.data == nullptr))
	{
		return *this;
	}
	else
	{
		this->~Stack();
		top = ref.top;
		size = ref.size;
		data = new T[size];
		for (int i = 0; i < top; i++)
		{
			data[i] = ref.data[i];
		}
		return *this;
	}
}
template <typename T>
bool Stack<T>::isFull()
{
	return (top == size) ? true : false;
}
template <typename T>
bool Stack<T>::isEmpty()
{
	return (top == 0) ? true : false;
}
template <typename T>
void Stack<T>::push(T ref)
{
	if (top == size)
	{
		reSize(size == 0 ? 1 : size * 2);
	}
	data[top] = ref;
	top++;
}
template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is already empty.\nExiting";
		exit(0);
	}
	T value = data[top - 1];
	top--;
	if (top > 0 && top == size / 4)
	{
		reSize(size / 2);
	}
	return value;
}
template <typename T>
T Stack<T>::Top()
{
	if (isEmpty())
	{
		cout << "Stack is already empty.\nExiting";
		exit(0);
	}
	return data[top - 1];
}