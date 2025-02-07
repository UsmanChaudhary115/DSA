#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* previous; 
	Node() : data(0), next(nullptr), previous(nullptr)
	{}
	Node(int data) : Node()
	{
		this->data = data;
	}
	Node(int data, Node* next, Node* previous)
	{
		this->next = next;
		next = nullptr;
		this->previous = previous;
		previous = nullptr;
		this->data = data;
	}
};
#endif // !NODE_H
