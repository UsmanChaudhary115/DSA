#ifndef CDLL_H
#define CDLL_H
#include"Node.h"
class CDLL
{
	Node* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
	int getLength()
	{
		Node* temp = head;
		int length = 1;
		while (temp != head->previous)
		{
			length++;
			temp = temp->next;
		}
		return length;
	}
	
	bool find(int target, Node* head, Node* last)
	{
		if (head == last)
		{
			return false;
		}
		else
		{
			Node* temp = head;
			while (temp != last)
			{
				if (target == ((head->data) + (temp->next->data)))
				{
					return true;
				}
				temp = temp->next;
			}
			head = head->next;
			return find(target, head, last);
		}
	}
public:
	CDLL(); // Constructor
	~CDLL(); //Destructor 
	CDLL (const CDLL &); //Copy Constructor 
	void insertAtHead(int); // Insert val at head
	void insertAtTail(int); //Insert val at tail
	void insertAfter(int, int); // insert val after first occurrence of key
	void insertBefore(int, int); // insert val before first occurrence of key 
	void removeAtHead(); // Remove Node at Head
	void removeAtTail(); // Remove Node at Tail 
	void removeAfter(int); // Remove the node after first occurrence of key 
	void removeBefore(int); //Remove node before first occurrence of key
	void remove(int); // Remove first occurrence of key
	void display();
	void rotateCircularDLL(int);
	bool targetSum(int);
	int removeEveryMthNodes(int);
	Node* getHead()
	{
		return head;
	}
	void setHead(Node* p)
	{
		head = p;
	}
};
#endif // !CDLL_H
