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
	bool isFull();
	bool isEmpty();
	void push(int ref);
	int pop();
	int getTop();
	void showStack();
};
