#ifndef STACK_H
#define STACK_H
#include"List.h"
class Stack
{
	List list;
public:
	Stack();
	Stack(const Stack&);
	Stack& operator = (const Stack&);
	bool isEmpty() const;
	void push(int ref);
	int pop();
	int getTop() const;
	void showStack() const;
	friend ostream& operator << (ostream& os, const Stack ref);
};

#endif // !STACK_H
