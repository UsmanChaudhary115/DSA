#include"Node.h"
template<typename T>
Node<T>::Node() : data(0), next(nullptr),previous(nullptr)
{}
template<typename T>
Node<T>::Node(T data) :Node()
{
	this->data = data;
}
template<typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* previous)
{
	this->next = next;
	next = nullptr;
	this->previous = previous;
	previous = nullptr;
	this->data = data;
}
template<typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

//Node getNext()
//{
//	return *next;
//}

template<typename T>
void Node<T>::setNext(Node<T>* ref)
{
	if (ref != nullptr)
	{
		next = ref;
		ref = nullptr;
	}
}
template<typename T>
Node<T>* Node<T>::getPrevious()
{
	return previous;
}
template<typename T>
void Node<T>::setPrevious(Node<T>* ref)
{
	if (ref != nullptr)
	{
		previous = ref;
		ref = nullptr;
	}
}
template<typename T>
T Node<T>::getData()
{
	return data;
}