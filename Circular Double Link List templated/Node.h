#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* previous; 
	Node() : data(0), next(nullptr), previous(nullptr)
	{}
	Node(T data) : Node()
	{
		this->data = data;
	}
	Node(T data, Node<T>* next, Node<T>* previous)
	{
		this->next = next;
		next = nullptr;
		this->previous = previous;
		previous = nullptr;
		this->data = data;
	}
};
#endif // !NODE_H
