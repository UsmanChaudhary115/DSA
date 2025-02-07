#include<iostream>
using namespace std;
#include"CDLL.h"
int main()
{
	CDLL<int> list;
	list.insertAtHead(1);
	list.insertAtHead(2);
	list.insertAtTail(3);
	list.insertAtHead(4);
	list.insertAtHead(5);
	list.display();
	cout << endl << list.targetSum(10);
	return 0;
}