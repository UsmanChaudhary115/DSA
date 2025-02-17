#ifndef LIST_H
#define LIST_H
#include"Node.h"
#include<iostream>
using namespace std;
class Double_List
{
	Node* head;
	Node* tail;
public:
	Double_List();
	void addToHead(int);
	void addToTail(int);
	bool isEmpty();
	int deleteFromHead();
	int deleteFromTail();
	void displayList();
	bool deleteNode(int);
	bool isInList(int);
	void deleteNthNodeFromEnd(int);
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	~Double_List();
};
#endif // !LIST_H
