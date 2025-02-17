#ifndef LIST_H
#define LIST_H
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class Double_List
{
	Node<T>* head;
	Node<T>* tail;
public:
	Double_List();
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	void displayList();
	bool deleteNode(T);
	bool isInList(T);
	~Double_List();
	Node<T>* getHead()
	{
		return head;
	}
	Node<T>* getTail()
	{
		return tail;
	}
};
#endif // !LIST_H
