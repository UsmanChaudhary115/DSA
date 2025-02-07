#ifndef CDLL_H
#define CDLL_H
#include"Node.h"
template<typename T>
class CDLL
{
	Node<T>* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
	int getLength()
	{
		Node<T>* temp = head;
		int length = 1;
		while (temp != head->previous)
		{
			length++;
			temp = temp->next;
		}
		return length;
	}
	bool find(int target, Node<T>* head, Node<T>* last)
	{
		if (head == last)
		{
			return false;
		}
		else
		{
			Node<T>* temp = head;
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
	CDLL<T>(const CDLL<T>& ref); //Copy Constructor 
	void insertAtHead (T val); // Insert val at head
	void insertAtTail(T val); //Insert val at tail
	void insertAfter(T key, T val); // insert val after first occurrence of key
	void insertBefore(T key, T val); // insert val before first occurrence of key 
	void removeAtHead(); // Remove Node at Head
	void removeAtTail(); // Remove Node at Tail 
	void removeAfter(T key); // Remove the node after first occurrence of key 
	void removeBefore(T key); //Remove node before first occurrence of key
	void remove(T key); // Remove first occurrence of key (3) void display();
	void display();


	//////// TASK 2 /////////
	void rotateCircularDLL(int);
	//////// TASK 3 /////////
	bool targetSum(int);
};
#endif // !CDLL_H
