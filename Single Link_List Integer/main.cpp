#include"List.h"
Node* reverseList(Node* head)
{
	List temp;
	while (head != nullptr)
	{
		temp.addToHead(head->getData());
		head = head->getNext();
	}
	cout << temp;
	return temp.getHead();
}
List convertArrayToList(int* arr,int size)
{
	List l;
	for (int i = 0;i < size;i++)
	{
		l.addToTail(arr[i]);
	}
	return l;
}
bool isPalindrom(List list) 
{
	if (!list.isEmpty() && (list.getHead()->getNext() != nullptr))
	{
		bool status = true;
		List temp;
		Node* temp1 = list.getHead();
		Node* temp2 = list.getHead();
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
			if (temp.getHead()->getData() != temp1->getData())
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
void zigzag(Node* head)
{
	if (head != nullptr)
	{
		bool isGreaterStatus = true;
		for (Node* temp = head->getNext();temp != nullptr;temp = temp->getNext())
		{
			if (isGreaterStatus)
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
int main()
{
	int arr[13] = { rand()%20,rand() % 20 ,rand() % 20 ,rand() % 20 ,rand() % 20 };
	List l = convertArrayToList(arr,5);
	cout << l << endl;

	//l.deleteMinimum();
	//l.deleteNode(1);
	l.descendingSort();
	cout << l;
	
	return 0;
}