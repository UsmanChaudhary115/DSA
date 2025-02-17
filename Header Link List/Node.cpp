#include"Node.h"
Node::Node() : data(0), next(nullptr)
{}
Node::Node(int data) : data(data), next(nullptr)
{}
Node::Node(int data, Node* ref) : data(data), next(ref)
{}
Node* Node::getNext()
{
	return next;
}
void Node::setNext(Node* ref)
{
	if (ref != next)
	{
		next = ref;
	}
}
int Node::getData()
{
	return data;
}