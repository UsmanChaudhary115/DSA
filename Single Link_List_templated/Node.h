#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template <typename T>
class Node
{
	T data;
	Node<T>* next;
public:
	Node();
	Node(T);
	Node(T, Node<T>*);
	Node<T>* getNext();
	void setNext(Node<T>*);
	T getData();
};
#endif // !NODE_H
