#include"CSLL.h"
#include<iostream>
using namespace std;
CSLL::CSLL():tail(nullptr)
{}
bool CSLL::isEmpty()
{
	return tail == nullptr;
}
void CSLL::addToTail(int e)
{
	if (isEmpty())
	{
		tail = new Node{ e };
		tail->setNext(tail);
	}
	else
	{
		tail->setNext(new Node{ e, tail->getNext() }); //"tail->getNext()" would be current head
		tail = tail->getNext();
	}
}
void CSLL::addToHead(int e)
{
	if (isEmpty())
	{
		tail = new Node{ e };
		tail->setNext(tail);
	}
	else
	{
		tail->setNext(new Node{ e, tail->getNext() }); //"tail->getNext()" would be current head
	}
}
int CSLL::deleteFromHead()
{
	if (isEmpty())
	{
		cout << "Empty";
		return 0;
	}
	else if (tail->getNext() == tail)
	{
		int a = tail->getData();
		delete tail;
		tail = nullptr;
		return a;
	}
	else
	{
		Node* temp = tail->getNext();
		int a = temp->getData();
		tail->setNext(temp->getNext());
		delete temp;
		temp = nullptr;
		return a;
	}
}
int CSLL::deleteFromTail()
{
	if (isEmpty())
	{
		cout << "Empty";
		return 0;
	}
	else if (tail->getNext() == tail)
	{
		int a = tail->getData();
		delete tail;
		tail = nullptr;
		return a;
	}
	else
	{
		int a = tail->getData();
		Node* temp = tail->getNext();
		while (temp->getNext() != tail)
		{
			temp = temp->getNext();
		}
		temp->setNext(tail->getNext());
		delete tail;
		tail = temp;
		temp = nullptr;
		return a;
	}
}
void CSLL::displayList()
{
	if (isEmpty())
	{
		cout << "Empty!";
		return;
	}
	Node* temp = tail->getNext();	
	while (temp != tail)			
	{
		cout << temp->getData();
		cout << " -> ";
		temp = temp->getNext();		
	}
	cout << tail->getData();
}
bool CSLL::deleteNode(int e)
{
	bool status = false;
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (tail->getData() == e)
	{
		deleteFromTail();
		status = true;
	}
	else if (tail->getNext()->getData() == e)
	{
		deleteFromHead();
		status = true;
	}
	else
	{
		Node* temp = tail->getNext();
		while (temp != tail && !status)
		{
			if (temp->getNext()->getData() == e)
			{
				Node* p = temp->getNext();
				temp->setNext(p->getNext());
				delete p;
				p = nullptr;
				status = true;
			}
			else
			{
				temp = temp->getNext();
			}
		}
	}
	return status;
}
bool CSLL::isInList(int e)
{
	bool status = false;
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		for (Node* temp = tail->getNext(); temp != tail && !status; temp = temp->getNext())
		{
			if (temp->getData() == e)
			{
				status = true;
			}
		}
		if (!status && tail->getData() == e)
		{
			status = true;
		}
	}
	return status;
}
CSLL::~CSLL()
{
	if (isEmpty())
	{
		return;
	}
	for (Node* temp = tail->getNext(); temp != tail;)	
	{											
		Node* p = temp;							
		temp = temp->getNext();					
		delete p;								
	}
	delete tail;
	tail = nullptr;
}
