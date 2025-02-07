#include<iostream>
using namespace std;
#include"CDLL.h"
int removeEveryMthNodes(CDLL& list,int m)
{
	if (m > 0)
	{
		while (list.getHead()->next != list.getHead())
		{
			for (int i = 1;i < m;i++)
			{
				list.setHead(list.getHead()->next);
			}
			Node* p = list.getHead();
			list.getHead()->previous->next = list.getHead()->next;
			list.getHead()->next->previous = list.getHead()->previous;
			list.setHead(list.getHead()->next);
			delete p;
			p = nullptr;
		}
		int data = list.getHead()->data;
		return data;
	}
	exit(0);
}
int main()
{
	CDLL list;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.insertAtTail(6);
	list.insertAtTail(7);
	list.display();
	cout << endl;
	cout << removeEveryMthNodes(list, 3);
	return 0;
}