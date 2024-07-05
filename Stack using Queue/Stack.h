#ifndef STACH_H
#define	STACH_H
#include"Queue.h"
class Stack 
{
private:
	Queue data{ 100 };
public:
	Stack(); // Constructor
	void push(int x); // Push element x onto stack
	int pop(); // Removes the element on top of the stack and returns that element
	int top(); // Get the top element
	bool empty(); // Returns whether the stack is empty
};
#endif // !STACH_H
