#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<typename T>
class Node
{
	T data;
	Node<T>* next;
	Node<T>* previous;
public:
	Node();
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	Node<T>* getNext();
	void setNext(Node<T>* ref);
	Node<T>* getPrevious();
	void setPrevious(Node<T>* ref);
	T getData();

	void setData(T data)
	{
		this->data = data;
	}
};
#endif // !NODE_H
