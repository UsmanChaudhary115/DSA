#include"Stack.h"
Stack::Stack()
{}
void Stack::push(int x)
{
	Queue temp{ 100 };
	while (!data.isEmpty())
	{
		temp.enQueue(data.deQueue());
	}
	data.enQueue(x);
	while (!temp.isEmpty())
	{
		data.enQueue(temp.deQueue());
	}
}
int Stack::pop()
{
	return data.deQueue();
}
int Stack::top()
{
	int val = data.deQueue();
	push(val);
	return val;
}
bool Stack::empty()
{
	return (data.isEmpty())?true:false;
}
