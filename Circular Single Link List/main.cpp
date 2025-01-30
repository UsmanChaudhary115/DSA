#include"CSLL.h"
#include<iostream>
using namespace std;
int main()
{
	CSLL list;
	list.addToHead(10);
	list.addToTail(20);
	list.addToHead(10);
	list.displayList();
	list.deleteNode(10);
	list.displayList();
	return 0;
}
