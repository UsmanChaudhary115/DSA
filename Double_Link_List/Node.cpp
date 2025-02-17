#include"Node.h"
Node::Node() : data(0), next(nullptr),previous(nullptr)
{}
Node::Node(int data) :Node()
{
	this->data = data;
}
Node::Node(int data, Node* next, Node* previous)
{
	this->next = next;
	next = nullptr;
	this->previous = previous;
	previous = nullptr;
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

Node* Node::getPrevious()
{
	return previous;
}
void Node::setPrevious(Node* ref)
{
	if (ref != nullptr || ref != previous)
	{
		previous = ref;
		ref = nullptr;
	}
}
int Node::getData()
{
	return data;
}