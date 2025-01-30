#include"Node.h"
Node::Node() : data(0), next(nullptr)
{}
Node::Node(int data) :Node()
{
	this->data = data;
}
Node::Node(int data, Node* ref)
{
	next = ref;
	ref = nullptr;
	this->data = data;
}
Node* Node::getNext()
{
	return next;
}
void Node::setNext(Node* ref)
{
	if (ref != next)
	{
		next = ref;
		ref = nullptr;
	}
}
int Node::getData()
{
	return data;
}