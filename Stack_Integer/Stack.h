#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
class Stack
{
	int* data;
	int topIndex;
	int size;
	void reSize(int);
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	Stack& operator = (const Stack&);
	bool isFull() const;
	bool isEmpty() const;
	void push(int ref);
	int pop();
	int getTop() const;
	void showStack() const;
	void sort();
	Stack getSorted() const;
	friend ostream& operator<<(ostream& os, const Stack&);
	int getTopIndex()
	{
		return topIndex;
	}
};
#endif // !STACK_H
