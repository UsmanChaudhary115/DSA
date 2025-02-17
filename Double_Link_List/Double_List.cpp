#include"Double_List.h"
Double_List::Double_List() :head(nullptr), tail(nullptr)
{}
bool Double_List::isEmpty()
{
	return (head == nullptr);
}
void Double_List::addToHead(int element)
{
	head = new Node(element, head, nullptr);
	//While new Node`s next pointer will receive current address hold by head. 
	//Then head will point to the new Node.
	//The previous of the head will always points to nullptr.
	
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = head;
	}
	else
	{
		head->getNext()->setPrevious(head);
	}
}
void Double_List::addToTail(int element)
{
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = new Node(element);
		head = tail;
		return;
	}
	tail->setNext(new Node(element, nullptr, tail));
	tail = tail->getNext();
}
int Double_List::deleteFromHead()
{
	int data;
	if (isEmpty())
	{
		cout << "List is Empty!" << endl;
		data = 0;
	}
	else if (head->getNext() == nullptr)
	{
		data = head->getData();		// Getting Data of an object currently pointed by head.
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		data = head->getData();			// Getting Data of an object currently pointed by head.
		head = head->getNext();			// set Head to the next object
		delete head->getPrevious();		// Deleting object prior to head.
		head->setPrevious(nullptr);		// setting previous pointer of head to NULL.
	}
	return data;
}
int Double_List::deleteFromTail()
{
	int data;
	if (isEmpty())
	{
		data = 0;
	}
	else if (tail->getPrevious() == nullptr)
	{
		data = tail->getData();		// Getting Data of an object currently pointed by tail.
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		data = tail->getData();		// Getting Data of an object currently pointed by tail.
		tail = tail->getPrevious();		// set tail to the previous object
		delete tail->getNext();			// Deleting object next to tail.
		tail->setNext(nullptr);			// setting next pointer of tail to NULL.
	}		
	return data;
}
void Double_List::displayList()
{
	if (isEmpty())
	{
		cout << "Empty!";
		return;
	}
	Node* temp = head;				//Starting a temporary pointer from start of the list.
	while (temp != nullptr)			//Iterating until the end of the list.
	{
		cout << temp->getData();	//Printing Data hold by the object currently pointed by temporary pointer.
		if (temp->getNext() != nullptr)
		{							//This will print traditional "->" sign of list after every entry except for the last one.
			cout << " <-> ";
		}
		temp = temp->getNext();		//Temporary pointer is getting address of the next connected object in the list from the next pointer present in the object.
									//At Tail, It`ll receive nullptr from its next pointer thus terminating the loop.
	}
}
bool Double_List::deleteNode(int element)
{
	bool status = false;
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->getData() == element)
	{
		deleteFromHead();
		status = true;
	}
	else
	{
		for (Node* temp = head; (temp != tail) && !status; temp = temp->getNext())
		{
			if (temp->getNext()->getData() == element)
			{
				Node* p = temp->getNext();
				temp->setNext(p->getNext());
				if (temp->getNext() != nullptr)
				{
					temp->getNext()->setPrevious(temp);
				}
				delete p;
				p = nullptr;
				status = true;
			}
		}
	}
	return status;
}
bool Double_List::isInList(int element)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return false;
	}
	for (Node* temp = head; temp != nullptr; temp = temp->getNext())		//Starting a temporary pointer from start of the list.
	{																		//Iterating until the end of the list.
		if (temp->getData() == element)										//If element found, return statement will terminate the loop.
		{
			return true;
		}
	}
	return false;															//If whole list traversed without encountering the key, this return statement will be executed.
}
Double_List::~Double_List()
{
	if (isEmpty())
	{
		return;
	}
	for (Node* temp = head; temp != nullptr;)	//Starting a temporary pointer from start of the list.
	{											//Iterating until the end of the list.
		Node* p = temp;							//Another Block level pointer will point to the object pointed by the pointer "temp".
		temp = temp->getNext();					//"temp" will move to the next object.
		delete p;								//Current object pointed by 'p' is being deleted.
	}
	head = nullptr;								//Both "Head" & "Tail" pointers receiving nullptr.
	tail = nullptr;
}
void Double_List::deleteNthNodeFromEnd(int n)
{
	if (!isEmpty() && n > 0)
	{
		int i = 0;
		for (Node* temp = tail;i < n && temp != nullptr;i++)
		{
			if (temp != nullptr && (i == n - 1))
			{
				if (temp == head)
				{
					deleteFromHead();
				}
				else if (temp == tail)
				{
					deleteFromTail();
				}
				else
				{
					temp->getPrevious()->setNext(temp->getNext());
					temp->getNext()->setPrevious(temp->getPrevious());
					delete temp;
					temp = nullptr;
				}
			}
			else
			{
				temp = temp->getPrevious();
			}
		}
	}
}