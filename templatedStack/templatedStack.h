#include <iostream>
using namespace std;
template <typename T>
class Stack
{
	T* data;
	int top;
	int size;
	void reSize(int);
public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();
	Stack& operator = (const Stack<T>&);
	bool isFull();
	bool isEmpty();
	void push(T);
	T pop();
	T Top();
};
