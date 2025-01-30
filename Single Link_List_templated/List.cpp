#include"List.h"
template <typename T>
List<T>::List() :head(nullptr), tail(nullptr)
{}
//List::List(int element) :List()
//{
//	addToHead(element);
//}
template <typename T>
bool List<T>::isEmpty()
{
	return (head == nullptr);
}
template <typename T>
void List<T>::addToHead(T element)
{
	head = new Node<T>(element, head);
	//Head will point to new Node 
	//While new Node`s next pointer will receive current address hold by head. 
	//Then head will point to the new Node.
	
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = head;
	}
}
template <typename T>
void List<T>::addToTail(T element)
{
	if (tail == nullptr)	// This condition will be executed only for the first element.
	{
		tail = new Node<T>(element);
		head = tail;
		return;
	}
	tail->setNext(new Node<T>(element));  // Tail`s next pointer that was previously containing nullptr, now will receive the address of newly created Node having nullptr in its next pointer.
	tail = tail->getNext(); // Tail will be moved to the newly added Node.
}
template <typename T>
T List<T>::deleteFromHead()
{
	if (isEmpty())
	{
		return 0;
	}
	Node<T>* temp = head->getNext();// A temporary pointer getting address from the next pointer of an object currently pointed by head.
	T a = head->getData();		// Getting Data of an object currently pointed by head.
	delete head;					// Deleting object pointed by head.
	head = temp;					// Head is receiving next object`s address using temporary pointer.
	temp = nullptr;					// Temporary pointer getting out of the race.
	if (head == nullptr)			// Checking if that was the only object in the list which we have deleted.
	{								// If yes, removing that memory`s address from tail.
		tail = nullptr;
	}
	return a;
}
template <typename T>
T List<T>::deleteFromTail()
{
	if (isEmpty())
	{
		return 0;
	}
	T a = tail->getData();		//Getting Data present at Tail
	Node<T>* temp = head;			//Starting a temporary pointer from start of the list.
	while (temp->getNext() != tail) //Iterating until one before tail. Here, temp->getNext() will be pointing to the tail at the end.
	{
		temp = temp->getNext();
	}
	delete tail;					//Object pointed by Tail be deleted here.
	tail = temp;					//Tail pointer receiving address of 2nd last object int the list which is now the last one.
	tail->setNext(nullptr);			//Setting next pointer of the last object to nullptr.
	temp = nullptr;
	return a;						//Returning deleted Object`s Data.
}
template <typename T>
void List<T>::displayList()
{
	if (isEmpty())
	{
		cout << "Empty!";
		return;
	}
	Node<T>* temp = head;				//Starting a temporary pointer from start of the list.
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
template <typename T>
bool List<T>::deleteNode(T element)
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
		for (Node<T>* temp = head; (temp != tail) && !status; temp = temp->getNext())
		{
			if (temp->getNext()->getData() == element)
			{
				Node<T>* p = temp->getNext();
				temp->setNext(p->getNext());
				delete p;
				p = nullptr;
				status = true;
			}
		}
	}
	return status;
}
template <typename T>
bool List<T>::isInList(T element)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return false;
	}
	for (Node<T>* temp = head; temp != nullptr; temp = temp->getNext())		//Starting a temporary pointer from start of the list.
	{																		//Iterating until the end of the list.
		if (temp->getData() == element)										//If element found, return statement will terminate the loop.
		{
			return true;
		}
	}
	return false;															//If whole list traversed without encountering the key, this return statement will be executed.
}
template <typename T>
List<T>::~List()
{
	if (isEmpty())
	{
		return;
	}
	for (Node<T>* temp = head; temp != nullptr;)//Starting a temporary pointer from start of the list.
	{											//Iterating until the end of the list.
		Node<T>* p = temp;						//Another Block level pointer will point to the object pointed by the pointer "temp".
		temp = temp->getNext();					//"temp" will move to the next object.
		delete p;								//Current object pointed by 'p' is being deleted.
	}
	head = nullptr;								//Both "Head" & "Tail" pointers receiving nullptr.
	tail = nullptr;
}