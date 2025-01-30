#ifndef LIST_H
#define LIST_H
#include"Node.h"
#include<iostream>
using namespace std;
class List
{
	Node* head;
	Node* tail;
	int size;
public:
	List();
	List(const List&);
	List& operator=(const List&);
	List(List&&);
	List& operator=(List&&);
	bool isEmpty() const;
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void displayList() const;
	bool deleteNode(int);
	bool isInList(int) const;
	int getSize() const;
	Node* getHead() const;
	Node* getTail() const;
	int getMinimum() const;
	int getMaximum() const;
	int deleteMaximum();
	int deleteMinimum();
	void ascendingSort();
	void descendingSort();
	~List();
	friend ostream& operator << (ostream& os, const List ref);
	bool isPalindrom() const;
	int getMiddleElement() const;
	void reverseList();
	void zigzag();
};
#endif // !LIST_H
