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
List::List(List&& ref) 
{
	*this = move(ref);
}
List& List::operator=(List&& ref)
{
	if (!ref.isEmpty() && this != &ref)
	{
		this->~List();
		head = ref.head;
		tail = ref.tail;
		ref.head = nullptr;
		ref.tail = nullptr;
	}
	return *this;
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
bool List::deleteNode(int element) // deletes first occurance
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
int List::getMiddleElement() const
{
	Node* temp1 = head;
	Node* temp2 = head;
	while (temp2->getNext() != nullptr)
	{
		temp2 = temp2->getNext();
		if (temp2->getNext() != nullptr)
		{
			temp1 = temp1->getNext();
			temp2 = temp2->getNext();
		}
	}
	int data = temp1->getData();
	temp1 = nullptr;
	temp2 = nullptr;
	return data;
}
bool List::isPalindrom() const
{
	if (!isEmpty() && (this->head->getNext() != nullptr))
	{
		bool status = true;
		List temp;
		Node* temp1 = head;
		Node* temp2 = head;
		while (temp2->getNext() != nullptr)
		{
			temp.addToHead(temp1->getData());
			temp2 = temp2->getNext();
			temp1 = temp1->getNext();
			if (temp2->getNext() != nullptr)
			{
				temp2 = temp2->getNext();
			}
		}
		while (!temp.isEmpty() && status)
		{
			if (temp.head->getData() != temp1->getData())
			{
				status = false;
			}
			temp.deleteFromHead();
			temp1 = temp1->getNext();
		}
		if ((status && temp1 != nullptr) || (temp1 == nullptr && !temp.isEmpty()))
		{
			status = false;
		}
		return status;
	}
	else
	{
		return true;
	}
}
void List::reverseList()
{
	List temp;
	while (!isEmpty())
	{
		temp.addToHead(deleteFromHead());
	}
	*this = move(temp);
}
void List::zigzag()
{
	if (!isEmpty())
	{
		/*bool isGreaterStatus = true;
		List temp = move(*this);
		while (!temp.isEmpty())
		{
			if (isEmpty())
			{
				this->addToTail(temp.deleteFromHead());
			}
			else
			{
				if (isGreaterStatus)
				{
					this->addToTail(temp.deleteMaximum());
					isGreaterStatus = false;
				}
				else
				{

					this->addToTail(temp.deleteMinimum());
					isGreaterStatus = true;
				}
			}
		}*/

		bool isGreaterStatus = true;
		for (Node* temp = head->getNext();temp != nullptr;temp = temp->getNext())
		{
			if(isGreaterStatus)
			{
				Node* q = temp;
				for (Node* p = temp;p != nullptr;p = p->getNext())
				{
					if (p->getData() > q->getData())
					{
						q = p;
					}
				}
				int data = temp->getData();
				temp->setData(q->getData());
				q->setData(data);
				isGreaterStatus = false;
			}
			else
			{
				Node* q = temp;
				for (Node* p = temp;p != nullptr;p = p->getNext())
				{
					if (p->getData() < q->getData())
					{
						q = p;
					}
				}
				int data = temp->getData();
				temp->setData(q->getData());
				q->setData(data);
				isGreaterStatus = true;
			}
		}
	}
}
int List::getMinimum() const
{
	if(!isEmpty())
	{
		int data = head->getData();
		for (Node* temp = head;temp != nullptr;temp = temp->getNext())
		{
			if ((temp->getData() < data))
			{
				data = temp->getData();
			}
		}
		return data;
	}
	exit(0);
}
int List::getMaximum() const
{
	if (!isEmpty())
	{
		int data = head->getData();
		for (Node* temp = head;temp != nullptr;temp = temp->getNext())
		{
			if ((temp->getData() > data))
			{
				data = temp->getData();
			}
		}
		return data;
	}
	exit(0);
}
int List::deleteMaximum()
{
	if (!isEmpty())
	{
		if (head->getNext() == nullptr)
		{
			return deleteFromHead();
		}
		else
		{
			int data = head->getData();
			Node* p = head;
			for (Node* temp = head;temp->getNext() != nullptr;temp = temp->getNext())
			{
				if ((temp->getNext()->getData() > data))
				{
					data = temp->getNext()->getData();
					p = temp;
				}
			}
			if (p->getData() > p->getNext()->getData())
			{
				deleteFromHead();
			}
			else if (p->getNext() == tail)
			{
				deleteFromTail();
			}
			else
			{
				Node* q = p->getNext();
				p->setNext(q->getNext());
				delete q;
				size--;
				q = nullptr;
				p = nullptr;
			}
			return data;
		}
	}
	exit(0);
}
int List::deleteMinimum()
{
	if (!isEmpty())
	{
		if (head->getNext() == nullptr)
		{
			return deleteFromHead();
		}
		else
		{
			int data = head->getData();
			Node* p = head;
			for (Node* temp = head;temp->getNext() != nullptr;temp = temp->getNext())
			{
				if ((temp->getNext()->getData() < data))
				{
					data = temp->getNext()->getData();
					p = temp;
				}
			}
			if (p->getData() < p->getNext()->getData())
			{
				deleteFromHead();
			}
			else if (p->getNext() == tail)
			{
				deleteFromTail();
			}
			else
			{
				Node* q = p->getNext();
				p->setNext(q->getNext());
				delete q;
				size--;
				q = nullptr;
				p = nullptr;
			}
			return data;
		}
	}
	exit(0);
}
void List::ascendingSort()
{
	if (!isEmpty())
	{
		List temp = move(*this);
		while (!temp.isEmpty())
		{
			addToTail(temp.deleteMinimum());
		}
	}
}
void List::descendingSort()
{
	if (!isEmpty())
	{
		List temp = move(*this);
		while (!temp.isEmpty())
		{
			addToTail(temp.deleteMaximum());
		}
	}
}