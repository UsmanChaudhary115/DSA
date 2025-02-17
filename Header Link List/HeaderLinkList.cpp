#include"HeaderLinkList.h"
HeaderLinkList::HeaderLinkList() :start()
{}
void HeaderLinkList::insert(int val)
{
	if (start.next != nullptr)
	{
		Node* temp = start.next;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(new Node(val));
		start.size++;
		resetMetaData();
	}
	else
	{
		start.next = new Node(val);
		start.maxData = val;
		start.minData = val;
		start.size = 1;
	}
}
void HeaderLinkList::remove()
{
	if (start.next != nullptr)
	{
		Node* temp = start.next;
		if (temp->getNext() == nullptr)
		{
			delete temp;
			temp = nullptr;
			start.next = nullptr;
			resetMetaData();
		}
		else
		{
			while (temp->getNext()->getNext() != nullptr)
			{
				temp = temp->getNext();
			}
			delete temp->getNext();
			temp->setNext(nullptr);
			temp = nullptr;
			start.size--;
			resetMetaData();
		}
	}
}
void HeaderLinkList::removeLinkByValue(int val)
{
	if (start.next != nullptr)
	{
		Node* temp = start.next;
		bool status = false;
		if (temp->getData() == val)
		{
			start.next = temp->getNext();
			delete temp;
			temp = nullptr;
			start.size--;
		}
		else
		{
			while (temp->getNext() != nullptr && !status)
			{
				if (temp->getNext()->getData() == val)
				{
					Node* p = temp->getNext();
					temp->setNext(p->getNext());
					delete p;
					start.size--;
					status = true;
				}
				else
				{
					temp = temp->getNext();
				}
			}
		}
		resetMetaData();
	}
	else
	{
		cout << "List is Empty!" << endl;
	}
}
void HeaderLinkList::removeLinkByIndex(int index)
{
	if (start.next != nullptr && index > 0 && index <= start.size)
	{
		int i = 1;
		Node* temp = start.next;
		if (i == index)
		{
			start.next = temp->getNext();
			delete temp;
			temp = nullptr;
			start.size--;
		}
		else
		{
			while (i < (index - 1))
			{
				i++;
				temp = temp->getNext();
			}
			Node* p = temp->getNext();
			temp->setNext(p->getNext());
			delete p;
			p = nullptr;
			start.size--;
		}
		resetMetaData();
	}
}
void HeaderLinkList::updateLink(int index,int value)
{
	if (start.next != nullptr && index > 0 && index <= start.size)
	{
		Node* temp = start.next;
		for (int i = 1;i < index;i++)
		{
			temp = temp->getNext();
		}
		temp->setData(value);
		resetMetaData();
	}
}
bool HeaderLinkList::isInList(int value)
{
	if (start.next == nullptr)
	{
		cout << "List is Empty" << endl;
		return false;
	}
	bool status = false;
	for (Node* temp = start.next; temp != nullptr && !status; temp = temp->getNext())		
	{						
		if (temp->getData() == value)										
		{
			status = true;
		}
	}
	return status;
}
void HeaderLinkList::displayAllLinks()
{
	if (start.next != nullptr)
	{
		for (Node* temp = start.next;temp != nullptr;temp = temp->getNext())
		{
			cout << temp->getData();	
			if (temp->getNext() != nullptr)
			{							
				cout << " -> ";
			}
		}
		cout << endl;
		cout << "Size: " << start.size << endl;
		cout << "Minimum Value: " << start.minData << endl;
		cout << "Maximum Value: " << start.maxData << endl;
	}
	else
	{
		cout << "List is Empty!" << endl;
	}
}
void HeaderLinkList::clearLinks()
{
	this->~HeaderLinkList();
}
int HeaderLinkList::countLinks()
{
	return start.size;
}
HeaderLinkList::~HeaderLinkList()
{
	if (start.next != nullptr)
	{
		Node* temp = start.next;
		while (temp != nullptr)
		{
			Node* p = temp;
			temp = temp->getNext();
			delete p;
		}
		start.next = nullptr;
	}
	resetMetaData();
}