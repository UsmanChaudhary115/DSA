#include"Stack.h"
ostream& operator << (ostream& os, const Stack ref)
{
	ref.showStack();
	return os;
}
Stack::Stack(): list()
{}
Stack::Stack(const Stack& ref) :list(ref.list)
{}
Stack& Stack::operator = (const Stack& ref) 
{
	if (&ref == this)
	{
		return *this;
	}
	this->~Stack();
	list = ref.list;
	return *this;
}
bool Stack::isEmpty() const 
{
	return list.isEmpty();
}
void Stack::push(int ref)
{
	list.addToHead(ref);
}
int Stack::pop()
{
	return list.deleteFromHead();
}
int Stack::getTop() const
{
	if (list.isEmpty())
	{
		cout << "List is Empty!" << endl;
		return -1;
	}
	return list.getHead()->getData();
}
void Stack::showStack() const
{
	if (list.isEmpty())
	{
		cout << "Stack is Empty" << endl;
	}
	else
	{
		for (Node* p = list.getHead();p != nullptr;p = p->getNext())
		{
			cout << p->getData() << endl;
		}
	}
}