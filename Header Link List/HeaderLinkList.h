#ifndef HEADERLINKLIST_H
#define HEADERLINKLIST_H
#include"SpecialNode.h"
#include<iostream>
using namespace std;
class HeaderLinkList
{
	SpecialNode start;
	void resetMetaData()
	{
		if (start.next != nullptr)
		{
			Node* temp = start.next;
			start.minData = temp->getData();
			start.maxData = temp->getData();
			temp = temp->getNext();
			while (temp != nullptr)
			{
				if (start.maxData < temp->getData())
				{
					start.maxData = temp->getData();
					temp = temp->getNext();
				}
				else if (start.minData > temp->getData())
				{
					start.minData = temp->getData();
					temp = temp->getNext();
				}
				else
				{
					temp = temp->getNext();
				}
			}
			temp = nullptr;
		}
		else
		{
			start.maxData = 0;
			start.minData = 0;
			start.size = 0;
		}
	}
public:
	HeaderLinkList();
	void insert(int);
	void remove();
	void removeLinkByValue(int);
	void removeLinkByIndex(int);
	void updateLink(int,int);
	bool isInList(int);
	//bool findLinkByCondition();
	void displayAllLinks();
	//void sortLinks();
	void clearLinks();
	int countLinks();
	~HeaderLinkList();
	/*int* p = new int(5);
	int* q = p;*/
};
#endif // !HEADERLINKLIST_H
