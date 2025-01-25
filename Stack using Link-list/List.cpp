#include"List.h"
ostream& operator << (ostream& os, const List ref)
{
	ref.displayList();
	return os;
}
List::List() :head(nullptr), tail(nullptr), size(0)
{}
List::List(const List& ref) :List()
{
	*this = ref;
}
List& List::operator=(const List& ref)
{
	if (ref.head == nullptr || &ref == this)
	{
		return *this;
	}
	for (Node* p = ref.head;p != nullptr;p = p->getNext())
	{
		addToTail(p->getData());
	}
}
bool List::isEmpty() const
{
	return (head == nullptr);
}
void List::addToHead(int element)
{
	head = new Node(element, head);
	size++;
	//While new Node`s next pointer will receive current address hold by head. 
	//Head will point to the new Node.
	
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = head;
	}
}
void List::addToTail(int element)
{
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = new Node(element);
		size++;
		head = tail;
		return;
	}
	tail->setNext(new Node(element));  // Tail`s next pointer that was previously containing nullptr, now will receive the address of newly created Node having nullptr in its next pointer.
	size++;
	tail = tail->getNext(); // Tail will be moved to the newly added Node.
}
int List::deleteFromHead()
{
	if (isEmpty())
	{
		return 0;
	}
	Node* temp = head->getNext();	// A temporary pointer getting address from the next pointer of an object currently pointed by head.
	int a = head->getData();		// Getting Data of an object currently pointed by head.
	delete head;					// Deleting object pointed by head.
	size--;
	head = temp;					// Head is receiving next object`s address using temporary pointer.
	temp = nullptr;					// Temporary pointer getting out of the race.
	if (head == nullptr)			// Checking if that was the only object in the list which we have deleted.
	{								// If yes, removing that memory`s address from tail too.
		tail = nullptr;
	}
	return a;
}
int List::deleteFromTail()
{
	if (isEmpty())
	{
		return 0;
	}
	int a = tail->getData();		//Getting Data present at Tail
	Node* temp = head;				//Starting a temporary pointer from start of the list.
	while (temp->getNext() != tail) //Iterating until one before tail. Here, temp->getNext() will be pointing to the tail at the end.
	{
		temp = temp->getNext();
	}
	delete tail;					//Object pointed by Tail be deleted here.
	size--;
	tail = temp;					//Tail pointer receiving address of 2nd last object int the list which is now the last one.
	temp = nullptr;
	tail->setNext(nullptr);			//Setting next pointer of the last object to nullptr.
	return a;						//Returning deleted Object`s Data.
}
void List::displayList() const
{
	if (isEmpty())
	{
		cout << "List is Empty!";
		return;
	}
	Node* temp = head;				//Starting a temporary pointer from start of the list.
	while (temp != nullptr)			//Iterating until the end of the list.
	{
		cout << temp->getData();	//Printing Data hold by the object currently pointed by temporary pointer.
		if (temp->getNext() != nullptr)
		{							//This will print traditional "->" sign of list after every entry except for the last one.
			cout << " -> ";
		}
		temp = temp->getNext();		//Temporary pointer is getting address of the next connected object in the list from the next pointer present in the object.
									//At Tail, It`ll receive nullptr from its next pointer thus terminating the loop.
	}
}
bool List::deleteNode(int element)
{
	bool status = false;
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->getData() == element)
	{
		deleteFromHead();
		size--;
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
				delete p;
				size--;
				p = nullptr;
				status = true;
			}
		}
	}
	return status;
}  
bool List::isInList(int element) const
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
Node* List::getHead() const
{
	return head;
}
Node* List::getTail() const
{
	return tail;
}
List::~List()
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
	size = 0;
}
int List::getSize() const
{
	return size;
}
