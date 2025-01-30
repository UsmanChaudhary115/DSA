#include"Node.h"
template <typename T>
Node<T>::Node() : data(0), next(nullptr)
{}
template <typename T>
Node<T>::Node(T data) :Node()
{
	this->data = data;
}
template <typename T>
Node<T>::Node(T data, Node<T>* ref)
{
	next = ref;
	ref = nullptr;
	this->data = data;
}
template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

//Node getNext()
//{
//	return *next;
//}

template <typename T>
void Node<T>::setNext(Node<T>* ref)
{
	if (ref != nullptr || ref != next)
	{
		next = ref;
		ref = nullptr;
	}
}
template <typename T>
T Node<T>::getData()
{
	return data;
}