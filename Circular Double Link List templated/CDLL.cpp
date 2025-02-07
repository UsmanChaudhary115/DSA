#include"CDLL.h"
template<typename T>
CDLL<T>::CDLL():head(nullptr)
{}
template<typename T>
CDLL<T>::~CDLL() 
{
	if (isEmpty())
	{
		return;
	}
	Node<T>* temp = head;
	Node<T>* temp2 = head->previous;
	while (temp != temp2)
	{
		Node<T>* p = temp;
		temp = temp->next;
		delete p;
		p = nullptr; // Set p to nullptr after deletion
	}
	delete temp;
	temp = nullptr;
	head = nullptr;
}
template<typename T>
CDLL<T>::CDLL<T>(const CDLL<T>& ref)
{
	if (ref.head == nullptr)
	{
		return;
	}
	this->~CDLL();
	Node<T>* temp = ref.head;
	while (temp != ref.head->previous)
	{
		insertAtTail(temp->data);
		temp = temp->next;
	}
	insertAtTail(temp->data);
}
template<typename T>
void CDLL<T>::insertAtHead(T val)
{
	if (isEmpty())
	{
		head = new Node<T>(val);
		head->next = head;
		head->previous = head;
	}
	else
	{
		Node<T>* temp = head->previous;
		head->previous = new Node<T>(val, head, head->previous);
		head = head->previous;
		temp->next = head;
	}
}
template<typename T>
void CDLL<T>::insertAtTail(T val)
{
	if (isEmpty())
	{
		head = new Node<T>(val);
		head->next = head;
		head->previous = head;
	}
	else
	{
		Node<T>* temp = head->previous;
		head->previous = new Node<T>(val, head, head->previous);
		temp->next = head->previous;
	}
}
template<typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		Node<T>* temp = head->next;
		head->next = new Node<T>(val, temp, head);
		temp->previous = head->next;
		temp = nullptr;
	}
	else
	{
		bool status = true;
		for (Node<T>* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node<T>* p = temp->next;
				temp->next = new Node<T>(val, p, temp);
				p->previous = temp->next;
				p = nullptr;
				status = false;
			}
		}
	}
}
template<typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		Node<T>* temp = head->previous;
		head->previous = new Node<T>(val, head, temp);
		temp->next = head->previous;
		temp = nullptr;
	}
	else
	{
		bool status = true;
		for (Node<T>* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node<T>* p = temp->previous;
				temp->previous = new Node<T>(val, temp, p);
				p->next = temp->previous;
				p = nullptr;
				status = false;
			}
		}
	}
}
template<typename T>
void CDLL<T>::removeAtHead()
{
	if (isEmpty())
	{
		cout << "Already Empty!" << endl;
	}
	else
	{
		if (head->next == head)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T>* temp = head->previous;
			head = head->next;
			delete head->previous;
			temp->next = head;
			head->previous = temp;
			temp = nullptr;
		}
	}
}
template<typename T>
void CDLL<T>::removeAtTail()
{
	if (isEmpty())
	{
		cout << "Already Empty!" << endl;
	}
	else
	{
		if (head->previous == head)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T>* temp = head->previous;
			head->previous = temp->previous;
			temp->previous->next = head;
			delete temp;
			temp = nullptr;
		}
	}
}
template<typename T>
void CDLL<T>::removeAfter(T key)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		if (!(head->next == head))		//this condition will only be true if there are two or more blocks present
		{
			Node<T>* temp = head->next;
			head->next = head->next->next;
			temp->next->previous = head;
			delete temp;
			temp = nullptr;
		}
	}
	else
	{
		bool status = true;
		for (Node<T>* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node<T>* p = temp->next;
				temp->next = temp->next->next;
				p->next->previous = temp;
				delete p;
				p = nullptr;
				status = false;
			}
		}
	}
}
template<typename T>
void CDLL<T>::removeBefore(T key)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		if (!(head->previous == head))		//this condition will only be true if there are two or more blocks present
		{
			Node<T>* temp = head->previous;
			head->previous = head->previous->previous;
			temp->previous->next = head;
			delete temp;
			temp = nullptr;
		}
	}
	else
	{
		bool status = true;
		for (Node<T>* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node<T>* p = temp->previous;
				temp->previous = temp->previous->previous;
				p->previous->next = temp;
				delete p;
				p = nullptr;
				status = false;
			}
		}
	}
}
template<typename T>
void CDLL<T>::remove(T key)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		if (head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* temp = head;
		head->previous->next = head->next;
		head->next->previous = head->previous;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	else
	{
		bool status = true;
		for (Node<T>* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node<T>* p = temp;
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				delete p;
				p = nullptr;
				status = false;
			}
		}
	}
}
template<typename T>
void CDLL<T>::display()
{

	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		Node<T>* temp = head;
		while (temp != head->previous)
		{
			cout << temp->data;
			cout << "<->";
			temp = temp->next;
		}
		cout << head->previous->data;
	}
}
template<typename T>
void CDLL<T>::rotateCircularDLL(int times)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		int length = getLength();
		times = times % length;
		while (times)
		{
			head = head->previous;
			times--;
		}
	}
}
template<typename T>
bool CDLL<T>::targetSum(int target)
{
	return find(target, head, head->previous);
}
