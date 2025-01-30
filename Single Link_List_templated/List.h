#ifndef LIST_H
#define LIST_H
#include"Node.h"
#include<iostream>
using namespace std;
template <typename T>
class List
{
	Node<T>* head;
	Node<T>* tail;
public:
	List();
	//List(int);
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void displayList();
	bool deleteNode(T);
	bool isInList(T);
	~List();
};
#endif // !LIST_H
