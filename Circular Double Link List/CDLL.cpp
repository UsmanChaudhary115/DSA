#include"CDLL.h"
CDLL::CDLL() :head(nullptr)
{}
CDLL::~CDLL()
{
	if (isEmpty())
	{
		return;
	}
	Node* temp = head;
	Node* temp2 = head->previous;
	while (temp != temp2)
	{
		Node* p = temp;
		temp = temp->next;
		delete p;
		p = nullptr; // Set p to nullptr after deletion
	}
	delete temp;
	temp = nullptr;
	head = nullptr;
}
CDLL::CDLL(const CDLL& ref)
{
	if (ref.head == nullptr)
	{
		return;
	}
	this->~CDLL();
	Node* temp = ref.head;
	while (temp != ref.head->previous)
	{
		insertAtTail(temp->data);
		temp = temp->next;
	}
	insertAtTail(temp->data);
}
void CDLL::insertAtHead(int val)
{
	if (isEmpty())
	{
		head = new Node(val);
		head->next = head;
		head->previous = head;
	}
	else
	{
		Node* temp = head->previous;
		head->previous = new Node(val, head, head->previous);
		head = head->previous;
		temp->next = head;
	}
}
void CDLL::insertAtTail(int val)
{
	if (isEmpty())
	{
		head = new Node(val);
		head->next = head;
		head->previous = head;
	}
	else
	{
		Node* temp = head->previous;
		head->previous = new Node(val, head, head->previous);
		temp->next = head->previous;
	}
}
void CDLL::insertAfter(int key, int val)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		Node* temp = head->next;
		head->next = new Node(val, temp, head);
		temp->previous = head->next;
		temp = nullptr;
	}
	else
	{
		bool status = true;
		for (Node* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node* p = temp->next;
				temp->next = new Node(val, p, temp);
				p->previous = temp->next;
				p = nullptr;
				status = false;
			}
		}
	}
}
void CDLL::insertBefore(int key, int val)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		Node* temp = head->previous;
		head->previous = new Node(val, head, temp);
		temp->next = head->previous;
		temp = nullptr;
	}
	else
	{
		bool status = true;
		for (Node* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node* p = temp->previous;
				temp->previous = new Node(val, temp, p);
				p->next = temp->previous;
				p = nullptr;
				status = false;
			}
		}
	}
}
void CDLL::removeAtHead()
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
			Node* temp = head->previous;
			head = head->next;
			delete head->previous;
			temp->next = head;
			head->previous = temp;
			temp = nullptr;
		}
	}
}
void CDLL::removeAtTail()
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
			Node* temp = head->previous;
			head->previous = temp->previous;
			temp->previous->next = head;
			delete temp;
			temp = nullptr;
		}
	}
}
void CDLL::removeAfter(int key)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		if (!(head->next == head))
		{
			Node* temp = head->next;
			head->next = head->next->next;
			temp->next->previous = head;
			delete temp;
			temp = nullptr;
		}
	}
	else
	{
		bool status = true;
		for (Node* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node* p = temp->next;
				temp->next = temp->next->next;
				p->next->previous = temp;
				delete p;
				p = nullptr;
				status = false;
			}
		}
	}
}
void CDLL::removeBefore(int key)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else if (head->data == key)
	{
		if (!(head->previous == head))
		{
			Node* temp = head->previous;
			head->previous = head->previous->previous;
			temp->previous->next = head;
			delete temp;
			temp = nullptr;
		}
	}
	else
	{
		bool status = true;
		for (Node* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node* p = temp->previous;
				temp->previous = temp->previous->previous;
				p->previous->next = temp;
				delete p;
				p = nullptr;
				status = false;
			}
		}
	}
}
void CDLL::remove(int key)
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
		Node* temp = head;
		head->previous->next = head->next;
		head->next->previous = head->previous;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	else
	{
		bool status = true;
		for (Node* temp = head->next; temp != head && status; temp = temp->next)
		{
			if (temp->data == key)
			{
				Node* p = temp;
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				delete p;
				p = nullptr;
				status = false;
			}
		}
	}
}
void CDLL::display()
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		Node* temp = head;
		while (temp != head->previous)
		{
			cout << temp->data;
			cout << " <-> ";
			temp = temp->next;
		}
		cout << head->previous->data;
	}
}
void CDLL::rotateCircularDLL(int times)
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		int length = getLength();
		times = times % length; // Agar size time se chota hay to pori list ko br br nh ghumana blk size k hisab se time ko adjust kr lena hai
		while (times)
		{
			head = head->previous;
			times--;
		}
	}
}
bool CDLL::targetSum(int target)
{
	return find(target, head, head->previous);
}
int CDLL::removeEveryMthNodes(int m)
{
	if (m > 0)
	{
		while (head->next != head)
		{
			for (int i = 1;i < m;i++)
			{
				head = head->next;
			}
			Node* p = head;
			head->previous->next = head->next;
			head->next->previous = head->previous;
			head = head->next;
			delete p;
			p = nullptr;
		}
		int data = head->data;
		return data;
	}
	exit(0);
}